#ifndef _Multiple_Answer_HPP_
#define _Multiple_Answer_HPP_

#include "Multiple_Choice.hpp"

class Multiple_Answer : public Multiple_Choice
{
public:
    Multiple_Answer(VecChoice options, std::string title, std::string answer, int number);
    bool check_answer();
private:
    bool correct;
};

#endif