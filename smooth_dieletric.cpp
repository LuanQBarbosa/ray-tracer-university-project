#include "smooth_dieletric.h"
#define PI 3.14159265358979323846f


SmoothDieletric::SmoothDieletric( glm::vec3 reflectance )
{
    reflectance_ = { reflectance };
    type = 2;
}

glm::vec3 SmoothDieletric::fr()
{
	return reflectance_/ PI;
}