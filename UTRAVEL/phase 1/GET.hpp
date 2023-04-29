#ifndef _GET_HPP_
#define _GET_HPP_

#include "User_Input.hpp"

class get_ : public User_Input
{
public:
    get_();
    VecString flights();
    //VecString tickets();
    void print_flights(VecOfFlights _flights_);
    //void print_tickets(TicketInfo _tickets_);
private:
    //void check_attributes_size(int attribute_size, int check_amount);
    //void flights_error(int flights_number, int user_login_id);
};

#endif