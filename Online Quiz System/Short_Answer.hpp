#ifndef _Short_Answer_HPP_
#define _Short_Answer_HPP_

#include "Question.hpp"

class Short_Answer : public Question
{
public:
    Short_Answer(std::string title, std::string answer, int number);
    bool check_answer();
private:
    bool correct;
};

#endif