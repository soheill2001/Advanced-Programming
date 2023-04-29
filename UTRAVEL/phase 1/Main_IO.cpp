#include "Main_IO.hpp"

using namespace std;

enum string_convert
{
    signup,
    _post_,
    _get_,
    _delete_,
    login,
    logout,
    wallet,
    tickets,
    flights,
    filter,
    garbage
};

string_convert hash_it(string command)
{
    if (command == SIGNUP) return signup;
    if (command == LOGIN) return login;
    if (command == LOGOUT) return logout;
    if (command == WALLET) return wallet;
    if (command == TICKETS) return tickets;
    if (command == FLIGHTS) return flights;
    if (command == POST) return _post_;
    if (command == GET) return _get_;
    if (command == DELETE) return _delete_;
    if (command == FILTERS) return filter;
    else return garbage;
}

Main_IO::Main_IO(Utravel *new_travel)
{
    utravel = new_travel;
}

int Main_IO::string_to_time(string new_time)
{
    int hour = (new_time[0] - STRING_TO_INT) * 10 + (new_time[1] - STRING_TO_INT);
    int min = (new_time[3] - STRING_TO_INT) * 10 + (new_time[4] - STRING_TO_INT);
    return (hour * ONE_HOUR_AS_MIN + min);
}

void Main_IO::read_file_data(char* file_name)
{
    TwoVecString rows;
    rows = flights_info->read_data(file_name);
    for (int index = 1; index < rows.size(); index++)
    {
        string seat, price;
        Flight_Data new_flight_data;
        for (int i = 0; i < rows[0].size(); i++)
        {  
            if (rows[0][i] == AIRLINE)
                new_flight_data.airline_name = rows[index][i];
            else if (rows[0][i] == ORIGIN)
                new_flight_data.origin = rows[index][i];
            else if (rows[0][i] == DESTINATION)
                new_flight_data.destination = rows[index][i];
            else if (rows[0][i] == DEPARTURE_DATE)
                new_flight_data.departure_date = stoi(rows[index][i]);
            else if (rows[0][i] == ARRIVAL_DATE)
                new_flight_data.arrival_date = stoi(rows[index][i]);
            else if (rows[0][i] == DEPARTURE_TIME)
                new_flight_data.departure_time = string_to_time(rows[index][i]);
            else if (rows[0][i] == ARRIVAL_TIME)
                new_flight_data.arrival_time = string_to_time(rows[index][i]);
            else if (rows[0][i] == COST)
                new_flight_data.base_price = stof(rows[index][i]);
            else if (rows[0][i] == SEATS)
                new_flight_data.economy_seats = stoi(rows[index][i]);
        }
        new_flight_data.id = index;
        Flight *new_flight = new Flight(new_flight_data);
        utravel->add_flights(new_flight, new_flight_data.airline_name);
    }
}

void Main_IO::add_filter_(VecString attributes)
{
    if (find(attributes.begin(), attributes.end(), FROM) != attributes.end())
    {
        string origin_city = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), FROM)) + 1];
        string destination_city = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), TO)) + 1];
        City_Filter *new_filter = new City_Filter(origin_city, destination_city);
        utravel->add_filter(new_filter);
    }
    else if (find(attributes.begin(), attributes.end(), AIRLINE) != attributes.end())
    {
        string airline_name = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), AIRLINE)) + 1];
        Airline_Filter *new_filter = new Airline_Filter(airline_name, NULL_STRING);
        utravel->add_filter(new_filter);
    }
    /*else if (find(attributes.begin(), attributes.end(), MIN_PRICE) != attributes.end())
    {
        string min_price = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), MIN_PRICE)) + 1];
        string max_price = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), MAX_PRICE)) + 1];
        Price_Filter *new_filter = new Price_Filter(min_price, max_price);
        utravel->add_filter(new_filter);
    }*/
}

void Main_IO::handle_post_command()
{
    VecString attributes;
    string command;
    cin >> command;
    try 
    {
        switch(hash_it(command))
        {
            case signup:
                attributes = post_command->signup();
                utravel->signup_(attributes);
                break;
            case login:
                attributes = post_command->login();
                utravel->login_(attributes);
                break;
            case logout:
                utravel->logout_();
                break;
            case wallet:
                attributes = post_command->wallet();
                utravel->wallet_(attributes);
                break;
            /*case tickets:
                attributes = post_command->tickets();
                utravel->tickets_(attributes);
                break;*/
            case filter:
                attributes = post_command->filter();
                add_filter_(attributes);
                break;
            case garbage:
                cout << NOT_FOUND << endl;
                break;
        }
    }
    catch (string error)
    {
        cout << error << endl;
    }
}

void Main_IO::handle_get_command()
{
    VecString attributes;
    string command;
    cin >> command;
    try 
    {
        switch(hash_it(command))
        {
            case flights:
                attributes = get_command->flights();
                get_command->print_flights(utravel->flights_(attributes));
                break;
            /*case tickets:
                attributes = get_command->tickets();
                TicketInfo dalam = utravel->get_tickets(attributes);
                get_command->print_tickets(dalam);
                break;*/
            case garbage:
                cout << NOT_FOUND << endl;
                break;
        }
    }
    catch (string error)
    {
        cout << error << endl;
    }
}

void Main_IO::handle_delete_command()
{
    VecString attributes;
    string command;
    cin >> command;
    try 
    {
        switch(hash_it(command))
        {
            /*case tickets:
                attributes = get_command->tickets();
                TicketInfo dalam = utravel->get_tickets(attributes);
                get_command->print_tickets(dalam);
                break;*/
        }
    }
    catch (string error)
    {
        cout << error << endl;
    }
}

void Main_IO::get_user_command()
{
    string command;
    while(cin >> command)
    {
        switch(hash_it(command))
        {
            case _post_:
                handle_post_command();
                break;
            case _get_:
                handle_get_command();
                break;
            case _delete_:
                handle_delete_command();
                break;
            case garbage:
                cout << BAD_REQUEST << endl;
                break;
        }
    }
}