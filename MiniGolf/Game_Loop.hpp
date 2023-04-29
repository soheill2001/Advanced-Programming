#ifndef _Game_Loop_HPP_
#define _Game_Loop_HPP_

#include <iostream>
#include <string>
#include "RSDL/src/rsdl.hpp"
#include "Golf.hpp"

void get_input(Final_Area &main_area, Ball &main_ball);
void update(Window *window, Golf *mini_golf);
void draw(Window *window, Golf *mini_golf);

#endif