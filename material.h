#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <glm/glm.hpp>
#include "brdf.h"

class Material
{
public:

	Material( void );

	Material( BRDF* brdf, glm::vec3 emission);

	glm::vec3 emission_;

	BRDF* brdf_;

};





#endif /* MATERIAL_H_ */
