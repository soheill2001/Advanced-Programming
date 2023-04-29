#include "City_Filter.hpp"

using namespace std;

City_Filter::City_Filter(string parameter1, string parameter2) : Main_Filter(parameter1, parameter2)
{}

bool City_Filter::check_flight(Flight_Data flight)
{
    if (flight.origin == get_first_parameter() && flight.destination == get_second_parameter())
        return true;
    else 
        return false;
}