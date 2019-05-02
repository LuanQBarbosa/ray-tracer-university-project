#ifndef PERFECT_REFLECTOR_H_
#define PERFECT_REFLECTOR_H_


#include <glm/glm.hpp>
#include "brdf.h"

class PerfectReflector : public BRDF
{
public:

    PerfectReflector( glm::vec3 reflectance );

    glm::vec3 fr();

};
#endif //PERFECT_REFLECTOR_H_