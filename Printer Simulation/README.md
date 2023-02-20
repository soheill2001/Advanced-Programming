# Printer Simulation

This is a C++ program that simulates a printer and a printing queue. Users can add printers and print tasks to the system. The program automatically assigns tasks to available printers based on priority, which is determined by whether the task is a VIP order or a regular order. The program also keeps track of ink and paper levels and warns users when they are running low.

## Usage
### Adding Printers
To add a printer to the system, use the command `add_printer`. The program will prompt you to enter the printing speed.
#### Input
```
add_printer <printer_speed>
```
#### Output
```
printer added successfully.
```


### Adding Print Tasks
To add a print task to the system, use the command `add_order`. The program will prompt you to enter the order's type (VIP or regular), number of pages, and color.
#### Input
```
add_order <r> <g> <b> <x> <num_of_pages> <regular|vip>
```
#### Output
```
order added successfully
```


### Showing Printer Status
To show the status of all printers in the system, use the command `show_press_info`.
#### Input
```
show_press_info 
```
#### Output
```
passed time: <time of simulation>
VIP orders queue:
<first order id> <num_of_papers>
...
regular orders queue:
<first order id> <num_of_papers>
...
printers:
printer ID: <first printer>
status: <busy|idle|not_available>
current order: <order id> <amount of papers needed for
completing current order>
ink left:
red: <red ink left for the first printer>
green: <green ink left for the first printer
```

### Advancing Time
To advance the time by a certain number of seconds, use the command `advance_time`.
#### Input
```
advance_time <time_steps>
```
#### Output
```
ok
```

### Finishing all Tasks
To finish all tasks, use the command `finish`.
#### Input
```
finish
```
#### Output
```
<time required to finish the orders from the beginning of the day>

```

## Functionality
### Printing Queue
The program maintains a queue of print tasks, which are assigned to printers as they become available. Tasks are assigned based on priority, with VIP orders taking precedence over regular orders.

### Ink and Paper Levels
The program keeps track of ink and paper levels for each printer. When the ink or paper levels run low, the program warns the user and stops assigning tasks to that printer until the levels are replenished.

### Printer Status
The program shows the status of each printer, indicating whether it is available to take on a task or currently busy printing a task.

### Time Management
The program keeps track of the amount of time it takes to print each task and the amount of time remaining for the ink and paper levels. The user can advance the time by a certain number of seconds using the `advance_time` command.


