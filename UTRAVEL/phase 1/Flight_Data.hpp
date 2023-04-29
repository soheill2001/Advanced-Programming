#ifndef _Flight_Data_HPP_
#define _Flight_Data_HPP_

#include <string>

struct Flight_Data
{
    int departure_date;
    int arrival_date;
    int departure_time;
    int arrival_time;
    int economy_seats;
    int business_seats;
    int id;
    float base_price;
    std::string origin;
    std::string destination;
    std::string airline_name;
};

#endif