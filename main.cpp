#include <chrono>
#include <ctime>
#include <ratio>
#include <iostream>
#include "main.h"

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
    unsigned int x_resolution = 512;
    unsigned int y_resolution = 512;

//    OrthographicCamera camera{ -1.25f,
//                                1.25f,
//                               -1.25f,
//                                1.25f,
//								  5.0f,
//                                glm::ivec2{ x_resolution, y_resolution },
//                                glm::vec3{ 0.0f, 0.0f,  1.0f },     // position
//                                glm::vec3{ 0.0f, 1.0f,  0.0f },     // up
//                                glm::vec3{ 0.0f, 0.0f, -1.0f } };   // look at

    PinholeCamera camera{ -2.5f,
						  2.5f,
						  -2.5f,
						  2.5f,
						  5.0f,
						  glm::ivec2{ x_resolution, y_resolution },
						  glm::vec3{ 1.5f, 0.0f, 4.5f },     // position
						  glm::vec3{ 0.0f, -1.0f,  0.0f },     // up
						  glm::vec3{ 0.0f, 0.0f, -1.0f } };   // look at

    Scene scene{};

    scene.load();
    // scene.loadObj("/home/ryuugami/Codes/ray_tracer-master/3d_models/scene.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, m1);
    scene.loadObj("/home/ryuugami/Desktop/models/Scene/left.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 1.0f, 0.0f, 0.0f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene.loadObj("/home/ryuugami/Desktop/models/Scene/right.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.0f, 0.0f, 1.0f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene.loadObj("/home/ryuugami/Desktop/models/Scene/updown.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene.loadObj("/home/ryuugami/Desktop/models/Scene/frontback.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, Material{ new Diffuse{ glm::vec3{ 0.5f, 0.5f, 0.5f } }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    scene.loadObj("/home/ryuugami/Desktop/models/link_wolf.obj", glm::vec3{ 0.0f, -0.75f, -1.5f }, 1.0f, Material{ new CookTorrance{ glm::vec3{ 239.0f, 148.0f, 45.0f } / 255.0f }, glm::vec3{ 0.0f, 0.0f, 0.0f } });
    // scene.loadObj("/home/ryuugami/Codes/ray-tracer-university-project-master/models/bear.obj", glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.0f, m1);

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
    rendering_buffer.save( "output_image6.ppm" );

    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    seconds = time_span.count();

    time = calculate_time(seconds);
    std::cout << "Time spent to render image: " << time << std::endl;

    return EXIT_SUCCESS;
}

