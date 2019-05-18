#include "scene.h"

Scene::Scene( void )
{}

Scene::~Scene( void )
{
	if ( bvh_ )
    {
        delete bvh_;
        bvh_ = nullptr;
    }
}

// bool Scene::intersect( const Ray &ray,
//                        IntersectionRecord &intersection_record ) const
// {
//     bool intersection_result = false;
//     IntersectionRecord tmp_intersection_record;
//     std::size_t num_primitives = primitives_.size();

//     // Loops over the list of primitives, testing the intersection of each primitive against the given ray 
//     for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
//         if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
//             if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
//             {
//                 intersection_record = tmp_intersection_record;
//                 intersection_result = true; // the ray intersects a primitive!
//             }

//     return intersection_result;
// }

bool Scene::intersect( const Ray &ray,
                       IntersectionRecord &intersection_record ) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;

    intersection_result = bvh_->intersect( ray, intersection_record);

    return intersection_result;
}

void Scene::buildBVH( void )
{
    bvh_ = new BVH( primitives_ );
	std::clog << std::endl;
}

void Scene::load( void )
{
	Material m1{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } };
	Material m2{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 0.0f } }, glm::vec3{ 40.0f, 40.0f, 40.0f } };
	Material m3{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 1.0f } }, glm::vec3{ 12.5f, 12.5f, 12.5f } };

	// Spheres
	// Sphere *s1 = new Sphere(glm::vec3(-1.5f, -1.0f, 1.0f), 0.75f, Material{ new SmoothDieletric{ glm::vec3{ 69.0f, 74.0f, 208.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });	
	// primitives_.push_back(Primitive::PrimitiveUniquePtr(s1));

    // Sphere *s2 = new Sphere(glm::vec3(0.0f, -1.0f, 0.0f), 0.75f, Material{ new CookTorrance{ glm::vec3{ 44.0f, 242.0f, 97.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s2));

    // Sphere *s3 = new Sphere(glm::vec3(1.5f, -1.0f, 1.0f), 0.75f, Material{ new PerfectReflector{ glm::vec3{ 15.0f, 210.0f, 8.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
	// primitives_.push_back(Primitive::PrimitiveUniquePtr(s3));

	// Sphere *s1 = new Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 1.0f, Material{ new SmoothDieletric{ glm::vec3{ 69.0f, 74.0f, 208.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });	
	// primitives_.push_back(Primitive::PrimitiveUniquePtr(s1));

	// Sphere *s2 = new Sphere(glm::vec3(0.0f, 0.0f, 0.0f), 0.99f, Material{ new Diffuse{ glm::vec3{ 255.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s2));

	// Lights    
    // Sphere *s4 = new Sphere(glm::vec3(-0.35f, 3.5f, 0.0f), 1.0f, m3);
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s4));

	Sphere *s4 = new Sphere(glm::vec3(-0.95f, 1.0f, 0.75f), 0.15f, m3);
    primitives_.push_back(Primitive::PrimitiveUniquePtr(s4));

    // Sphere *s5 = new Sphere(glm::vec3(0.0f, 4.0f, -0.75f), 1.5f, m3);
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s5));

    // Sphere *s6 = new Sphere(glm::vec3(0.0f, 4.0f, -2.5f), 1.5f, m3);
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s6));

    // Sphere *s7 = new Sphere(glm::vec3(0.0f, 4.0f, -4.25f), 1.5f, m3);
    // primitives_.push_back(Primitive::PrimitiveUniquePtr(s7));	

}

void Scene::loadObj( const char* obj, glm::vec3 position, float size, Material material )
{
	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile(obj,
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

			Triangle *triangle = new Triangle((glm::vec3(v1.x, v1.y, v1.z)) * size + position,
											 (glm::vec3(v2.x, v2.y, v2.z)) * size + position,
											 (glm::vec3(v3.x, v3.y, v3.z)) * size + position,
											 material);

			primitives_.push_back( Primitive::PrimitiveUniquePtr(triangle));
		}
	}
}

