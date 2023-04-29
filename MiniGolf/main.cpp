#include "Game_Loop.hpp"
#include "RSDL/src/rsdl.hpp"
#include "Golf.hpp"
#include <string>

using namespace std;

int main()
{
    Ball main_ball;
    Final_Area main_land;
    get_input(main_land, main_ball);
    main_ball.add_curr_land(&main_land);
    Golf mini_golf(&main_land, &main_ball);
    Window *window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    while(true)
    {
        update(window, &mini_golf);
        draw(window, &mini_golf);
        delay(DELAY);
    }
}