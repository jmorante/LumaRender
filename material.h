//
// Created by Jared Morante on 9/19/20.
//

#ifndef LUMARENDER_MATERIAL_H
#define LUMARENDER_MATERIAL_H
#include "ray.h"
#include "hitable.h"

class material {
    public:
        virtual bool scatter(const ray& ray_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
};


#endif //LUMARENDER_MATERIAL_H
