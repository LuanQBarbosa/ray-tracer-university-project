#ifndef COOK_TORRANCE_H_
#define COOK_TORRANCE_H_

#include <glm/glm.hpp>
#include "brdf.h"

class CookTorrance : public BRDF
{
public:

	CookTorrance ( glm::vec3 reflectance );

	glm::vec3 fr();

};


#endif /* COOK_TORRANCE_H_ */
