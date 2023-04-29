#include "Single_Answer.hpp"

using namespace std;

Single_Answer::Single_Answer(VecChoice options, string title, string answer, int number) : Multiple_Choice(options, title, answer, number) 
{}

bool Single_Answer::check_answer()
{
    if (get_correct_answer() == get_student_answer())
        correct = true;
    else
        correct = false;
    return correct;
}