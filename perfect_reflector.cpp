#include "perfect_reflector.h"
#define PI 3.14159265358979323846f


PerfectReflector::PerfectReflector( glm::vec3 reflectance )
{
    reflectance_ = { reflectance };
    type = 1;
}

glm::vec3 PerfectReflector::fr()
{
	return reflectance_/ PI;
}