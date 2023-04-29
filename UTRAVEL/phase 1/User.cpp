#include "User.hpp"

using namespace std;

User::User(string user_name, string user_pass, int id)
{
    username = user_name;
    password = user_pass;
    user_id = id;
    cash = 0;
}

bool User::check_username(string user)
{
    if (username == user)
        return true;
    else
        return false;
}

bool User::check_password(string pass)
{
    if (password == pass)
        return true;
    else
        return false;
}

void User::increase_money(float money)
{
    cash += money;
}

bool User::check_money(float money)
{
    if (cash >= money)
        return true;
    else
        return false;
}

void User::buy_ticket(pair<int, int> flight_info, pair<string, string> ticket_info, pair<float, int> third)
{
    /*Ticket *new_ticket = new Ticket;
    new_ticket->flight_id = third.second;
    new_ticket->ticket_id = flight_info.first;
    new_ticket->quantity = flight_info.second;
    if (ticket_info.first == ECONOMY)
        new_ticket->economy = true;
    else
        new_ticket->economy = false;
    if (ticket_info.second == REFUNDABLE)
        new_ticket->refundable = true;
    else
        new_ticket->refundable = false;
    new_ticket->cost = third.first;
    user_tickets.push_back(*new_ticket);
    cash -= third.first;*/
    //VecTicket dalam = user_tickets;
    Ticket new_ticket(flight_info, ticket_info, third);
    //cout << new_ticket.cost << endl << new_ticket.quantity << endl;
    //dalam.push_back(new_ticket);
    //user_tickets = dalam;
    //cout << "antar" << endl;
    user_tickets.push_back(new_ticket);
    /*Ticket new_buy_ticket;
    new_buy_ticket.flight_id = third.second;
    new_buy_ticket.ticket_id = flight_info.first;
    new_buy_ticket.quantity = flight_info.second;
    if (ticket_info.first == ECONOMY)
        new_buy_ticket.economy = true;
    else
        new_buy_ticket.economy = false;
    if (ticket_info.second == REFUNDABLE)
        new_buy_ticket.refundable = true;
    else
        new_buy_ticket.refundable = false;
    new_buy_ticket.cost = third.first;
    user_tickets.push_back(new_buy_ticket);
    cash -= third.first;*/
}

VecCheckTicket User::get_user_tickets(int ticket_id)
{
    if (ticket_id != 0)
        for (int i = 0; i < user_tickets.size(); i++)
            if (user_tickets[i].ticket_id == ticket_id)
                return {VecTicket {user_tickets[i]}, true};
    else
        return {user_tickets, true};
    return {{}, false};
}