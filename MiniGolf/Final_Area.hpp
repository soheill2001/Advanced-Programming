#ifndef _Final_Area_HPP_
#define _Final_Area_HPP_

#include <iostream>
#include <vector>
#include "Water_Area.hpp"
#include "Grass_Area.hpp"
#include "Sand_Area.hpp"
#include "Defines.hpp"
#include "Wall.hpp"
#include "Moving_Wall.hpp"
#include "Ball.hpp"
#include "RSDL/src/rsdl.hpp"

typedef std::vector<Grass_Area> VecGrass;
typedef std::vector<Sand_Area> VecSand;
typedef std::vector<Water_Area> VecWater;
typedef std::vector<Wall> VecWall;
typedef std::vector<Moving_Wall> VecMovWall;

class Ball;

class Final_Area
{
public:
    Final_Area() = default;
    void update();
    void add_land(Point start, Point end, std::string type);
    void add_wall(Point start, Point end, std::string type);
    void add_hole_pos(Point pos);
    void draw(Window *window);
    void reflect (Ball *ball);
    bool win_check(Ball *ball);
    bool lose_check(Ball *ball);
    float where_is_ball(Ball *ball);
private:
    bool check_reflect(Ball *ball, auto wall);
    VecGrass Grass_lands;
    VecSand Sand_lands;
    VecWater Water_lands;
    VecWall walls;
    VecMovWall walking_walls;
    Point hole_pos;
};

#endif