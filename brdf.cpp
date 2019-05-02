#include "brdf.h"

BRDF::BRDF( void )
{}

BRDF::BRDF( glm::vec3 reflectance ):
		reflectance_{ reflectance }
{}

BRDF::~BRDF( void )
{}

