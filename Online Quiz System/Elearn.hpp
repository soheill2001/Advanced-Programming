#ifndef _Elearn_HPP_
#define _Elearn_HPP_

#include <vector>
#include "Single_Answer.hpp"
#include "Multiple_Answer.hpp"
#include "Short_Answer.hpp"
#include "I_O.hpp"

typedef std::vector<Question*> VecQ;

class Elearn
{
public:
    Elearn() = default;
    //void add_new_question(Question new_q);
    void read_questions(char* filename);
    void get_user_answers();
private:
    void calculate_score();
    int correct_answers;
    VecQ questions;
    I_O *input_output;
};

#endif