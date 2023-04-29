#include "Game_Loop.hpp"

using namespace std;

bool state = false;

enum string_convert
{
    grass_area,
    sand_area,
    water_area,
    hole,
    ball,
    wall,
    sharp_wall,
    moving_wall
};

string_convert hashit(string command)
{
    if (command == GRASS_AREA) return grass_area;
    if (command == SAND_AREA) return sand_area;
    if (command == WATER_AREA) return water_area;
    if (command == HOLE) return hole;
    if (command == BALL) return ball;
    if (command == WALL) return wall;
    if (command == SHARP_WALL) return sharp_wall;
    if (command == MOVING_WALL) return moving_wall;
}

void add_Land(Final_Area &main_area, string land_type)
{
    Point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    main_area.add_land(start, end, land_type);
}

void add_hole(Final_Area &main_area)
{
    Point pos;
    cin >> pos.x >> pos.y;
    main_area.add_hole_pos(pos);
}

void add_ball(Ball &main_ball)
{
    pair<float, float> pos;
    cin >> pos.first >> pos.second;
    main_ball.set_pos(pos);
}

void add_wall(Final_Area &main_area, string type)
{
    Point start, end;
    cin >> start.x >> start.y >> end.x >> end.y;
    main_area.add_wall(start, end, type);
}

void get_input(Final_Area &main_area, Ball &main_ball)
{
    string input;
    while (cin >> input)
    {
        switch (hashit(input))
        {
            case grass_area:
                add_Land(main_area, GRASS);
                break;
            case sand_area:
                add_Land(main_area, SAND);
                break;
            case water_area:
                add_Land(main_area, WATER);
                break;
            case hole:
                add_hole(main_area);
                break;
            case ball:
                add_ball(main_ball);
                break;
            case wall:
                add_wall(main_area, WALL);
                break;
            case sharp_wall:
                add_wall(main_area, SHARP_WALL);
                break;
            case moving_wall:
                add_wall(main_area, MOVING_WALL);
                break;
        }
    }
}

void update(Window *window, Golf *mini_golf)
{
    while (window->has_pending_event())
    {
        Event e = window->poll_for_event();
        switch (e.get_type())
        {
            case Event::EventType::QUIT:
                exit(0);
                break;
            case Event::EventType::LCLICK:
                if (mini_golf->ball_info()->get_speed() == 0)
                {
                    Point Prev_Mouse_Position = get_current_mouse_position();
                    mini_golf->ball_info()->set_Prev_Position({Prev_Mouse_Position.x, Prev_Mouse_Position.y});
                    mini_golf->inc_shoot();
                    state = true;
                    break;
                }
            case Event::EventType::LRELEASE:
                state = false;
                break;
        }
    }
    mini_golf->update(state, window);
    mini_golf->lose_check(window);
    mini_golf->win_check(window);
}

void draw(Window *window, Golf *mini_golf)
{
    window->clear();
    mini_golf->draw(window);
    window->update_screen();
}