#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string PRINTER_ADDED = "printer added successfully";
const string ORDER_ADDED = "order added successfully";
const string REGULAR_ORDERS = "regular orders queue:";
const string FINISHED_TASK = "orders finished:";
const string CURRENT_ORDER = "current order: ";
const string VIP_ORDERS = "VIP orders queue:";
const string NOT_AVAILABLE = "not_available";
const string PASSED_TIME = "passed time: ";
const string ADVANCE_TIME = "advance_time";
const string SHOW_INFO = "show_press_info";
const string PAPER_LEFT = "papers left: ";
const string PRINTER_ID = "printer ID: ";
const string ADD_PRINTER = "add_printer";
const string ADD_ORDER = "add_order";
const string INK_LEFT = "ink left:";
const string PRINTERS = "printers:";
const string REGULAR = "regular";
const string STATUS = "status: ";
const string AVAILABLE = "idle";
const string GREEN = "green: ";
const string BLACK = "black: ";
const string FINISH = "finish";
const string BLUE = "blue: ";
const string BUSY = "busy";
const string RED = "red: ";
const string VIP = "vip";
const string OK = "ok";
const int TIME_TO_FULL_PAPER = 5;
const int TIME_TO_FULL_INK = 10;
const int START_GREEN = 1000;
const int START_BLACK = 1000;
const int START_BLUE = 1000;
const int START_PAPER = 100;
const int START_RED = 1000;
const int START_TIME = 0;
const int EMPTY = 0;

struct Colors
{
    int R_Ink;
    int G_Ink;
    int B_Ink;
    int X_Ink;
} color_default = {START_RED, START_GREEN, START_BLUE, START_BLACK};

//***************** CLASS TIME  *****************//

class Time
{
public:
    Time(int init_timer_ink = START_TIME, int init_timer_paper = START_TIME);
    void set_remain_time(int ink_time, int paper_time);
    int get_ink_timer() { return timer_ink; }
    int get_paper_timer() { return timer_paper; }
private:
    int timer_ink;
    int timer_paper;
};

Time::Time(int init_timer_ink, int init_timer_paper)
{
    timer_ink = init_timer_ink;
    timer_paper = init_timer_paper;
}

void Time::set_remain_time(int ink_time, int paper_time)
{
    timer_ink += ink_time;
    timer_paper += paper_time;
}

//***************** CLASS INK *****************//

class Ink
{
public:
    Ink(Colors color = color_default);
    void set_Red(int Red) { R_ink = Red; }
    void set_Green(int Green) { G_ink = Green; }
    void set_Blue(int Blue) { B_ink = Blue; }
    void set_Black(int Black) { x_ink = Black; }
    int get_Red() { return R_ink; }
    int get_Green() { return G_ink; }
    int get_Blue() { return B_ink; }
    int get_Black() { return x_ink; }
private:
    int R_ink;
    int G_ink;
    int B_ink;
    int x_ink;
};

Ink::Ink(Colors color)
{
    R_ink = color.R_Ink;
    G_ink = color.G_Ink;
    B_ink = color.B_Ink;
    x_ink = color.X_Ink;
}

//***************** CLASS PAPER *****************//

class Paper
{
public:
    void set(int num_paper) { papers_count = num_paper; }
    int get_paper() { return papers_count; }
private:
    int papers_count;
};

//***************** CLASS TASK *****************//

class Task
{
public:
    Task(Ink ink = color_default, int paper = 0, int id = 0, int time_spend = 0);
    Ink ink_info() { return ink_need; }
    Paper paper_info() { return paper_to_print; }
    void set_paper(int num_paper) { paper_to_print.set(num_paper); }
    void inc_time_taken() { time_taken++; }
    int get_id() { return task_id; }
    int get_time_taken() { return time_taken; }
private:
    Paper paper_to_print;
    Ink ink_need;
    int task_id;
    int time_taken;
};

Task::Task(Ink ink, int paper, int id, int time_spend)
{
    paper_to_print.set(paper);
    ink_need = ink;
    task_id = id;
    time_taken = time_spend;
}

typedef vector<Task> VecTask;

//***************** CLASS PRINTER *****************//

class Printer
{
public:
    Printer(int speed, int num_printer);
    string get_status() { return status; }
    Task task_info() { return current_task; }
    void is_available(VecTask &vip, VecTask &regular, VecTask &finished_task);
    void is_not_available(vector<Task> &finished_task);
    void is_busy(vector<Task> &finished_task);
    void show_info();
private:
    void status_update(string current_status) { status = current_status; }
    void change_paper(int paper_can_print, vector<Task> &finished_task);
    void change_ink(int paper_to_can_print);
    void remain_time_setter();
    void charge_storages(vector<Task> &finished_task);
    bool ink_checker(int paper_can_print);
    bool paper_ink_checker(vector<Task> &finished_task);
    string status;
    int pages_per_time;
    int printer_id;
    Ink ink;
    Paper paper;
    Time full_storage_remain_time;
    Task current_task;
};

Printer::Printer(int speed, int num_printer)
{
    status = AVAILABLE;
    pages_per_time = speed;
    printer_id = num_printer;
    paper.set(START_PAPER);
}

void Printer::show_info()
{
    
    cout << endl << PRINTER_ID << printer_id << endl << STATUS << status << endl;
    if (status != AVAILABLE)
    {
        cout << CURRENT_ORDER << current_task.get_id() << " " << current_task.paper_info().get_paper() << endl;
    }
    cout << INK_LEFT << endl << RED << ink.get_Red() << endl << GREEN << ink.get_Green()
         << endl << BLUE << ink.get_Blue() << endl << BLACK << ink.get_Black() << endl
         << PAPER_LEFT << paper.get_paper() << endl;
}

void Printer::change_ink(int paper_can_print)
{
    ink.set_Red(ink.get_Red() - (paper_can_print * current_task.ink_info().get_Red()));
    ink.set_Green(ink.get_Green() - (paper_can_print * current_task.ink_info().get_Green()));
    ink.set_Blue(ink.get_Blue() - (paper_can_print * current_task.ink_info().get_Blue()));
    ink.set_Black(ink.get_Black() - (paper_can_print * current_task.ink_info().get_Black()));
}

bool Printer::ink_checker(int paper_can_print)
{
    if (current_task.ink_info().get_Red() * paper_can_print <= ink.get_Red() &&
        current_task.ink_info().get_Green() * paper_can_print <= ink.get_Green() &&
        current_task.ink_info().get_Blue() * paper_can_print <= ink.get_Blue() &&
        current_task.ink_info().get_Black() * paper_can_print <= ink.get_Black())
        {
            return true;
        }
    else
    {
        return false;
    }
}

void Printer::change_paper(int paper_can_print, vector<Task> &finished_task)
{
    change_ink(paper_can_print);
    paper.set(paper.get_paper() - paper_can_print);
    current_task.set_paper(current_task.paper_info().get_paper() - paper_can_print);
    if (current_task.paper_info().get_paper() == EMPTY)
    {
        finished_task.push_back(current_task);
    }
}

void Printer::is_available(VecTask &vip, VecTask &regular, VecTask &finished_task)
{
    if (vip.size() != 0)
    {
        current_task = vip[0];
        vip.erase(vip.begin());
        status_update(BUSY);
        is_busy(finished_task);
    }
    else if(regular.size() != 0)
    {
        current_task = regular[0];
        regular.erase(regular.begin());
        status_update(BUSY);
        is_busy(finished_task);
    }
    else
    {
        status_update(AVAILABLE);
    }
}

void Printer::charge_storages(vector<Task> &finished_task)
{
    if (full_storage_remain_time.get_ink_timer() == 0 && 
        full_storage_remain_time.get_paper_timer() == 0)
    {

        if (current_task.paper_info().get_paper() == 0)
        {
            status_update(AVAILABLE);
        }
        else
        {
            status_update(BUSY);
            is_busy(finished_task);
        }
    }
}

void Printer::is_not_available(vector<Task> &finished_task)
{
    if (full_storage_remain_time.get_paper_timer() > 0)
    {
        full_storage_remain_time.set_remain_time(0, -1);
        if (full_storage_remain_time.get_paper_timer() == 0)
        {
            paper.set(START_PAPER);
            charge_storages(finished_task);
        }
        
    }
    else if (full_storage_remain_time.get_ink_timer() > 0)
    {
        full_storage_remain_time.set_remain_time(-1, 0);
        if (full_storage_remain_time.get_ink_timer() == 0)
        {
            ink.set_Black(START_BLACK); ink.set_Blue(START_BLUE);
            ink.set_Green(START_GREEN); ink.set_Red(START_RED);
            charge_storages(finished_task);
        }
        
    }
}

void Printer::remain_time_setter()
{
    if (pages_per_time > paper.get_paper())
    {
        full_storage_remain_time.set_remain_time(EMPTY, TIME_TO_FULL_PAPER);
    }
    else if(!ink_checker(pages_per_time))
    {
        full_storage_remain_time.set_remain_time(TIME_TO_FULL_INK, EMPTY);
    }
}

bool Printer::paper_ink_checker(vector<Task> &finished_task)
{
    if (pages_per_time > paper.get_paper() || !ink_checker(pages_per_time))
    {
        if (current_task.paper_info().get_paper() <= paper.get_paper() && 
            ink_checker(current_task.paper_info().get_paper()))
        {
            change_paper(current_task.paper_info().get_paper(), finished_task);
        }
        else
        {
            status_update(NOT_AVAILABLE);
            remain_time_setter();
        }
        return false;
    }
    else
    {
        return true;
    }
}

void Printer::is_busy(vector<Task> &finished_task)
{
    current_task.inc_time_taken();
    if (paper_ink_checker(finished_task))
    {
        if (pages_per_time > current_task.paper_info().get_paper())
        {
            change_paper(current_task.paper_info().get_paper(), finished_task);
        }
        else
        {
            change_paper(pages_per_time, finished_task);
        }
    }
}

typedef vector<Printer> VecPri;

//***************** CLASS PRINTING_HOUSE *****************//

class Printing_House
{
public:
    Printing_House() { all_time_taken = 0; task_counter = 0; }
    void add_printer(int printer_speed);
    void add_order(Colors color, int num_of_pages, string type);
    void advance_time(int time_step);
    void show_press_info();
    void finish();
    int get_all_time_taken() { return all_time_taken; }
private:
    void set_time_taken(int time_step) { all_time_taken += time_step; }
    VecPri printers;
    VecTask regular_tasks;
    VecTask vip_tasks;
    VecTask finished_task;
    int all_time_taken;
    int task_counter;
};

void Printing_House::add_printer(int printer_speed)
{
    Printer new_printer(printer_speed, printers.size() + 1);
    printers.push_back(new_printer);
}

void Printing_House::add_order(Colors color, int num_of_pages, string type)
{
    task_counter++;
    Ink task_ink(color);
    Task new_task(task_ink, num_of_pages, task_counter);
    if (type == VIP)
    {
        vip_tasks.push_back(new_task);
    }
    else
    {
        regular_tasks.push_back(new_task);
    }
}

void Printing_House::advance_time(int time_step)
{
    set_time_taken(time_step);
    for (int j = 0; j < time_step; j++)
    {
        for (int i = 0; i < printers.size(); i++)
        {
            if (printers[i].get_status() == AVAILABLE || 
               (printers[i].get_status() == BUSY && 
                printers[i].task_info().paper_info().get_paper() == 0))
            {
                printers[i].is_available(vip_tasks, regular_tasks, finished_task);
            }
            else if (printers[i].get_status() == NOT_AVAILABLE)
            {
                printers[i].is_not_available(finished_task);
            }
            else if (printers[i].get_status() == BUSY)
            {
                printers[i].is_busy(finished_task);
            }
        }
    }
}

void Printing_House::show_press_info()
{
    cout << PASSED_TIME << all_time_taken << endl;
    cout << VIP_ORDERS << endl;
    for (int i = 0; i < vip_tasks.size(); i++)
    {
        cout << vip_tasks[i].get_id() << " " << vip_tasks[i].paper_info().get_paper() << endl;
    }
    cout << endl << REGULAR_ORDERS << endl;
    for (int i = 0; i < regular_tasks.size(); i++)
    {
        cout << regular_tasks[i].get_id() << " " << regular_tasks[i].paper_info().get_paper() << endl;
    }
    cout << endl << PRINTERS;
    for (int i = 0; i < printers.size(); i++)
    {
        printers[i].show_info();
    }
    cout <<  endl << FINISHED_TASK << endl;
    for (int i = 0; i < finished_task.size(); i++)
    {
        cout << finished_task[i].get_id() << " " << finished_task[i].get_time_taken() << endl;
    }
    cout << endl;
}

void Printing_House::finish()
{
    while (finished_task.size() != task_counter)
    {
        set_time_taken(1);
        for (int i = 0; i < printers.size(); i++)
        {
            if (printers[i].get_status() == AVAILABLE || 
               (printers[i].get_status() == BUSY && 
                printers[i].task_info().paper_info().get_paper() == 0))
            {
                printers[i].is_available(vip_tasks, regular_tasks, finished_task);
            }
            else if (printers[i].get_status() == NOT_AVAILABLE)
            {
                printers[i].is_not_available(finished_task);
            }
            else if (printers[i].get_status() == BUSY)
            {
                printers[i].is_busy(finished_task);
            }
        }
    }
    cout << get_all_time_taken() << endl;
}

//***************** END_OF_CLASSES *****************//

enum string_convert
{
    add_printer,
    add_order,
    advance_time,
    show_press_info,
    finish
};

string_convert hashit(string command)
{
    if (command == ADD_PRINTER) return add_printer;
    if (command == ADD_ORDER) return add_order;
    if (command == ADVANCE_TIME) return advance_time;
    if (command == SHOW_INFO) return show_press_info;
    if (command == FINISH) return finish;
}

void adding_printer(Printing_House &printing_house)
{
    string speed_printer;
    cin >> speed_printer;
    printing_house.add_printer(stoi(speed_printer));
    cout << PRINTER_ADDED << endl;
}

void adding_order(Printing_House &printing_house)
{
    Colors colors;
    string red, green, blue, black, num_pages, type_;
    cin >> red >> green >> blue >> black >> num_pages >> type_;
    colors.R_Ink = stoi(red); colors.G_Ink = stoi(green);
    colors.B_Ink = stoi(blue); colors.X_Ink = stoi(black);
    printing_house.add_order(colors, stoi(num_pages), type_);
    cout << ORDER_ADDED << endl;
}

void forward_time(Printing_House &printing_house)
{
    string time_step;
    cin >> time_step;
    cout << OK << endl;
    printing_house.advance_time(stoi(time_step));
}

void do_command(Printing_House &printing_house)
{
    string command;
    while(cin >> command)
    {
        switch (hashit(command))
        {
            case add_printer:
                adding_printer(printing_house);
                break;
            case add_order:
                adding_order(printing_house);
                break;
            case advance_time:
                forward_time(printing_house);
                break;
            case show_press_info:
                printing_house.show_press_info();
                break;
           case finish:
                printing_house.finish();
                break;
        }
    }
}

int main()
{
    Printing_House printing_house;
    do_command(printing_house);
}