#include "Ball.hpp"

using namespace std;

Ball::Ball(float sp, Point velo)
{
    speed = sp;
    velocity_vector.first = velo.x;
    velocity_vector.second = velo.y;
}

void Ball::set_pos(std::pair<float, float> pos)
{
    ball_pos.first = pos.first;
    ball_pos.second = pos.second;
    Current_Mouse_Position.x = pos.first;
    Current_Mouse_Position.y = pos.second;
    Prev_Mouse_Position.x = pos.first;
    Prev_Mouse_Position.y = pos.second;
}

void Ball::draw(Window *window)
{
    window->fill_circle({(int)ball_pos.first, (int)ball_pos.second}, BALL_RADIUS, WHITE);
    window->draw_line({(int)ball_pos.first, (int)ball_pos.second},
        {(Prev_Mouse_Position.x - Current_Mouse_Position.x) + (int)ball_pos.first,
        (Prev_Mouse_Position.y - Current_Mouse_Position.y) + (int)ball_pos.second}, RED);
}

void Ball::set_Prev_Position(pair<float, float> Prev_Pos)
{
    Prev_Mouse_Position.x = Prev_Pos.first;
    Prev_Mouse_Position.y = Prev_Pos.second;
}

void Ball::set_Current_Position(pair<float, float> Curr_Pos)
{
    Current_Mouse_Position.x = Curr_Pos.first;
    Current_Mouse_Position.y = Curr_Pos.second;
}

void Ball::set_velocity(float vx, float vy)
{
    velocity_vector.first = vx;
    velocity_vector.second = vy;
}

void Ball::set_speed(float decrease)
{
    speed = speed - decrease;
    if (speed < 0)
        speed = 0;
}

void Ball::move()
{
    ball_pos.first += velocity_vector.first * speed * DELTA_SPEED;
    ball_pos.second += velocity_vector.second * speed * DELTA_SPEED;
    Area->reflect(this);
}

void Ball::update(bool state, Window *window)
{
    if (state)
    {
        set_Current_Position({get_current_mouse_position().x, get_current_mouse_position().y});
        set_velocity(Prev_Mouse_Position.x - Current_Mouse_Position.x, Prev_Mouse_Position.y - Current_Mouse_Position.y);
        speed = MAX_INIT_SPEED;
    }
    else
    {
        set_Prev_Position(ball_pos);
        set_Current_Position(ball_pos);
        move();
        set_speed(Area->where_is_ball(this));
    }
}