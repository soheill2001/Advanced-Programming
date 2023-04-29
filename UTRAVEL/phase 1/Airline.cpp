#include "Airline.hpp"

using namespace std;

Airline::Airline(string name)
{
    airline_name = name;
}

void Airline::add_flight(Flight new_flight)
{
    airline_flight.push_back(new_flight);
}

void Airline::print()
{
    cout << airline_name << endl;
    for (int i = 0; i < airline_flight.size(); i++)
        airline_flight[i].print();
}

bool Airline::find_flight(int flight_id)
{
    for (int i = 0; i < airline_flight.size(); i++)
        if (airline_flight[i].get_fight_data().id == flight_id)
            return true;
    return false;
}