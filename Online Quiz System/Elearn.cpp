#include "Elearn.hpp"

using namespace std;

void Elearn::calculate_score()
{
    correct_answers = 0;
    input_output->print_result(questions, correct_answers);

}

void Elearn::read_questions(char* filename)
{
    input_output->read_data(filename, &questions);
}

void Elearn::get_user_answers()
{
    input_output->get_answers(questions);
    calculate_score();
}