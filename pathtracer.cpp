#include "pathtracer.h"

#include <random>
#include <functional>
#include <chrono>

PathTracer::PathTracer( Camera &camera,
                      const Scene &scene,
                      const glm::vec3 background_color,
                      Buffer &buffer ) :
        camera_( camera ),
        scene_( scene ),
        background_color_{ background_color },
        buffer_( buffer )
{}

std::uniform_real_distribution<float> dist(0.0f, 1.0f);
auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);

void PathTracer::integrate( void )
{
    // Image space origin (i.e. x = 0 and y = 0) at the top left corner.

    // Loops over image rows
    int nsamples = 1000;

    // #pragma omp parallel for schedule( dynamic, 1 )    
    for ( std::size_t y = 0; y < buffer_.v_resolution_; y++ )
    {
        std::stringstream progress_stream;
        progress_stream << "\r  progress .........................: "
                        << std::fixed << std::setw( 6 )
                        << std::setprecision( 2 )
                        << 100.0 * y / ( buffer_.v_resolution_ - 1 )
                        << "%";

        std::clog << progress_stream.str();

        // Loops over image columns
        for ( std::size_t x = 0; x < buffer_.h_resolution_; x++ )
        {

            for ( int samples = 0; samples < nsamples; ++samples )
            {
                float r1 = dist(rng);
                while (r1 == 1.0f)
                    r1 = dist(rng);

                float r2 = dist(rng);
                while (r2 == 1.0f)
                    r2 = dist(rng);

                Ray ray{ camera_.getWorldSpaceRay( glm::vec2{ x + r1, y + r2 } ) };

                buffer_.buffer_data_[x][y] += L(ray, 0);
            }

            buffer_.buffer_data_[x][y] /= nsamples;

        }
    }
    
    std::clog << std::endl;
}

glm::vec3 PathTracer::L( Ray &ray, int curr_depth )
{
    IntersectionRecord intersection_record;
	intersection_record.t_ = std::numeric_limits<double>::max();

    glm::vec3 Lo( 0, 0, 0 );
    Ray new_ray;

    float dot;
    float vFresnel;
    float random;
    float cosX;

    if (curr_depth < 15) {
        if (scene_.intersect(ray, intersection_record)) {

            switch (intersection_record.material_.brdf_->type) {
                
                case 0:     // diffuse

                    new_ray = get_new_ray(intersection_record);

                    dot = glm::dot(new_ray.direction_, intersection_record.normal_);            
                    if (dot < 0) {
                        new_ray.direction_ *= -1;
                        dot = -dot;
                    }

                    Lo = intersection_record.material_.emission_ + 2.0f * ((float)M_PI) * intersection_record.material_.brdf_->fr() * L(new_ray, ++curr_depth) * dot;
                    break;

                case 1:     // perfect_reflector

                    new_ray = get_reflected_ray(ray,intersection_record);
                    Lo = L(new_ray, ++curr_depth);
                    break;

                case 2:     // smooth_dieletric

                    cosX = glm::dot(ray.direction_, intersection_record.normal_);
                    random = dist(rng);
                    float n1, n2;

                    if(cosX < 0.0f) {    // Entering
                        n1 = 1.0f;
                        n2 = 1.5f;
                    } else {             // Getting out
                        n1 = 1.5f;
                        n2 = 1.0f;
                        intersection_record.normal_ = - intersection_record.normal_;
                    }

                    glm::vec3 new_direction;

                    vFresnel = fresnel(ray, intersection_record, n1, n2);
                    if(random < vFresnel)
                        new_direction = get_reflected_ray(ray, intersection_record).direction_;
                    else
                        new_direction = get_refracted_direction(ray, intersection_record, n1, n2);

                    new_ray = {intersection_record.position_ + 0.001f * new_direction, new_direction};

                    Lo = L(new_ray, ++curr_depth);
                    break;

                case 3:     // cook_torrance

                    //roughness factor

                    float m = 0.5f;

                    //Importance sampling

                    ONB tangent_frame;
                    tangent_frame.setFromV( intersection_record.normal_ );

                    glm::dmat3x3 tangent_to_universe_space = tangent_frame.getBasisMatrix();
                    glm::dmat3x3 universe_to_tangent_space = glm::transpose( tangent_to_universe_space );

                    glm::dvec3 w_i = universe_to_tangent_space * -ray.direction_;

                    float r1 = dist(rng);

                    float r2 = dist(rng);

                    float phi = 2.0f * M_PI * r2;

                    float theta = glm::atan(glm::sqrt( -(m * m) * glm::log(1 - r1)));

                    glm::dvec3 p = {glm::cos(phi) * glm::sin(theta), glm::cos(theta), glm::sin(phi) *  glm::sin(theta)};

                    glm::dvec3 w_r = 2.0 * p * glm::dot( p, w_i ) - w_i;

                    glm::dvec3 new_dir = tangent_to_universe_space * w_r;


                    new_ray = { (glm::dvec3) intersection_record.position_ + new_dir * 0.00001, new_dir };


                    glm::dvec3 h = glm::normalize( w_i + w_r );
                    double nh = std::abs( h.y );
                    double nv = std::abs( w_i.y );
                    double nl = std::abs( w_r.y );
                    double vh = std::abs( glm::dot( w_i, h ) );
                    double lh = std::abs( glm::dot( w_r, h ) );

                    // Beckmann normal distribution function
                    double nh_2 = nh * nh;
                    double m_2 = m * m;
                    double d1 = 1.0 / ( M_PI * m_2 * nh_2 * nh_2 );
                    double d2 = ( nh_2 - 1.0 ) / ( m_2 * nh_2 );
                    double d = d1 * exp( d2 );

                    // Cook-Torrance geometric attenuation
                    double g1 = 2.0 * nh / vh;
                    double g = std::min( 1.0, std::min( g1 * nv, g1 * nl ) );

                    // Fresnel term
                    glm::dvec3 r0 = intersection_record.material_.brdf_->fr();
                    const double x = 1.0f - lh;
                    glm::dvec3 F = r0 + ( 1.0 - r0 ) * x * x * x * x * x;

                    glm::dvec3 rough_specular_term = ( F * d * g ) / ( 4.0 * nv * nl );

                    //PDF
                    double om = glm::dot( w_r, h );
                    double a = ( d1 * exp( d2 ) * nh ) / ( 4.0 * ( om ) );

                    //Cook-torrance
                    glm::vec3 ct = 1.0 / a  * rough_specular_term;

                    if ( w_r.y < 0.0 )
                        ct = glm::vec3{ 0.0, 0.0, 0.0 };


                    Lo = intersection_record.material_.emission_ +
                        ct * L(new_ray, ++curr_depth) *
                        glm::dot(intersection_record.normal_,
                        new_ray.direction_);
            }
        }
    }
    
    return Lo;
}

Ray PathTracer::get_new_ray( IntersectionRecord intersection_record )
{
    float r1 = dist(rng);
    while (r1 == 1.0f)
        r1 = dist(rng);

    float r2 = dist(rng);
    while (r2 == 1.0f)
        r2 = dist(rng);

    float theta = acos(1 - r1);
    float phi = 2 * ((float)M_PI) * r2;
    float radius = 1;

    float x = radius * sin(theta) * cos(phi);
    float y = radius * sin(theta) * sin(phi);
    float z = radius * cos(theta);

    glm::vec3 dir(x, y, z);
    ONB onb;
    onb.setFromV(intersection_record.normal_);
    dir = glm::normalize(dir * onb.getBasisMatrix());

    Ray new_ray(intersection_record.position_, dir);    

    return new_ray;
}

Ray PathTracer::get_reflected_ray(Ray ray, IntersectionRecord &intersection_record)
{
    ONB onb_;
    Ray refl_ray;

    onb_.setFromV(intersection_record.normal_);    

    glm::vec3 dir = glm::transpose(onb_.getBasisMatrix()) * ray.direction_;
    dir = { dir.x, -dir.y, dir.z };

    refl_ray = { intersection_record.position_ + (intersection_record.normal_*0.001f), onb_.getBasisMatrix() * dir };
    return refl_ray;
}

glm::vec3 PathTracer::get_refracted_direction(Ray ray, IntersectionRecord &intersection_record, float n1, float n2)
{
    float n = n1 / n2;
    float cos1 = -glm::dot(intersection_record.normal_, ray.direction_);
    float cos2 = 1.0 - n * n * (1.0f - cos1 * cos1);    
    cos2 = sqrt(cos2);

    return n * ray.direction_ + (n * cos1 - cos2) * intersection_record.normal_;
}

float PathTracer::fresnel(Ray ray, IntersectionRecord &intersection_record, float n1, float n2)
{
    float Ro = (n1 - n2)/(n1 + n2);
    Ro *= Ro;
    float cos1 = -glm::dot(intersection_record.normal_, ray.direction_);

    if(n1 > n2){
        float n = n1 / n2;
        float cos2 = 1.0f - n * n * (1.0f - cos1 * cos1);

        if(cos2 < 0.0f)     // TIR
            return 1.0f;

        cos1 = sqrt(cos2);
    }

    float x = 1.0f - cos1;
    return Ro + (1.0f - Ro)* x * x * x * x * x;
}
