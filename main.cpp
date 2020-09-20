#include <iostream>
#include <fstream>
#include "raytracer.h"
//#include "vec3.h"
//#include "ray.h"
#include "hitable_list.h"
#include "sphere.h"
#include "float.h"
#include "camera.h"
#include "random.h"
#include "lambertian.h"
#include "metal.h"

//vec3 random_in_unit_sphere() {
//    vec3 p;
//    do {
//        p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
//    } while(p.squared_length() >= 1.0);
//    return p;
//}

vec3 color(const ray& r, hitable *world, int depth) {
    hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
        ray scattered;
        vec3 attentuation;

        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attentuation, scattered)) {
            return attentuation*color(scattered, world, depth+1);
        } else {
            return vec3(0,0,0);
        }
        //vec3 target = rec.p + rec.normal + random::random_in_unit_sphere();
        //return 0.5*color(ray(rec.p, target-rec.p), world);
    } else {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5*(unit_direction.y() + 1.0);
        return (1.0-t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
    }
}

int main() {
    std::ofstream ppmFile;
    ppmFile.open("rgbFile.ppm");
    int nx = 900;
    int ny = 450;
    int ns = 100;

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 900;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;
    const int max_depth = 50;

    ppmFile << "P3\n" << nx << " " << ny << "\n255\n";
    //std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    hitable *list[4];
    list[0] = new sphere(vec3(0,0,-1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3)));
    list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
    list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2)));
    list[3] = new sphere(vec3(-1, 0, -1), 0.5, new metal(vec3(0.8, 0.8, 0.8)));
    hitable *world = new hitable_list(list, 4);
    camera cam;
    for (int j = ny-1; j >= 0; j--) {
        std::cout << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < nx; i++) {
            vec3 col(0,0,0);
            for (int s=0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                ray r = cam.get_ray(u, v);
                vec3 p = r.point_at_paramter(2.0);
                col += color(r, world, 0);
            }

            col /= float(ns);
            col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            ppmFile << ir << " " << ig << " " << ib << "\n";
            //std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    std::cerr << "\nDone.\n";
    ppmFile.close();
    return 0;
}