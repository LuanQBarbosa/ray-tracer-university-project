#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <glm/glm.hpp>
#include "primitive.h"
#include "intersection_record.h"
#include "ray.h"
#include "material.h"

class Triangle : public Primitive
{

	glm::vec3 vertex[3];

public:

	Triangle( void );

	Triangle( const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec3 &v3, Material material );

	bool intersect( const Ray &ray,
			IntersectionRecord &intersection_record ) const;

};


#endif /* TRIANGLE_H_ */
