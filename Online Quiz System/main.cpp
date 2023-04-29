#include "Elearn.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Elearn elearn;
    elearn.read_questions(argv[1]);
    elearn.get_user_answers();
}