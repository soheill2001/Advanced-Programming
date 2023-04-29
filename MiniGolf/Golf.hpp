#ifndef _Golf_HPP_
#define _Golf_HPP_

#include "Final_Area.hpp"
#include "Ball.hpp"

class Golf
{
public:
    Golf(Final_Area *land, Ball *ball);
    Ball *ball_info() { return main_ball; }
    Final_Area *area_info() { return golf_land; }
    void update(bool state, Window *window);
    void draw(Window *window);
    void win_check(Window *window);
    void lose_check(Window *window);
    void inc_shoot() { shoot_ball++; }
private:
    Ball *main_ball;
    Final_Area *golf_land;
    int shoot_ball;
};

#endif