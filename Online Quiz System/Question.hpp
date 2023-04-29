#ifndef _Question_HPP_
#define _Question_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Define.hpp"

class Question
{
public:
    Question(std::string title, std::string answer, int number);
    void set_student_answer(std::string answer);
    virtual bool check_answer() = 0;
    std::string get_correct_answer() { return correct_answer; }
    std::string get_student_answer() { return student_answer; }
private:
    int Question_number;
    std::string question_title;
    std::string correct_answer;
    std::string student_answer;
};

#endif