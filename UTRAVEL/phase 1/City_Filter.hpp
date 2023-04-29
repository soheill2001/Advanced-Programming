#ifndef _City_Filter_HPP_
#define _City_Filter_HPP_

#include <iostream>
#include "Main_Filter.hpp"

class City_Filter : public Main_Filter
{
public:
    City_Filter(std::string parameter1, std::string parameter2);
    bool check_flight(Flight_Data flight);
private:

};

#endif