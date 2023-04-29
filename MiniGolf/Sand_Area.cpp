#include "Sand_Area.hpp"

using namespace std;

Sand_Area::Sand_Area(Point start, Point end, float fc)
{
    start_pos = start;
    end_pos = end;
    friction_coefficient = fc;
}

void Sand_Area::draw(Window *window)
{
    Rectangle r(start_pos.x, start_pos.y, end_pos.x, end_pos.y);
    window->fill_rect(r, SAND_COLOR);
}