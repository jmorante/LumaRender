//
// Created by Jared Morante on 9/19/20.
//

#ifndef LUMARENDER_RANDOM_H
#define LUMARENDER_RANDOM_H
#include "vec3.h"

class random {
    public:
        static vec3 random_in_unit_sphere() {
            vec3 p;
            do {
                p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
            } while(p.squared_length() >= 1.0);
            return p;
        }
};


#endif //LUMARENDER_RANDOM_H
