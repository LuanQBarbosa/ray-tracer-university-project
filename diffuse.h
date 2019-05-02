#ifndef DIFFUSE_H_
#define DIFFUSE_H_

#include <glm/glm.hpp>
#include "brdf.h"

class Diffuse : public BRDF
{
public:

	Diffuse ( glm::vec3 reflectance );

	glm::vec3 fr();

};


#endif /* DIFFUSE_H_ */
