//
// Created by Jared Morante on 9/20/20.
//

#ifndef LUMARENDER_COLOR_H
#define LUMARENDER_COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0, 255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif //LUMARENDER_COLOR_H
