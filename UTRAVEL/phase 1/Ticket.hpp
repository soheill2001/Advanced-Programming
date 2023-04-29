#ifndef _Ticket_HPP_
#define _Ticket_HPP_

#include <iostream>
#include <string>
#include "Defines.hpp"

using namespace std;

struct Ticket
{
    int ticket_id;
    int flight_id;
    int quantity;
    float cost;
    bool economy;
    bool refundable;
    Ticket(pair<int, int> flight_info, pair<string, string> ticket_info, pair<float, int> third)
    {
        flight_id = third.second;
        ticket_id = flight_info.first;
        quantity = flight_info.second;
        if (ticket_info.first == ECONOMY)
            economy = true;
        else
            economy = false;
        if (ticket_info.second == REFUNDABLE)
            refundable = true;
        else
            refundable = false;
        cost = third.first;
    }
};

#endif