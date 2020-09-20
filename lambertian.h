//
// Created by Jared Morante on 9/19/20.
//

#ifndef LUMARENDER_LAMBERTIAN_H
#define LUMARENDER_LAMBERTIAN_H
#include "material.h"
#include "random.h"

class lambertian : public material {
    public:
        lambertian(const vec3& a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const {
            vec3 target = rec.p + rec.normal + random::random_in_unit_sphere();
            scattered = ray(rec.p, target-rec.p);
            attenuation = albedo;
            return true;
        }

        vec3 albedo;
};


#endif //LUMARENDER_LAMBERTIAN_H
