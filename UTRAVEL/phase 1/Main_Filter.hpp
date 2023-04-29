#ifndef _Main_Filter_HPP_
#define _Main_Filter_HPP_

#include <string>
#include "Flight_Data.hpp"

class Main_Filter
{
public:
    Main_Filter(std::string parameter1, std::string parameter2);
    std::string get_first_parameter() { return first_parameter; }
    std::string get_second_parameter() { return second_parameter; }
    virtual bool check_flight(Flight_Data flight) = 0;
private:
    std::string first_parameter;
    std::string second_parameter;
};

#endif
