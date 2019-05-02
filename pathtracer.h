#ifndef PATHTRACER_H_
#define PATHTRACER_H_

#include <sstream>
#include <iomanip>
#include <cmath>
#include <omp.h>

#include "camera.h"
#include "scene.h"
#include "buffer.h"

class PathTracer
{
public:

    PathTracer( Camera &camera,
               const Scene &scene,
               const glm::vec3 background_color,
               Buffer &buffer );

    void integrate( void );

    glm::vec3 L( Ray &ray, int curr_depth );

    Ray get_new_ray( IntersectionRecord intersection_record );

    Ray get_reflected_ray( Ray ray, IntersectionRecord &intersection_record );

    glm::vec3 get_refracted_direction(Ray ray, IntersectionRecord &intersection_record, float n1, float n2);

    float fresnel(Ray ray, IntersectionRecord &intersection_record, float n1, float n2);

private:

    const Camera &camera_;

    const Scene &scene_;

    glm::dvec3 background_color_;

    Buffer &buffer_;

};

#endif /* PATHTRACER_H_ */

