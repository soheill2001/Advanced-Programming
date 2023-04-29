#include "Utravel.hpp"

using namespace std;

Utravel::Utravel()
{
    user_login_id = 0;
    tickets_sell = 0;
}

void Utravel::check_user_login(bool condition)
{
    if (!condition)
    {
        if (user_login_id != USER_LOGIN)
        {
            throw PERMISSION_DENIED;
        }
    }
    if (condition)
    {
        if (user_login_id == USER_LOGIN)
        {
            throw PERMISSION_DENIED;
        }
    }
}

Flight Utravel::find_flight(int flight_id)
{
    int flights_number = 0;
    for (int i = 0; i < airlines.size(); i++)
        flights_number += airlines[i].get_flights().size();
    for (int i = 0; i < flights_number; i++)
        for (int j = 0; j < airlines.size(); j++)
            for (int z = 0; z < airlines[j].get_flights().size(); z++)
                if (airlines[j].get_flights()[z].get_fight_data().id == flight_id)
                    return airlines[j].get_flights()[z];
    throw NOT_FOUND;
}

bool compare_id(const Flight_Data &a, const Flight_Data &b)
{
    return a.id < b.id;
}

void Utravel::add_flights(Flight *new_flight, string airline_name)
{
    bool condition = false;
    for (int i = 0; i < airlines.size(); i++)
    {
        if (airlines[i].get_airline_name() == airline_name)
        {
            airlines[i].add_flight(*new_flight);
            condition= true;
            break;
        }
    }
    if (!condition)
    {
        Airline *new_airline = new Airline(airline_name);
        new_airline->add_flight(*new_flight);
        airlines.push_back(*new_airline);
    }
    all_flights.push_back(new_flight->get_fight_data());
    sort(all_flights.begin(), all_flights.end(), compare_id);
}

void Utravel::signup_(VecString attributes)
{
    check_user_login(false);
    error_handle->signup_errors(attributes, &users);
    string username, password;
    username = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), USERNAME)) + 1];
    password = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), PASSWORD)) + 1];
    User *new_user = new User(username, password, users.size() + 1);
    new_user->increase_money(1000);
    users.push_back(*new_user);
    user_login_id = users.size();
    throw OK;
}

void Utravel::login_(VecString attributes)
{
    check_user_login(false);
    error_handle->login_errors(attributes, &users);
    int username_pos = distance(attributes.begin(), find(attributes.begin(), attributes.end(), USERNAME)) + 1;
    int password_pos = distance(attributes.begin(), find(attributes.begin(), attributes.end(), PASSWORD)) + 1;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].check_username(attributes[username_pos]) && users[i].check_password(attributes[password_pos]))
        {
            user_login_id = i + 1;
        }
    }
    throw OK;
}

void Utravel::logout_()
{
    check_user_login(true);
    user_login_id = USER_LOGIN;
    filters.clear();
    throw OK;
}

void Utravel::wallet_(VecString attributes)
{
    check_user_login(true);
    error_handle->wallet_errors(attributes);
    float money = stof(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), AMOUNT)) + 1]);
    users[user_login_id].increase_money(money);
    throw OK;
}

/*void Utravel::tickets_(VecString attributes)
{
    check_user_login(user_login_id);
    float cost;
    int flight_id = stoi(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), FLIGHT_ID)) + 1]);
    Flight flight_ = find_flight(flight_id);
    Flight_Data flight = flight_.get_fight_data();
    int quantity = stoi(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), QUANTITY)) + 1]);
    string flight_class = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), CLASS)) + 1];
    string ticket_type = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), TYPE)) + 1];
    if (flight_class == ECONOMY)
        cost = flight.base_price * quantity;
    else
        cost = flight.base_price * quantity * BUSINESS_PRICE;
    error_handle->ticket_errors({flight, flight_class}, {quantity, cost}, &users[user_login_id]);
    tickets_sell++;
    users[user_login_id].buy_ticket({tickets_sell, quantity}, {flight_class, ticket_type}, {cost, flight_id});
    flight_.buy_seat(quantity, flight_class);
    all_flights[flight_id] = flight_.get_fight_data();
    throw to_string(tickets_sell);
}*/

VecOfFlights Utravel::apply_filter()
{
    check_user_login(true);
    bool condition = false;
    VecOfFlights flights_new;
    for (int i = 0; i < all_flights.size(); i++)
    {
        for (int j = 0; j < filters.size(); j++)
        {
            if (filters[j]->check_flight(all_flights[i]))
                condition = true;
            else
                condition = false;
        }
        if (condition)
            flights_new.push_back(all_flights[i]);
    }
    return flights_new;
}

VecOfFlights Utravel::flights_(VecString attributes)
{
    check_user_login(true);
    VecOfFlights flight_to_print;
    int flight_id = 0;
    if (attributes.size() > 0)
        flight_id = stoi(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), ID)) + 1]);
    error_handle->flight_errors(&airlines, flight_id);
    if (attributes.size() <= 0)
        if (filters.size() > 0)
        {
            flight_to_print = apply_filter();
            return flight_to_print;
        }
        else
            return all_flights;
    return VecOfFlights {all_flights[flight_id - 1]};
}

/*TicketInfo Utravel::get_tickets(VecString attributes)
{
    int ticket_id = 0;
    if (attributes.size() > 0)
        ticket_id = stoi(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), ID)) + 1]);
    if (attributes.size() <= 0)
    {
        TicketInfo new_info;
        new_info.second = all_flights;
        VecCheckTicket new_ticket;
        new_ticket = users[user_login_id].get_user_tickets(0);
        //new_info.first = *new_ticket;
        //return new_info;
        return make_pair(new_ticket.first, all_flights);
        //return {users[user_login_id].get_user_tickets(), all_flights};
    }
    //return users[user_login_id].get_user_tickets(ticket_id);
}*/

/*void Utravel::delete_ticket(VecString attributes)
{
    int ticket_id = stoi(attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), ID)) + 1]);
    //if (users[user_login_id].delete_ticket(ticket_id))
}*/

void Utravel::add_filter(Main_Filter *new_filter)
{
    check_user_login(true);
    filters.push_back(new_filter);
    throw OK;
}