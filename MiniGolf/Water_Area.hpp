#ifndef _Water_Area_HPP_
#define _Water_Area_HPP_

#include <iostream>
#include "RSDL/src/rsdl.hpp"

class Water_Area
{
public:
    Water_Area(Point start, Point end);
    void draw(Window *window);
    std::pair<Point, Point> get_pos() { return {start_pos, end_pos}; }
private:
    Point start_pos;
    Point end_pos;
};

#endif