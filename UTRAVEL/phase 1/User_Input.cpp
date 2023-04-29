#include "User_Input.hpp"

using namespace std;

void User_Input::line_divider(string command, vector<string> *attributes)
{
    if (command.size() != 0)
    {
        command.erase(command.begin());
        while (command.length() > 0)
        {
            int space_index = command.find(SPACE_SEPERATOR);
            if (space_index == -1)
            {
                attributes->push_back(command);
                command.erase();
            }
            else
            {
                string word = command.substr(0, space_index);
                command.erase(0, space_index + 1);
                attributes->push_back(word);
            }
        }
    }
}

void User_Input::check_attributes_size(int attribute_size, int check_amount)
{
    if (attribute_size != check_amount)
        throw BAD_REQUEST;
}