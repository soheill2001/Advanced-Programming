#ifndef _I_O_HPP_
#define _I_O_HPP_

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include "Single_Answer.hpp"
#include "Multiple_Answer.hpp"
#include "Short_Answer.hpp"

typedef std::vector<Question*> VecQ;

class I_O
{
public:
    I_O() = default;
    void read_data(char* filename, VecQ *questions);
    void get_answers(VecQ &questions);
    void print_result(VecQ questions, int &correct_answers);
private:
    void short_answer_(std::ifstream *input, VecQ *questions);
    void multiple_choices(std::ifstream *input, VecQ *questions, std::string type);
    std::string reducer(std::string &answer);
};

#endif