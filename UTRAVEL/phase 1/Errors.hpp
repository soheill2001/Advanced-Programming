#ifndef _ERRORS_HPP_
#define _ERRORS_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include "User.hpp"
#include "Defines.hpp"
#include "Airline.hpp"

typedef std::vector<User> VecUser;
typedef std::vector<std::string> VecString;
typedef std::vector<Airline> VecAirlines;

class Error_Handle
{
public:
    void signup_errors(VecString attributes, VecUser *users);
    void login_errors(VecString attributes, VecUser *users);
    void wallet_errors(VecString attributes);
    void ticket_errors(std::pair<Flight_Data, std::string> flight, std::pair<int, float> user_request, User *user);
    void flight_errors(VecAirlines *airlines, int flight_id);
    void filter_errors();
private:
};

#endif