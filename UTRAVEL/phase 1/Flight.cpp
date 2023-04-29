#include "Flight.hpp"

using namespace std;

Flight::Flight(/*City city_info, Time time_info, Date date_info, int seat_info, float price, int flight_id*/Flight_Data new_flight_info)
{
    flight_data = new_flight_info;
    flight_data.business_seats = BUSINESS_PERCENTAGE * new_flight_info.economy_seats;
    flight_data.economy_seats = ECONOMY_PERCENTAGE * new_flight_info.economy_seats;
    /*city_travel = city_info;
    time_travel = time_info;
    flight_date = date_info;
    seats = seat_info;
    base_price = price;
    id = flight_id;*/
}

void Flight::buy_seat(int quantity, string seat_class)
{
    if (seat_class == ECONOMY)
        flight_data.economy_seats -= quantity;
    else
        flight_data.business_seats -= quantity;
}

void Flight::print()
{
    cout << flight_data.id << " " << flight_data.base_price << " " << flight_data.destination << " " << flight_data.departure_date << endl;
}