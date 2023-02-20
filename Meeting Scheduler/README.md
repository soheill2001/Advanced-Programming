# Meeting Scheduler

This is a C++ program that helps to schedule meetings among participants who can attend at different time slots. The program takes as input the number of time slots available and the list of participants along with their availability. It then suggests the best time slot(s) for the meeting, based on the participants' availability.

## Usage
When you run the program, it will ask you to enter the number of time slots available for the meeting. After that, you need to enter the names of the participants who will attend the meeting. You can enter as many names as you want, one name per line. When you are done entering the names, press Enter.

After entering the names of the participants, the program will ask you to enter the availability of each participant for each time slot.

### Input Format
The input format for the code is as follows:
```
<time_slots_count>
<participant1> <participant2> ...
<participant>:<time_slot_id> <status>|...
```

After entering the availability of all the participants, the program will suggest the best time slot(s) for the meeting, based on the participants' availability.

### Output Format
The output format for the code is as follows:
```
Time slot <time_slot_id>:
YES: <participants...>
NO: <participants...>
IF_NECESSARY: <participants...>
###
```

## Example
### Input
```
2
Alice Bob Charlie
Alice:1 YES|Bob:1 NO|Charlie:1 IF_NECESSARY
Alice:2 IF_NECESSARY|Bob:2 YES|Charlie:2 YES
```
### Output
```
Time slot 1:
YES: Alice
NO: Bob
IF_NECESSARY: Charlie
###
Time slot 2:
YES: Bob Charlie
IF_NECESSARY: Alice
###
```

