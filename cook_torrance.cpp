#include "cook_torrance.h"

CookTorrance::CookTorrance( glm::vec3 reflectance )		
{
    reflectance_ = { reflectance };
    type = 3;
}

glm::vec3 CookTorrance::fr()
{
	return reflectance_;
}

