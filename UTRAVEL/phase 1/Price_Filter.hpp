#ifndef _Price_Filter_HPP_
#define _Price_Filter_HPP_

#include "Main_Filter.hpp"

class Price_Filter : public Main_Filter
{
public:
    Price_Filter(std::string parameter1, std::string parameter2);
    bool check_flight(Flight_Data flight);
private:

};

#endif