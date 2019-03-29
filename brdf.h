#ifndef BRDF_H_
#define BRDF_H_

#include <glm/glm.hpp>

class BRDF
{
public:

	BRDF ( void );

	BRDF ( glm::vec3 reflectance );

	virtual ~BRDF( void );

	glm::vec3 fr();

	glm::vec3  reflectance_;

};


#endif /* BRDF_H_ */
