#ifndef _Flights_Info_HPP_
#define _Flights_Info_HPP_

#include "I_O.hpp"

typedef std::vector<std::vector<std::string>> TwoVecString;

class Flights_Info : public I_O
{
public:
    Flights_Info();
    TwoVecString read_data(char* file_name);
private:
    //void new_flight_info(std::vector<std::vector<std::string>> rows, VecAirlines *airlines);
    void line_divider(std::string attributes, std::vector<std::string> *row);
    //void add_airline_flight(VecAirlines *airlines, Flight *new_flight, std::string airline_name);
    //int string_to_time(std::string new_time);
};

#endif