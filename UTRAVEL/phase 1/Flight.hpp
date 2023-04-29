#ifndef _Flight_HPP_
#define _Flight_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Defines.hpp"
#include "Flight_Data.hpp"

class Flight
{
public:
    Flight(Flight_Data new_flight_info);
    Flight_Data get_fight_data() { return flight_data; }
    void buy_seat(int quantity, std::string seat_class);
    void print();
private:
    Flight_Data flight_data;
};

#endif