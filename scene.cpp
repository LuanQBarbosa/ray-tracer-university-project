#include "scene.h"

Scene::Scene( void )
{}

Scene::~Scene( void )
{}

bool Scene::intersect( const Ray &ray,
                       IntersectionRecord &intersection_record ) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;
    std::size_t num_primitives = primitives_.size();

    // Loops over the list of primitives, testing the intersection of each primitive against the given ray 
    for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
        if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
            if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
            {
                intersection_record = tmp_intersection_record;
                intersection_record.color_ = primitives_[primitive_id]->color_;
                intersection_result = true; // the ray intersects a primitive!
            }

    return intersection_result;
}

void Scene::load( void )
{
//    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.0f,  0.0f }, 0.2f } ) );
//    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.0f, -1.0f }, 0.2f } ) );
//    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f,-0.5f, -2.0f }, 0.2f } ) );
//    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.5f, -3.0f }, 0.2f } ) );

//    for (int i = 0; i < 10000; ++i)
//    	primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.25f + (2.0f*i), 0.5f, -1.0f), glm::vec3(0.5f, 0, 0), glm::vec3(0, 0, 0))));

//	  primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.25f, 0.5f, -1.0f), glm::vec3(0.5f, 0, 0), glm::vec3(0, 0, 0))));
//    primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(-0.25f, 0.5f, -1.0f), glm::vec3(-0.5f, 0, 0), glm::vec3(0, 0, 0))));
//    primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(-0.25f, -0.5f, -1.0f), glm::vec3(-0.5f, 0, 0), glm::vec3(0, 0, 0))));
//    primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.25f, -0.5f, -1.0f), glm::vec3(0.5f, 0, 0), glm::vec3(0, 0, 0))));

//    Zelda's Triforce!
//	  primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(-0.5f, 0.0f, 0.0f))));
//	  primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.5f, 0.0f, 0.0f), glm::vec3(-0.5f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f))));
//	  primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.5f, 0.0f, 0.0f))));

	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile("/home/ryuugami/Documents/Programming/eclipse-workspace/RT-Template-master/models/pig.obj",
											  aiProcess_CalcTangentSpace |
											  aiProcess_Triangulate |
											  aiProcess_JoinIdenticalVertices |
											  aiProcess_SortByPType);

	for (unsigned int j = 0; j < scene->mNumMeshes; j++) {
		auto mesh = scene->mMeshes[j];

		for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
			auto face = mesh->mFaces[i];

			auto v1 = mesh->mVertices[face.mIndices[0]];
			auto v2 = mesh->mVertices[face.mIndices[1]];
			auto v3 = mesh->mVertices[face.mIndices[2]];

			float r, g, b;
			r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

			Triangle *triangle = new Triangle(glm::vec3(v1.x, v1.y, v1.z),
											 glm::vec3(v2.x, v2.y, v2.z),
											 glm::vec3(v3.x, v3.y, v3.z));

			triangle->color_ = glm::vec3(r, g, b);
			primitives_.push_back( Primitive::PrimitiveUniquePtr(triangle));
		}
	}

}

