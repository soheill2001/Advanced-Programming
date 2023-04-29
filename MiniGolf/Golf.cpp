#include "Golf.hpp"

using namespace std;

Golf::Golf(Final_Area *land, Ball *ball)
{
    golf_land = land;
    main_ball = ball;
    shoot_ball = INIT_SHOOT;
}

void Golf::win_check(Window *window)
{
    if (golf_land->win_check(main_ball))
    {
        window->show_text(WIN_MESSAGE, MESSAGE_POSITION, RED, FONT, MESSAGE_SIZE);
        window->update_screen();
        delay(WIN_LOSE_DELAY);
        exit(0);
    }
}

void Golf::lose_check(Window *window)
{
    if (golf_land->lose_check(main_ball))
    {
        window->show_text(LOSE_MESSAGE, MESSAGE_POSITION, RED, FONT, MESSAGE_SIZE);
        window->update_screen();
        delay(WIN_LOSE_DELAY);
        exit(0);
    }
}

void Golf::draw(Window *window)
{
    golf_land->draw(window);
    main_ball->draw(window);
    window->show_text(to_string(shoot_ball), COUNTER_POSITION, RED, FONT, MESSAGE_SIZE);
}

void Golf::update(bool state, Window *window)
{
    golf_land->update();
    main_ball->update(state, window);
}