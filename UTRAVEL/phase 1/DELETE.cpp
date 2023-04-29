#include "DELETE.hpp"

using namespace std;

VecString delete_::delete_ticket()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    check_attributes_size(attributes.size(), DELETE_TICKET_ATTRIBUTE);
    return attributes;
}