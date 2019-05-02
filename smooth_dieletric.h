#ifndef SMOOTH_DIELETRIC_H_
#define SMOOTH_DIELETRIC_H_


#include <glm/glm.hpp>
#include "brdf.h"

class SmoothDieletric : public BRDF
{
public:

    SmoothDieletric( glm::vec3 reflectance );

    glm::vec3 fr();

};
#endif //SMOOTH_DIELETRIC_H_