#include "Moving_Wall.hpp"

using namespace std;

Moving_Wall::Moving_Wall(Point start, Point end)
{
    start_pos = start;
    end_pos = end;
    if (end.x >= end.y)
        set_velocity({1, 0});
    else
        set_velocity({0, 1});
    speed = WALL_SPEED;
}

void Moving_Wall::set_velocity(Point velo)
{
    velocity.x = velo.x;
    velocity.y = velo.y;
}

void Moving_Wall::draw(Window *window)
{
    Rectangle r(start_pos.x, start_pos.y, end_pos.x, end_pos.y);
    window->fill_rect(r, REGULAR_WALL_COLOR);
}

void Moving_Wall::update()
{
    start_pos += velocity * speed;
}