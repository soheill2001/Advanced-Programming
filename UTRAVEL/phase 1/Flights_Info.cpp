#include "Flights_Info.hpp"

using namespace std;

enum string_convert
{
    airline,
    origin,
    destination,
    departure_date,
    departure_time,
    arrival_date,
    arrival_time,
    seats,
    cost
};

string_convert hashit_(string command)
{
    if (command == AIRLINE) return airline;
    if (command == ORIGIN) return origin;
    if (command == DESTINATION) return destination;
    if (command == DEPARTURE_DATE) return departure_date;
    if (command == DEPARTURE_TIME) return departure_time;
    if (command == ARRIVAL_DATE) return arrival_date;
    if (command == ARRIVAL_TIME) return arrival_time;
    if (command == SEATS) return seats;
    if (command == COST) return cost;
}

/*int Flights_Info::string_to_time(string new_time)
{
    int hour = (new_time[0] - STRING_TO_INT) * 10 + (new_time[1] - STRING_TO_INT);
    int min = (new_time[3] - STRING_TO_INT) * 10 + (new_time[4] - STRING_TO_INT);
    return (hour * ONE_HOUR_AS_MIN + min);
}

void Flights_Info::add_airline_flight(VecAirlines *airlines, Flight *new_flight, string airline_name)
{
    bool condition = false;
    for (int i = 0; i < airlines->size(); i++)
    {
        if ((*airlines)[i].get_airline_name() == airline_name)
        {
            (*airlines)[i].add_flight(*new_flight);
            condition= true;
            break;
        }
    }
    if (!condition)
    {
        Airline *new_airline = new Airline(airline_name);
        new_airline->add_flight(*new_flight);
        airlines->push_back(*new_airline);
    }
}

void Flights_Info::new_flight_info(vector<vector<string>> rows, VecAirlines *airlines)
{
    for (int index = 1; index < rows.size(); index++)
    {
        string airline_name, seat, price;
        Flight_Data new_flight_data;
        for (int i = 0; i < rows[0].size(); i++)
        {   
            switch(hashit_(rows[0][i]))
            {
                case airline:
                    airline_name = rows[index][i];
                    break;
                case origin:
                    new_flight_data.origin = rows[index][i];
                    break;
                case destination:
                    new_flight_data.destination = rows[index][i];
                    break;
                case departure_date:
                    new_flight_data.departure_date = stoi(rows[index][i]);
                    break;
                case arrival_date:
                    new_flight_data.arrival_date = stoi(rows[index][i]);
                    break;
                case departure_time:
                    new_flight_data.departure_time = string_to_time(rows[index][i]);
                    break;
                case arrival_time:
                    new_flight_data.arrival_time = string_to_time(rows[index][i]);
                    break;
                case cost:
                    new_flight_data.base_price = stof(rows[index][i]);
                    break;
                case seats:
                    new_flight_data.economy_seats = stoi(rows[index][i]);
                    break;
            }
        }
        new_flight_data.id = index;
        Flight *new_flight = new Flight(new_flight_data);
        add_airline_flight(airlines, new_flight, airline_name);
    }
}*/

void Flights_Info::line_divider(string attributes, vector<string> *row)
{
    while (attributes.length() > 0)
    {
        int comma_index = attributes.find(COMMA_SEPERATOR);
        if (comma_index == -1)
        {
            row->push_back(attributes);
            attributes.erase();
        }
        else
        {
            string word = attributes.substr(0, comma_index);
            attributes.erase(0, comma_index + 1);
            row->push_back(word);
        }
    }
}

TwoVecString Flights_Info::read_data(char* file_name)
{
    TwoVecString rows{};
    ifstream input(file_name);
    string attributes;
    int index = 0;
    while (getline(input, attributes))
    {
        rows.push_back({});
        line_divider(attributes, &rows[index]);
        index ++;
    }
    return rows;
    //new_flight_info(rows, airlines);
}