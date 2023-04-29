#include "Wall.hpp"

using namespace std;

Wall::Wall(Point start, Point end, string type)
{
    start_pos = start;
    end_pos = end;
    wall_type = type;
}

void Wall::draw(Window *window)
{
    Rectangle r(start_pos.x, start_pos.y, end_pos.x, end_pos.y);
    if (wall_type == WALL)
        window->fill_rect(r, REGULAR_WALL_COLOR);
    else
        window->fill_rect(r, SHARP_WALL_COLOR);
}