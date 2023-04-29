#include "Price_Filter.hpp"

using namespace std;

Price_Filter::Price_Filter(string parameter1, string parameter2) : Main_Filter(parameter1, parameter2)
{}

bool Price_Filter::check_flight(Flight_Data flight)
{
    if (get_first_parameter().size() != 0 && get_second_parameter().size() != 0)
        if (flight.base_price >= stof(get_first_parameter()) && flight.base_price <= stof(get_second_parameter()))
            return true;
    else if (get_first_parameter().size() != 0)
        if (flight.base_price >= stof(get_first_parameter()))
            return true;
    else if (get_second_parameter().size() != 0)
        if (flight.base_price <= stof(get_second_parameter()))
            return true;
    return false;
}