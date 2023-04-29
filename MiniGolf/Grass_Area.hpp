#ifndef _Grass_Area_HPP_
#define _Grass_Area_HPP_

#include <iostream>
#include "Defines.hpp"
#include "RSDL/src/rsdl.hpp"

class Grass_Area
{
public:
    Grass_Area(Point start, Point end, float fc = GRASS_FRICTION_COEFFICIENT);
    void draw(Window *window);
    std::pair<Point, Point> get_pos() { return {start_pos, end_pos}; }
    float get_fc() { return friction_coefficient; }
private:
    Point start_pos;
    Point end_pos;
    float friction_coefficient;
};

#endif