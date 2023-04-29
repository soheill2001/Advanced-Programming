#include "Final_Area.hpp"

using namespace std;

void Final_Area::add_land(Point start, Point end, string type)
{
    if (type == SAND)
    {
        Sand_Area new_sand(start, end);
        Sand_lands.push_back(new_sand);
    }
    else if (type == WATER)
    {
        Water_Area new_water(start, end);
        Water_lands.push_back(new_water);
    }
    else 
    {
        Grass_Area new_grass(start, end);
        Grass_lands.push_back(new_grass);
    }
}

void Final_Area::add_hole_pos(Point pos)
{
    hole_pos = pos;
}

void Final_Area::add_wall(Point start, Point end, string type)
{
    if (type == MOVING_WALL)
    {
        Moving_Wall new_wall(start, end);
        walking_walls.push_back(new_wall);
    }
    else
    {
        Wall new_wall(start, end, type);
        walls.push_back(new_wall);
    }
}

void Final_Area::draw(Window *window)
{
    for (int i = 0; i < Grass_lands.size(); i++)
        Grass_lands[i].draw(window);
    for (int i = 0; i < Sand_lands.size(); i++)
        Sand_lands[i].draw(window);
    for (int i = 0; i < Water_lands.size(); i++)
        Water_lands[i].draw(window);
    for (int i = 0; i < walls.size(); i++)
        walls[i].draw(window);
    for (int i = 0; i < walking_walls.size(); i++)
        walking_walls[i].draw(window);
    window->fill_circle(hole_pos, HOLE_RADIUS, BLACK);
}

bool Final_Area::check_reflect(Ball *ball, auto wall)
{
    pair<float, float> ball_pos = ball->get_ball_pos(); 
    pair<float, float> velocity_vector = ball->get_velocity();
    for (int i = 0; i < wall.size(); i++)
    {
        int width = wall[i].get_pos().second.x; int height = wall[i].get_pos().second.y;
        int x_pos = wall[i].get_pos().first.x; int y_pos = wall[i].get_pos().first.y;
        if (ball_pos.first + (velocity_vector.first * DELTA_VELO) >= x_pos && 
            ball_pos.first + (velocity_vector.first * DELTA_VELO) <= x_pos + width &&
            ball_pos.second >= y_pos && ball_pos.second <= y_pos + height)
            {
                if (wall[i].get_type() == SHARP_WALL) { return false; }
                ball->set_velocity(-velocity_vector.first, velocity_vector.second);
            }
        if (ball_pos.first >= x_pos && ball_pos.first <= x_pos + width &&
            ball_pos.second + (velocity_vector.second * DELTA_VELO) >= y_pos && 
            ball_pos.second + (velocity_vector.second * DELTA_VELO) <= y_pos + height)
            {
                if (wall[i].get_type() == SHARP_WALL) { return false; }
                ball->set_velocity(velocity_vector.first, -velocity_vector.second);
            } 
    }
    return true;
}

void Final_Area::reflect(Ball *ball)
{
    check_reflect(ball, walls);
    check_reflect(ball, walking_walls);
}

float Final_Area::where_is_ball(Ball *ball)
{
    pair<float, float> ball_pos = ball->get_ball_pos();
    for (int i = 0; i < Grass_lands.size(); i++)
    {
        int width = Grass_lands[i].get_pos().second.x; int height = Grass_lands[i].get_pos().second.y;
        int x_pos = Grass_lands[i].get_pos().first.x; int y_pos = Grass_lands[i].get_pos().first.y;
        if (ball_pos.first >= x_pos && ball_pos.first <= x_pos + width &&
            ball_pos.second >= y_pos && ball_pos.second <= y_pos + height)
                return Grass_lands[i].get_fc();
    }
    for (int i = 0; i < Sand_lands.size(); i++)
    {
        int width = Sand_lands[i].get_pos().second.x; int height = Sand_lands[i].get_pos().second.y;
        int x_pos = Sand_lands[i].get_pos().first.x; int y_pos = Sand_lands[i].get_pos().first.y;
        if (ball_pos.first >= x_pos && ball_pos.first <= x_pos + width &&
            ball_pos.second >= y_pos && ball_pos.second <= y_pos + height)
                return Sand_lands[i].get_fc();
    }
    return BALL_IN_WATER;
}

bool Final_Area::win_check(Ball *ball)
{
    pair<float, float> ball_pos = ball->get_ball_pos();
    float d = sqrt((pow(ball_pos.first- hole_pos.x, 2) + pow(ball_pos.second - hole_pos.y, 2)));
    if (d < HOLE_RADIUS)
        return true;
    else
        return false;
}

bool Final_Area::lose_check(Ball *ball)
{
    if (where_is_ball(ball) == BALL_IN_WATER)
        return true;
    else if (!check_reflect(ball, walls))
        return true;
    else
        return false;
}

void Final_Area::update()
{
    for (int j = 0; j < walking_walls.size(); j++)
    {
        int wall_x = walking_walls[j].get_pos().first.x; int wall_y = walking_walls[j].get_pos().first.y;
        int wall_height = walking_walls[j].get_pos().first.x + walking_walls[j].get_pos().second.x;
        int wall_width = walking_walls[j].get_pos().first.y + walking_walls[j].get_pos().second.y;
        int wall_velo_x = walking_walls[j].get_velocity().x; int wall_velo_y = walking_walls[j].get_velocity().y;
        for (int i = 0; i < walls.size(); i++)
        {
            int width = walls[i].get_pos().second.x; int height = walls[i].get_pos().second.y;
            int x_pos = walls[i].get_pos().first.x; int y_pos = walls[i].get_pos().first.y;
            if ((wall_x + wall_velo_x >= x_pos || wall_height + wall_velo_x >= x_pos) && 
                (wall_x + wall_velo_x <= x_pos + width || wall_height + wall_velo_x <= x_pos + width) &&
                wall_y >= y_pos && wall_y <= y_pos + height)
                    walking_walls[j].set_velocity({-wall_velo_x, wall_velo_y});
            if (wall_x >= x_pos && wall_x <= x_pos + width &&
                (wall_y + wall_velo_y >= y_pos || wall_width + wall_velo_y >= y_pos) && 
                ((wall_y + wall_velo_y <= y_pos + height) || wall_width + wall_velo_y <= y_pos + height))
                    walking_walls[j].set_velocity({wall_velo_x, -wall_velo_y});
        }
        walking_walls[j].update();
    }
}