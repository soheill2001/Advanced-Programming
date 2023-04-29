#include "I_O.hpp"

using namespace std;

enum string_convert
{
    single_answer,
    multiple_answer,
    short_answer
};

string_convert hashit(string question_type)
{
    if (question_type == SINGLE_ANSWER) return single_answer;
    if (question_type == MULTIPLE_ANSWER) return multiple_answer;
    if (question_type == SHORT_ANSWER) return short_answer;
}

void I_O::multiple_choices(ifstream *input, VecQ *questions, string type)
{
    string question_title; string choices; 
    string choice; string correct_answer;
    getline(*input, question_title);
    getline(*input, choices);
    vector<string> options;
    for (int i = 0; i < stoi(choices); i++)
    {
        getline(*input, choice);
        options.push_back(choice);
    }
    getline(*input, correct_answer);
    if (type == SINGLE_ANSWER)
    {
        Single_Answer* new_question = new Single_Answer(options, question_title, correct_answer, questions->size() + 1);
        questions->push_back(new_question);
    }
    else
    {
        Multiple_Answer* new_question = new Multiple_Answer(options, question_title, correct_answer, questions->size() + 1);
        questions->push_back(new_question);
    }
    getline(*input, choice);
}

void I_O::short_answer_(ifstream *input, VecQ *questions)
{
    string question_title; string correct_answer;
    getline(*input, question_title);
    getline(*input, correct_answer);
    Short_Answer* new_question = new Short_Answer(question_title, correct_answer, questions->size() + 1);
    questions->push_back(new_question);
    getline(*input, correct_answer);
}

void I_O::read_data(char* filename, VecQ *questions)
{
    ifstream input(filename);
    string line;
    while(getline(input, line))
    {
        switch(hashit(line))
        {
            case single_answer:
                multiple_choices(&input, questions, SINGLE_ANSWER);
                break;
            case multiple_answer:
                multiple_choices(&input, questions, MULTIPLE_ANSWER);
                break;
            case short_answer:
                short_answer_(&input, questions);
                break;
        }
    }
}

string I_O::reducer(string &answer)
{
    string new_answer = answer.substr(0, answer.find(SPACE));
    answer.erase(answer.begin(), answer.begin() + answer.find(SPACE) + 1);
    return new_answer;
}

void I_O::get_answers(VecQ &questions)
{
    for (int i = 0; i < questions.size(); i++)
    {
        string command, question_number, answer;
        getline(cin, answer);
        command = reducer(answer);
        question_number = reducer(answer);
        if (command == FINISH_EXAM) 
            break;
        questions[stoi(question_number) - 1]->set_student_answer(answer);
        if (questions[stoi(question_number) - 1]->check_answer())
            cout << CORRECT << endl;
        else
            cout << WRONG << endl;
    }
}

void I_O::print_result(VecQ questions, int &correct_answers)
{
    for (int i = 0; i < questions.size(); i++){
        if (questions[i]->get_student_answer() == NOT_ANSWERED)
            cout << i + 1 << NO_ANSWER << SEPERATOR << CORRECT_ANSWER << questions[i]->get_correct_answer() << endl;
        else if (questions[i]->check_answer())
        {
            correct_answers++;
            cout << i + 1 << CORRECT_ << endl;
        }
        else
            cout << i + 1 << WRONG_ANSWER << SEPERATOR << CORRECT_ANSWER << questions[i]->get_correct_answer() 
            <<  COMMA << YOUR_ANSWER << questions[i]->get_student_answer() << endl;
    }
    cout << setprecision(GRADE_PRECISION) << fixed << FINAL_GRADE << float(correct_answers) / float(questions.size()) * DARSAD << endl;
}