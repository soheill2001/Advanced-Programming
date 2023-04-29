#include "Multiple_Choice.hpp"

using namespace std;

Multiple_Choice::Multiple_Choice(VecChoice options, std::string title, std::string answer, int number) : Question(title, answer, number)
{
    choices = options;
}