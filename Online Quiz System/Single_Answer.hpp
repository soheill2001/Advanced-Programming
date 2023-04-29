#ifndef _Single_Answer_HPP_
#define _Single_Answer_HPP_

#include "Multiple_Choice.hpp"

class Single_Answer : public Multiple_Choice
{
public:
    Single_Answer(VecChoice options, std::string title, std::string answer, int number);
    bool check_answer();
private:
    bool correct;
};

#endif