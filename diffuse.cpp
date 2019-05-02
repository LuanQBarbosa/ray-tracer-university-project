#include "diffuse.h"
#define PI 3.14159265358979323846f

Diffuse::Diffuse( glm::vec3 reflectance )		
{
    reflectance_ = { reflectance };
    type = 0;
}

glm::vec3 Diffuse::fr()
{
	return reflectance_/ PI;
}

