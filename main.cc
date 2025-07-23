#include "rtweekend.h"

#include "camera.h"
#include "hittable.h"
#include "material.h"
#include "hittable_list.h"
#include "sphere.h"



int main() {
    hittable_list world;
    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    world.add(make_shared<sphere>(point3( 0.0, -1000, 0), 1000.0, material_ground));

    //Felipe P MElo
    //Uma lua brilhante
    auto material_lua = make_shared<lambertian>(color(2.0, 2.0, 0.8)); //talvez seja melhor ajustar 
    world.add(make_shared<sphere>(point3(16.0, 40, -200), 100.0, material_lua));

    //Felipe P Melo
    //Estrelas de metal
    for (int i = 0; i < 100; ++i) {
        double radius = random_double(0.5, 1.5);
        double x = random_double(-60, 10);
        double y = random_double(0, 80);  
        double z = random_double(-200, 0);

        auto metal_star = make_shared<metal>(
            color(random_double(0.7, 1.0), random_double(0.7, 1.0), random_double(0.7, 1.0)),
            0.0
        );

        world.add(make_shared<sphere>(point3(x, y, z), radius, metal_star));
    }
    

/*
    
    auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
    auto material_left   = make_shared<dielectric>(1.50);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.50);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

    
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.4, material_bubble));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, material_right));
*/
    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;


    cam.vfov     = 90;
    cam.lookfrom = point3(13,2,2);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist    = 10.0;

    cam.render(world);
}
