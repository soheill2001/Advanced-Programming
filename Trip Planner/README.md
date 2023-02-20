# Trip Planner

This program helps users plan a day trip by suggesting a sequence of places to visit based on their opening and closing times and how much time they would like to spend at each place. The program takes a CSV file as input, with each row representing a place to visit, and outputs a list of the places to visit in order, along with the arrival and departure times.

## Usage
The program takes a CSV file as input, with each row representing a place to visit. The file should have the following format:
```
name,openingTime,closingTime,rank
```
Here is an example CSV file:
```
name,openingTime,closingTime,rank
Statue of Liberty,09:00,17:00,3
Empire State Building,10:00,22:00,2
Central Park,06:00,23:00,1

```

To run the program, execute the following command in the terminal:

```
./trip_planner [path/to/csv/file.csv] [duration]
```

For example, to plan a trip with a duration of 480 minutes (8 hours) using the example CSV file above, you would run the following command:

```
./trip_planner places.csv 480
```

The program will output a list of the places to visit in order, along with the arrival and departure times:

```
Location Central Park
visit from 06:00 until 07:00
---
Location Empire State Building
visit from 07:30 until 09:30
---
Location Statue of Liberty
visit from 10:00 until 12:00
```