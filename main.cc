#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "material.h"
#include "hittable_list.h"
#include "sphere.h"



int main() {
    hittable_list world;
    auto material_ground = make_shared<lambertian>(color(0.4, 0.8, 0.1));
    world.add(make_shared<sphere>(point3( 0.0, -830, 0), 800.0, material_ground));

    //Felipe P MElo
    //Uma lua brilhante
    auto material_lua = make_shared<lambertian>(color(2.0, 2.0, 0.8));  
    world.add(make_shared<sphere>(point3(0, 10, -300), 150.0, material_lua));

    //Felipe P Melo
    //Estrelas de metal
    for (int i = 0; i < 20; ++i) {
        double radius = random_double(4.0, 10.0);
        double x = random_double(-70, 70);
        double y = random_double(-30, -20);  
        double z = random_double(-60, 30);

        auto metal_star = make_shared<metal>(
            color(random_double(0.7, 1.0), random_double(0.7, 1.0), random_double(0.7, 1.0)),
            0.0
        );

        world.add(make_shared<sphere>(point3(x, y, z), radius, metal_star));
    }
    
    // Esferas de vidro (dielétrico)
    for (int i = 0; i < 7; ++i) {
        double radius = random_double(2.0, 5.0);
        double x = random_double(-25, 25); 
        double y = random_double(-5, 20);
        double z = random_double(-30, 0); 

        auto glass_material = make_shared<dielectric>(1.5);

        // Esfera de vidro com casca interna negativa
        world.add(make_shared<sphere>(point3(x, y, z), radius, glass_material));
        world.add(make_shared<sphere>(point3(x, y, z), -radius * 0.95, glass_material));
    }

    // Criação de esferas difusas com cores baseadas em posição
    for (int i=0; i<50;i++) {
        double radius = random_double(5.0, 12.0);
        double x = random_double(-250, 250);
        double y = random_double(-30, 120);
        double z = random_double(-150, -120); 

        auto lambert_material = make_shared<lambertian>(
            color(x/255,y/255,1 - z/255)
        );

        world.add(make_shared<sphere>(point3(x, y, z), radius, lambert_material));
    }
    for (int i=0; i<50;i++) {
        double radius = random_double(5.0, 12.0);
        double x = random_double(-250, 250);
        double y = random_double(-30, 120);
        double z = random_double(120, 150); 

        auto lambert_material = make_shared<lambertian>(
            color(x/255,y/255,1 - z/255)
        );

        world.add(make_shared<sphere>(point3(x, y, z), radius, lambert_material));
    }
    for (int i=0; i<20;i++) {
        double radius = random_double(5.0, 12.0);
        double x = random_double(-250, 250);
        double y = random_double(100, 120);
        double z = random_double(-120, 120); 

        auto lambert_material = make_shared<lambertian>(
            color(x/255,y/255,1 - z/255)
        );

        world.add(make_shared<sphere>(point3(x, y, z), radius, lambert_material));
    }

    // Criação da esfera de vidro no centro da tela
    world.add(make_shared<sphere>(point3(0,0,5), 2.0, make_shared<dielectric>(1.7)));
    world.add(make_shared<sphere>(point3(0,0,5), -2 * 0.95, make_shared<dielectric>(1.7)));

    
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1920;
    cam.samples_per_pixel = 1000;
    cam.max_depth         = 100;


    cam.vfov     = 90;
    cam.lookfrom = point3(0, 0, 10);         // um pouco atrás da origem
    cam.lookat   = point3(0, 0, -1);         // olha para trás (objeto fica mais perto com um Z maior)
    cam.vup      = vec3(0, 1, 0);           // "para cima" é Y+

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}
