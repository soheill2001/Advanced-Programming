#ifndef _Multiple_Choice_HPP_
#define _Multiple_Choice_HPP_

#include "Question.hpp"

typedef std::vector<std::string> VecChoice;

class Multiple_Choice : public Question
{
public:
    Multiple_Choice(VecChoice options, std::string title, std::string answer, int number);
private:
    VecChoice choices;
};

#endif