#include "POST.hpp"

using namespace std;

VecString post_::signup()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    check_attributes_size(attributes.size(), SIGNUP_LOGIN_ATTRIBUTES);
    return attributes;
}

VecString post_::login()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    check_attributes_size(attributes.size(), SIGNUP_LOGIN_ATTRIBUTES);
    return attributes;
}

VecString post_::wallet()
{
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    check_attributes_size(attributes.size(), WALLET_ATTRIBUTES);
    return attributes;
}

/*VecString post_::tickets()
{
    VecString attributes;
    string command;
    for (int i = 0; i < 9; i++)
    {
        cin >> command;
        attributes.push_back(command);
    }
    check_attributes_size(attributes.size(), TICKETS_ATTRIBUTES);
    return attributes;
}*/

City_Filter post_::city(VecString attributes)
{
    string origin_city = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), FROM)) + 1];
    string destination_city = attributes[distance(attributes.begin(), find(attributes.begin(), attributes.end(), TO)) + 1];
    City_Filter *new_city_filter = new City_Filter(origin_city, destination_city);
    return *new_city_filter;
}

VecString post_::filter()
{
    
    VecString attributes;
    string command;
    getline(cin, command);
    line_divider(command, &attributes);
    return attributes;
}