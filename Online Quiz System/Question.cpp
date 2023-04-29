#include "Question.hpp"

using namespace std;

Question::Question(string title, string answer, int number)
{
    question_title = title;
    correct_answer = answer;
    Question_number = number;
    student_answer = NOT_ANSWERED;
}

void Question::set_student_answer(string answer)
{
    student_answer = answer;
}