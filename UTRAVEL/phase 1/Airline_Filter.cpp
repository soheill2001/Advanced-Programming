#include "Airline_Filter.hpp"

using namespace std;

Airline_Filter::Airline_Filter(string parameter1, string parameter2) : Main_Filter(parameter1, parameter2)
{}

bool Airline_Filter::check_flight(Flight_Data flight)
{
    if (flight.airline_name == get_first_parameter())
        return true;
    else 
        return false;
}