#include "Multiple_Answer.hpp"

using namespace std;

Multiple_Answer::Multiple_Answer(VecChoice options, string title, string answer, int number) : Multiple_Choice(options, title, answer, number)
{
    
}

bool Multiple_Answer::check_answer()
{
    string correct_answer, student_answer;
    correct_answer = get_correct_answer();
    student_answer = get_student_answer();
    for (int i = 0; i < student_answer.size(); i++)
    {
        if (correct_answer.find(student_answer[i]) == string::npos)
        {
            correct = false;
            return false;
        }
        correct = true;
    }
    return true;
}