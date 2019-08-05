//
// Created by Jared Morante on 2019-08-04.
//

#ifndef LUMARENDER_HITABLE_H
#define LUMARENDER_HITABLE_H

#include "ray.h"

struct hit_record {
    float t;
    vec3 p;
    vec3 normal;
};

class hitable {
    public:
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};
#endif //LUMARENDER_HITABLE_H
