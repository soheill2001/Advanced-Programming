#include "Errors.hpp"

using namespace std;

void Error_Handle::signup_errors(VecString attributes, VecUser *users)
{
    string user = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), USERNAME)) + 1];
    for (int i = 0; i < users->size(); i++)
    {
        if ((*users)[i].check_username(user))
            throw BAD_REQUEST;
    }
}

void Error_Handle::login_errors(VecString attributes, VecUser *users)
{
    bool condition = false;
    int username_pos = distance(attributes.begin(), find(attributes.begin(), attributes.end(), USERNAME));
    int password_pos = distance(attributes.begin(), find(attributes.begin(), attributes.end(), PASSWORD));
    for (int i = 0; i < users->size(); i++)
    {
        if ((*users)[i].check_username(attributes[username_pos + 1]) && (*users)[i].check_password(attributes[password_pos + 1]))
        {
            condition = true;
        }
    }
    if (!condition)
        throw BAD_REQUEST;
}

void Error_Handle::wallet_errors(VecString attributes)
{
    int amount_pos = distance(attributes.begin(), find(attributes.begin(), attributes.end(), AMOUNT));
    float money = stof(attributes[amount_pos + 1]);
    if (money <= 0)
        throw BAD_REQUEST;
}

void Error_Handle::ticket_errors(pair<Flight_Data, string> flight_seat, pair<int, float> user_request, User *user)
{
    if (flight_seat.second == ECONOMY)
    {
        if (flight_seat.first.economy_seats < user_request.first)
            throw BAD_REQUEST;
    }
    else
    {
        if (flight_seat.first.business_seats < user_request.first)
            throw BAD_REQUEST;
    }
    if (!user->check_money(user_request.second))
        throw BAD_REQUEST;
}

void Error_Handle::flight_errors(VecAirlines *airlines, int flight_id)
{
    int flights_number = 0;
    for (int i = 0; i < airlines->size(); i++)
        flights_number += (*airlines)[i].get_flights().size();
    if (flights_number == NO_FLIGHTS)
        throw EMPTY;
    if (flight_id > flights_number)
        throw NOT_FOUND;
}