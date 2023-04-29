#ifndef _I_O_HPP_
#define _I_O_HPP_

#include "Airline.hpp"
#include "User.hpp"
#include "Utravel.hpp"
#include "City_Filter.hpp"
#include "Airline_Filter.hpp"
#include "Price_Filter.hpp"

typedef std::vector<User> VecUser;
typedef std::vector<Airline> VecAirlines;

class I_O
{
public:
    I_O();
    virtual void line_divider() = 0;
private:
    
};

#endif