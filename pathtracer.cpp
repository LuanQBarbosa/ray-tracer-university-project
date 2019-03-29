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
    int nsamples = 40;
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

    if (curr_depth < 5) {
        if (scene_.intersect(ray, intersection_record)) {

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

            Ray refl_ray(intersection_record.position_, dir);
            float dot = glm::dot(refl_ray.direction_, intersection_record.normal_);

            if (dot < 0) {
                refl_ray.direction_ *= -1;
                dot = -dot;
            }

            Lo = intersection_record.material_.emission_ + 2.0f * ((float)M_PI) * intersection_record.material_.brdf_.fr() * L(refl_ray, ++curr_depth) * dot;
        }
    }
    
    return Lo;
}

