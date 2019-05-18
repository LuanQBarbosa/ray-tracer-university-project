#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>
#include "main.h"

void load_final_scene(Scene* scene) {
    // room
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/room/walls(diffuse-dark-gray).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 100.0f, 100.0f, 100.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/room/floor(diffuse-light-gray).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 200.0f, 200.0f, 200.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // furniture
    scene->loadObj("//home/ryuugami/Desktop/Final Scene/final-preparation/furniture/counter(diffuse-brown).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 51.0f, 17.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("//home/ryuugami/Desktop/Final Scene/final-preparation/furniture/counter(smooth-dieletric).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new SmoothDieletric{ glm::vec3{ 144.0f, 81.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("//home/ryuugami/Desktop/Final Scene/final-preparation/furniture/cabinet(diffuse-brown).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 51.0f, 17.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("//home/ryuugami/Desktop/Final Scene/final-preparation/furniture/cabinet-doors(smooth-dieletric).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new SmoothDieletric{ glm::vec3{ 0.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/furniture/cabinet-lights.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 10.0f, 10.0f, 10.0f } });

    // weapons

    // //axe
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/axe/axe-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/axe/axe-handler(diffuse-brown).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 153.0f, 51.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/axe/axe-rings(cook-torrance-copper).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 184.0f, 115.0f, 51.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/axe/axe-top(cook-torrance-steel).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // gondor helmet
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/gondor-helmet/gondor-helmet(cook-torrance-steel).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/gondor-helmet/gondor-helmet-wings(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // hammer
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hammer/hammer-handler(diffuse-blue).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 230.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });   
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hammer/hammer-metal(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });   
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hammer/hammer-ring(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hammer/hammer-top(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // hylian shield
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hylian-shield/hylian-shield-body(diffuse-blue).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 230.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hylian-shield/hylian-shield-dec(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hylian-shield/hylian-shield-phoenix(diffuse-red).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 255.0f, 42.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/hylian-shield/hylian-shield-triforce(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // katana
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-handler1(diffuse-brown).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 153.0f, 51.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-handler2(diffuse-red).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 255.0f, 42.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-plate(diffuse-black).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-ring(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/katana/katana-stand(diffuse-brown).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 153.0f, 51.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // knife hand
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-hand/knife-hand-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-hand/knife-hand-handler(diffuse-black).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // knifes kuni
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-kuni/knifes-kuni(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // knife spear
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-spear/knife-spear-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-spear/knife-spear-gem(diffuse-green).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 204.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-spear/knife-spear-gem-out(smooth-dieletric).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new SmoothDieletric{ glm::vec3{ 0.0f, 0.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/knife-spear/knife-spear-hold(diffuse-yellow).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 204.0f, 170.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // kunai
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/kunai/kunai-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/kunai/kunai-handler(diffuse-red).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 255.0f, 42.0f, 0.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // simple helmet
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/simple-helmet/simple-helmet(cook-torrance-steel).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    // // simple knife
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/simple-knife/simple-knife-blade(perfect-reflector).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 192.0f, 192.0f, 196.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene->loadObj("/home/ryuugami/Desktop/Final Scene/final-preparation/weapons/simple-knife/simple-knife-handler(cook-torrance-gold).obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 212.0f, 175.0f, 55.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

}

std::string calculate_time(long seconds)
{
    long minutes_final=0, seconds_final=0, hours_final=0;
    if(seconds >= 60) {
        minutes_final = seconds/60;
        seconds_final = seconds - minutes_final*60;
    } else {
        seconds_final = seconds;
    }

    if(minutes_final >= 60) {
        hours_final = minutes_final/60;
        minutes_final = minutes_final - hours_final*60;
    }

    return std::to_string(hours_final) + " horas " + std::to_string(minutes_final) + " minutos " + std::to_string(seconds_final) + " segundos";
}

int main( void )
{
    // unsigned int x_resolution = 512;
    // unsigned int y_resolution = 512;

    unsigned int x_resolution = 1280;
    unsigned int y_resolution = 720;

//    OrthographicCamera camera{ -1.25f,
//                                1.25f,
//                               -1.25f,
//                                1.25f,
//								  5.0f,
//                                glm::ivec2{ x_resolution, y_resolution },
//                                glm::vec3{ 0.0f, 0.0f,  1.0f },     // position
//                                glm::vec3{ 0.0f, 1.0f,  0.0f },     // up
//                                glm::vec3{ 0.0f, 0.0f, -1.0f } };   // look at

    // PinholeCamera camera{ -2.5f,
	// 					  2.5f,
	// 					  -2.5f,
	// 					  2.5f,
	// 					  5.0f,
	// 					  glm::ivec2{ x_resolution, y_resolution },
	// 					  glm::vec3{ 0.0f, 0.0f, -5.0f },     // position
	// 					  glm::vec3{ 0.0f, -1.0f,  0.0f },     // up
	// 					  glm::vec3{ 0.0f, 0.0f, -1.0f } };   // look at

    // PinholeCamera camera{ -8.0f,
	// 					  8.0f,
	// 					  -4.5f,
	// 					  4.5f,
	// 					  5.0f,
	// 					  glm::ivec2{ x_resolution, y_resolution },
	// 					  glm::vec3{ -0.35f, 1.2f, 1.60f },     // position
	// 					  glm::vec3{ 0.0f, -1.0f,  0.0f },     // up
	// 					  glm::vec3{ -0.35f, 0.0f, -1.0f } };   // look at

    // glm::vec3{ -0.3f, 1.5f, 1.5f }
    // glm::vec3{ -0.35f, 10.0f, 5.0f }

    PinholeCamera camera{ -8.0f,
						  8.0f,
						  -4.5f,
						  4.5f,
						  5.0f,
						  glm::ivec2{ x_resolution, y_resolution },
						  glm::vec3{ -1.0f, 0.5f, 1.0f },     // position
						  glm::vec3{ 0.0f, -1.0f,  0.0f },     // up
						  glm::vec3{ -0.8f, 0.0f, -1.0f } };   // look at

    Scene scene{};

    scene.load();
    // scene.loadObj("/home/ryuugami/Codes/ray_tracer-master/3d_models/scene.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, m1);
    // scene.loadObj("/home/ryuugami/Desktop/models/Scene/left.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 1.0f, 0.0f, 0.0f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/models/Scene/right.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 1.0f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/models/Scene/updown.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/models/Scene/frontback.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/models/link_wolf2.obj", glm::vec3{ 0.0f, -1.0f, 1.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 239.0f, 148.0f, 45.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Codes/ray-tracer-university-project-master/models/bear.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, m1);

    // main scene test
    // scene.loadObj("/home/ryuugami/Desktop/Final Scene/Test-scene/paredes.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/Final Scene/Test-scene/balcao-madeira.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 141.0f, 69.0f, 15.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/Final Scene/Test-scene/balcao-vidro.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new SmoothDieletric{ glm::vec3{ 141.0f, 69.0f, 15.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Desktop/Final Scene/Test-scene/weapons.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new PerfectReflector{ glm::vec3{ 141.0f, 69.0f, 15.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });

    load_final_scene(&scene);

    auto start = std::chrono::steady_clock::now();   
    scene.buildBVH();
    auto end = std::chrono::steady_clock::now();

    long seconds;
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    seconds = time_span.count();

    std::string time = calculate_time(seconds);
    std::cout << "Time spent to build BVH: " << time << std::endl;

    Buffer rendering_buffer{ x_resolution, y_resolution };
    glm::vec3 background_color{ 0.0f, 0.0f, 0.0f };

    // Set up the renderer.
    PathTracer rt( camera,
                  scene,
                  background_color,
                  rendering_buffer );

    start = std::chrono::steady_clock::now();
    rt.integrate(); // Renders the final image.
    end = std::chrono::steady_clock::now();    

    // Save the rendered image to a .ppm file.
    rendering_buffer.save( "output_image9.ppm" );

    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    seconds = time_span.count();

    time = calculate_time(seconds);
    std::cout << "Time spent to render image: " << time << std::endl;

    return EXIT_SUCCESS;
}

