#include "Water_Area.hpp"

using namespace std;

Water_Area::Water_Area(Point start, Point end)
{
    start_pos = start;
    end_pos = end;
}

void Water_Area::draw(Window *window)
{
    Rectangle r(start_pos.x, start_pos.y, end_pos.x, end_pos.y);
    window->fill_rect(r, BLUE);
}