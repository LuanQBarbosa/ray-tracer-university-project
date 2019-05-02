#ifndef BRDF_H_
#define BRDF_H_

#include <glm/glm.hpp>

class BRDF
{
public:

	BRDF ( void );

	BRDF ( glm::vec3 reflectance );

	virtual ~BRDF( void );

	virtual glm::vec3 fr() = 0;

	glm::vec3  reflectance_;

	int type;

};


#endif /* BRDF_H_ */
