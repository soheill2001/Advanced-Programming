#ifndef _Wall_HPP_
#define _Wall_HPP_

#include <string>
#include <iostream>
#include "Defines.hpp"
#include "RSDL/src/rsdl.hpp"

class Wall
{
public:
    Wall(Point start, Point end, std::string type);
    void draw(Window *window);
    std::pair<Point, Point> get_pos() { return {start_pos, end_pos}; }
    std::string get_type() { return wall_type; }
private:
    Point start_pos;
    Point end_pos;
    std::string wall_type;
};

#endif