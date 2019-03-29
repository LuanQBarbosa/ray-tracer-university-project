#include "material.h"

Material::Material ( void )
{}

Material::Material ( BRDF brdf, glm::vec3 emission )
{
	brdf_ = brdf;
	emission_ = emission;
}


