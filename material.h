//
// Created by Jared Morante on 9/19/20.
//

#ifndef LUMARENDER_MATERIAL_H
#define LUMARENDER_MATERIAL_H
#include "ray.h"
#include "hittable.h"
#include "raytracer.h"

struct hit_record;

class material {
    public:
        virtual bool scatter(
            const ray& ray_in, const hit_record& rec, vec3& attenuation, ray& scattered
        ) const = 0;
};

class lambertian : public material {
    public:
        lambertian(const color& a) : albedo(a) {}

        virtual bool scatter(
                const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override {
            vec3 scatter_direction = rec.normal + random_unit_vector();
            scattered = ray(rec.p, scatter_direction);
            attenuation = albedo;
            return true;
        }

    public:
        color albedo;
};

#endif //LUMARENDER_MATERIAL_H
