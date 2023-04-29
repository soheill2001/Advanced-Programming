#include "GET.hpp"

using namespace std;

VecString get_::flights()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    if (attributes.size() > 0)
        check_attributes_size(attributes.size(), FLIGHT_ATTRIBUTE_ID);
    else
        check_attributes_size(attributes.size(), FLIGHT_ATTRIBUTE);
    return attributes;
}

void get_::print_flights(VecOfFlights _flights_)
{
    for (int i = 0; i < _flights_.size(); i++)
    {
        Flight_Data current_flight = _flights_[i];
        cout << current_flight.id << " " << current_flight.airline_name << " " << current_flight.origin << " " <<
            current_flight.destination << " " << current_flight.departure_time << " " << current_flight.arrival_date << 
                " " << current_flight.arrival_time << " " << current_flight.economy_seats + current_flight.business_seats <<
                    " " << current_flight.base_price << endl;
    }
}

/*VecString get_::tickets()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    if (attributes.size() > 0)
        check_attributes_size(attributes.size(), TICKET_ATTRIBUTE_ID);
    else
        check_attributes_size(attributes.size(), TICKET_ATTRIBUTE);
    return attributes;
}*/

Flight_Data find_flight(int flight_id, VecOfFlights flights)
{
    for (int i = 0; i < flights.size(); i++)
        if (flights[i].id == flight_id)
            return flights[i];
}

/*void get_::print_tickets(TicketInfo _tickets_)
{
    cout << _tickets_.first.size() << endl;
    for (int i = 0; i < _tickets_.first.size(); i++)
    {
        Ticket current_ticket = _tickets_.first[i];
        Flight_Data current_flight = find_flight(current_ticket.flight_id, _tickets_.second);
        string flight_class = ECONOMY, ticket_type = REFUNDABLE;
        cout << current_flight.airline_name << endl;
        if (!current_ticket.economy)
            flight_class = BUSINESS;
        if (!current_ticket.refundable)
            ticket_type = NONREFUNDABLE;
        cout << current_ticket.ticket_id << " " << current_ticket.flight_id << current_flight.airline_name << " " << 
            current_ticket.quantity << " " << current_flight.origin << " " << current_flight.destination << " " << 
                current_flight.departure_date << " " << current_flight.departure_time << " " << current_flight.arrival_date << " " << 
                    current_flight.arrival_time << " " <<  flight_class << " " << ticket_type << current_ticket.cost << endl;
    }
}*/