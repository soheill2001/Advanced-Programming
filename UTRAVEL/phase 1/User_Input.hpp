#ifndef _User_Input_HPP_
#define _User_Input_HPP_

#include "I_O.hpp"

class User_Input : public I_O
{
public:
    User_Input();
    void line_divider(std::string attributes, VecString *row);
    void check_attributes_size(int attribute_size, int check_amount);
};

#endif