#ifndef _User_HPP_
#define _User_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Ticket.hpp"
#include "Defines.hpp"

typedef std::vector<Ticket> VecTicket;
typedef std::pair<VecTicket, bool> VecCheckTicket;

class User
{
public:
    User(std::string user_name, std::string user_pass, int id);
    bool check_username(std::string user);
    bool check_password(std::string pass);
    bool check_money(float money);
    int get_user_id() { return user_id; }
    void increase_money(float money);
    void buy_ticket(std::pair<int, int> flight_info, std::pair<std::string, std::string> ticket_info, std::pair<float, int> third);
    VecCheckTicket get_user_tickets(int ticket_id);
    float get_money() { return cash; }
private:
    int user_id;
    float cash;
    VecTicket user_tickets;
    std::string username;
    std::string password;
};

#endif