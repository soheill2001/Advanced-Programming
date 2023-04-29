#ifndef _Airline_HPP_
#define _Airline_HPP_

#include "Flight.hpp"

typedef std::vector<Flight> VecFlight;

class Airline
{
public:
    Airline(std::string name);
    void add_flight(Flight new_flight);
    VecFlight get_flights() { return airline_flight; }
    std::string get_airline_name() { return airline_name; }
    bool find_flight(int id);
    void print();
private:
    std::string airline_name;
    VecFlight airline_flight;
};

#endif