#ifndef _Utravel_HPP_
#define _Utravel_HPP_

#include <algorithm>
#include <utility>
#include "User.hpp"
#include "Errors.hpp"
#include "Airline.hpp"
#include "Main_Filter.hpp"

typedef std::vector<Airline> VecAirlines;
typedef std::vector<User> VecUser;
typedef std::vector<std::string> VecString;
typedef std::vector<std::vector<std::string>> TwoVecString;
typedef std::vector<Flight_Data> VecOfFlights;
typedef std::pair<VecTicket, VecOfFlights> TicketInfo;
typedef std::vector<Main_Filter*> Filters;

class Utravel
{
public:
    Utravel();
    void add_flights(Flight *new_flight, std::string airline_name);
    void signup_(VecString attributes);
    void login_(VecString attributes);
    void logout_();
    void wallet_(VecString attributes);
    //void tickets_(VecString attributes);
    VecOfFlights flights_(VecString attributes);
    //TicketInfo get_tickets(VecString attributes);
    //void delete_ticket(VecString attributes);
    void add_filter(Main_Filter *new_filter);
private:
    VecUser users;
    VecAirlines airlines;
    VecOfFlights all_flights;
    Error_Handle *error_handle;
    int user_login_id;
    int tickets_sell;
    void check_user_login(bool condition);
    Flight find_flight(int flight_id);
    Filters filters;
    VecOfFlights apply_filter();
};

#endif