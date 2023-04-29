#ifndef _POST_HPP_
#define _POST_HPP_

#include <algorithm>
//#include <regex>
#include "User_Input.hpp"

typedef std::vector<std::string> VecString;

class post_ : public User_Input
{
public:
    post_();
    VecString signup();
    VecString login();
    VecString logout();
    VecString wallet();
    //VecString tickets();
    VecString filter();
private:
    City_Filter city(VecString attributes);
};

#endif