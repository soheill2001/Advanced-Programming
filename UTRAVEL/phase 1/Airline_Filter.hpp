#ifndef _Airline_Filter_HPP_
#define _Airline_Filter_HPP_

#include "Main_Filter.hpp"

class Airline_Filter : public Main_Filter
{
public:
    Airline_Filter(std::string parameter1, std::string parameter2);
    bool check_flight(Flight_Data flight);
private:

};

#endif