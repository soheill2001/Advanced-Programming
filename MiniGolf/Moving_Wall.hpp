#ifndef _Moving_Wall_HPP_
#define _Moving_Wall_HPP_

#include <string>
#include <iostream>
#include "Defines.hpp"
#include "RSDL/src/rsdl.hpp"

class Moving_Wall
{
public:
    Moving_Wall(Point start, Point end);
    void draw(Window *window);
    void update();
    void set_velocity(Point velo);
    Point get_velocity() { return velocity; }
    std::string get_type() { return WALL; }
    std::pair<Point, Point> get_pos() { return {start_pos, end_pos}; }
private:
    Point start_pos;
    Point end_pos;
    Point velocity;
    float speed;
};

#endif