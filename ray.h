//
// Created by Jared Morante on 2019-07-30.
//

#ifndef LUMARENDER_RAY_H
#define LUMARENDER_RAY_H
#include "vec3.h"

class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        point3 origin() const  {return orig;}
        vec3 direction() const {return dir;}

        point3 at(double t) const {
            return orig + t*dir; }

    public:
        point3 orig;
        vec3 dir;
};
#endif //LUMARENDER_RAY_H
