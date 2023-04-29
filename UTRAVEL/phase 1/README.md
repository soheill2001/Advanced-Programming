# PHASE 1

This phase provides a variety of commands to help users manage their account, browse available flights, apply filters, and purchase tickets.

## Commands
### Signup
```
POST signup ? username <username> password <password>
```
Allows users to create a new account by providing their username and password.
### Login
```
POST login ? username <username> password <password>
```
Allows users to log in to their existing account by providing their username and password.
### Logout
Logs the user out of their account.
### Wallet
```
POST wallet ? amount <amount> 
```
Allows users to deposit money into their account's wallet, where they can use it to purchase tickets. The `<amount>` parameter should be a positive integer representing the amount of money to be deposited.
### Flights
```
GET flights
```
Displays a list of available flights, along with their flight ID, airline, origin, destination, departure date, departure time, arrival date, arrival time, available seats, and cost.
### Flight Information by ID
```
GET flights ? id <id>
```
### Filters
```
POST filters ? from <city> to <city>
```
```
POST filters ? min_price <min_price> max_price <max_price>
```
```
POST filters ? airline <airline> 
```
```
POST filters ? departure_date <departure_date> min_departure_time <min_departure_time> max_departure_time <max_departure_time>
```
Allows users to apply filters to the list of available flights. Users can filter by origin, destination, price range, airline, and departure time range. Filters can be combined by using multiple options. If no filters are specified, all available flights will be displayed.
### Tickets
```
POST tickets ? flight <flight_id> quantity <quantity> class <class> type <type>
```
Allows users to purchase tickets for a specific flight. The `<flight_id>` parameter should be the ID of the flight that the user wants to purchase tickets for. The `<quantity>` parameter should be the number of tickets to purchase. The `<class>` parameter should be the class of the ticket (e.g., economy, business, first class). The `<type>` parameter should be the type of ticket (e.g., one-way, round-trip).
