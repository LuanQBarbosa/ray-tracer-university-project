#include "brdf.h"

BRDF::BRDF( void )
{}

BRDF::BRDF( glm::vec3 reflectance ):
		reflectance_{ reflectance }
{}

BRDF::~BRDF( void )
{}

glm::vec3 BRDF::fr()
{
	float pi = 3.14159265358979323846;

	return reflectance_/ pi;
}

