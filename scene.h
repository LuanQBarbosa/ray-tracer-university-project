#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "primitive.h"
#include "sphere.h" 
#include "triangle.h"
#include "bvh.h"
#include "diffuse.h"
#include "perfect_reflector.h"
#include "smooth_dieletric.h"
#include "cook_torrance.h"

class Scene
{
public:

    Scene( void );

    ~Scene( void );

    bool intersect( const Ray &ray,
                    IntersectionRecord &intersection_record ) const;

    void load( void );

    void loadObj( const char* obj, glm::vec3 position, float size, Material material );

    void buildBVH( void );

    const BVH *bvh_ = nullptr;

    std::vector< Primitive::PrimitiveUniquePtr > primitives_;

};

#endif /* SCENE_H_ */

