#include "Short_Answer.hpp"

using namespace std;

Short_Answer::Short_Answer(string title, string answer, int number) : Question(title, answer, number) 
{
    correct = "no_answer";
}

bool Short_Answer::check_answer()
{
    if (get_correct_answer() == get_student_answer())
        correct = true;
    else
        correct = false;
    return correct;
}