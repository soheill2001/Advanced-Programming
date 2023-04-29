#ifndef _Defines_HPP_
#define _Defines_HPP_

#include <iostream>
#include <string>
#include "RSDL/src/rsdl.hpp"

const std::string GRASS_AREA = "grass_area";
const std::string SAND_AREA = "sand_area";
const std::string WATER_AREA = "water_area";
const std::string HOLE = "hole";
const std::string BALL = "ball";
const std::string SAND = "sand";
const std::string WATER = "water";
const std::string GRASS = "grass";
const std::string WALL = "wall";
const std::string SHARP_WALL = "sharp_wall";
const std::string MOVING_WALL = "moving_wall";
const std::string WINDOW_TITLE = "RDSL";
const std::string WIN_MESSAGE = "WIN!";
const std::string LOSE_MESSAGE = "GAME OVER!";
const std::string FONT = "FreeSansBoldOblique-g9mR.ttf";
const float GRASS_FRICTION_COEFFICIENT = 0.0003;
const float SAND_FRICTION_COEFFICIENT = 0.0009;
const float MAX_INIT_SPEED = 0.1;
const float BALL_IN_WATER = 1000000;
const float WALL_SPEED = 1;
const float DELTA_SPEED = 0.1;
const float DELTA_VELO = 0.01;
const int INIT_POSITION = 0;
const int BALL_RADIUS = 5;
const int HOLE_RADIUS = 10;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 640;
const int DELAY = 10;
const int INIT_SHOOT = 0;
const int MESSAGE_SIZE = 50;
const int WIN_LOSE_DELAY = 2500;
const RGB REGULAR_WALL_COLOR = RGB(201, 135, 42);
const RGB SHARP_WALL_COLOR = RGB(84, 55, 16);
const RGB SAND_COLOR = RGB(255, 213, 154);
const Point MESSAGE_POSITION = Point(200, 200);
const Point COUNTER_POSITION = Point(5, 5);

#endif