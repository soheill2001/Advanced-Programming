#ifndef _Ball_HPP_
#define _Ball_HPP_

#include <iostream>
#include <cmath>
#include <string>
#include "RSDL/src/rsdl.hpp"
#include "Defines.hpp"
#include "Final_Area.hpp"

class Final_Area;           

class Ball
{
public:
    Ball(float sp = 0, Point velo = {INIT_POSITION, INIT_POSITION});
    void draw(Window *window);
    void set_speed(float decrease);
    void set_pos(std::pair<float, float> pos);
    void update(bool state, Window *window);
    void set_Prev_Position(std::pair<float, float> Prev_Pos);
    void add_curr_land(Final_Area *Field) { Area = Field; };
    void set_velocity(float vx, float vy);
    float get_speed() { return speed; }
    std::pair<float, float> get_ball_pos() { return ball_pos; }
    std::pair<float, float> get_velocity() { return velocity_vector; }
private:
    void move();
    void set_Current_Position(std::pair<float, float> Curr_Pos);
    Final_Area *Area;
    std::pair<float, float> ball_pos;
    Point Prev_Mouse_Position;
    Point Current_Mouse_Position;
    std::pair<float, float> velocity_vector;
    float speed;
};

#endif