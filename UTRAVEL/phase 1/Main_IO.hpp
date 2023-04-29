#ifndef _Main_IO_HPP_
#define _Main_IO_HPP_

#include <iostream>
#include "GET.hpp"
#include "POST.hpp"
#include "DELETE.hpp"
#include "Flights_Info.hpp"
#include "Main_Filter.hpp"

typedef std::vector<std::string> VecString;

class Main_IO
{
public:
    Main_IO(Utravel *new_utravel);
    void read_file_data(char* file_name);
    void get_user_command();
private:
    void handle_post_command();
    void handle_get_command();
    void handle_delete_command();
    int string_to_time(std::string new_time);
    void add_filter_(VecString attributes);
    get_ *get_command;
    post_ *post_command;
    delete_ *delete_command;
    Flights_Info *flights_info;
    Utravel *utravel;
};

#endif