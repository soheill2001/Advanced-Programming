#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void print_result(int index, vector<vector<string>> votes, string vote)
{
    cout << vote << ":";
    for (int i = 0; i < votes.size(); i++)
    {
        if (votes[i][index + 1] == vote)
        {
            cout << " " << votes[i][0];
        }
    }
    cout << endl;
    if (vote == "NO" || vote == "IF_NECESSARY")
    {
        return;
    }
    print_result(index, votes, "NO");
    print_result(index, votes, "IF_NECESSARY");
}

vector<int> find_indices_with_common_value(vector<int> vote_to_count, int min){
    vector<int> indices;
    for (int i = 0; i < vote_to_count.size(); i++)
    {
        if (min == vote_to_count[i])
        {
            indices.push_back(i);
        }
    }
    return indices;
}

void disable_selected_slot(vector<int> indices, vector<int> &no_count, vector<vector<string>> votes)
{
    int max = *max_element(no_count.begin(), no_count.end());
    no_count[indices[0]] = max + 1;
    cout << "Time slot " << indices[0] << ":" << endl;
    print_result(indices[0], votes, "YES");
}

void find_best_slot(vector<int> &no_count, vector<int> &if_count, vector<vector<string>> votes)
{
    int min = *min_element(no_count.begin(), no_count.end());
    vector<int> indices = find_indices_with_common_value(no_count, min), temp;
    if (indices.size() > 1)
    {
        for (int i = 0; i < indices.size(); i++)
        {
            temp.push_back(if_count[indices[i]]);
        }
        min = *min_element(temp.begin(), temp.end());
        indices = find_indices_with_common_value(if_count, min);
        disable_selected_slot(indices, no_count, votes);
    }
    else
    {
        disable_selected_slot(indices, no_count, votes);
    }
}

vector<int> vote_counter(vector<vector<string>> votes, vector<int> counter, string name)
{
    for (int i = 1; i < votes[0].size(); i++)
    {
        int count = 0;
        for (int j = 0; j < votes.size(); j++)
        {
            if (votes[j][i] == name)
            {
                count++;
            }
        }
        counter.push_back(count);
    }
    return counter;
}

void repeat_result(pair<vector<int>, vector<int>> vote_counters, vector<vector<string>> votes, int size)
{
    for (int i = 0; i < size; i++)
    {
        find_best_slot(vote_counters.first, vote_counters.second, votes);
        cout << "###" << endl;
    }
}

void final_result(vector<vector<string>> votes, int size)
{
    vector<int> no_count, if_count;
    no_count = vote_counter(votes, no_count, "NO");
    if_count = vote_counter(votes, if_count, "IF_NECESSARY");
    pair<vector<int>, vector<int>> vectors[] = {{no_count, if_count}};
    if (size > 3)
    {
        repeat_result(*vectors, votes, 3);
    }
    else
    {
        repeat_result(*vectors, votes, size);
    }
}

int find_user_index(vector<vector<string>> votes, string name)
{
    for (int i = 0; i < votes.size(); i++)
    {
        if (votes[i][0] == name)
        {
            return i;
        }
    }
    return -1;
}

void register_votes(vector<string> &votes, string vote, int from){
    if (from == vote.size())
    {
        return;
    }
    int vertical_line_index = vote.find("|", from + 1);
    int space_index = vote.find(" ", from);
    int slot_index = stoi(vote.substr(from + 1, space_index)) + 1;
    votes[slot_index] = vote.substr(space_index + 1, vertical_line_index - space_index - 1);
    register_votes(votes, vote, space_index + votes[slot_index].size() + 1);
}

void extract_voter_name(string vote, vector<vector<string>> &votes)
{
    int colon_index, user_index;
    string name;
    colon_index = vote.find(":");
    name = vote.substr(0, colon_index);
    user_index = find_user_index(votes, name);
    if (user_index == -1)
    {
        return;
    }
    register_votes(votes[user_index], vote, colon_index);
}

vector<vector<string>> get_votes(vector<vector<string>> votes)
{
    string vote;
    while (getline(cin,vote))
    {
        extract_voter_name(vote, votes);
    }
    return votes;
}

vector<vector<string>> adding_names_to_votes_vector(vector<string> names, vector<vector<string>> votes)
{
    for (int i = 0; i < names.size(); i++)
    {
        votes[i][0] = names[i];
    }
    return votes;
}

vector<string> get_participant_names(vector<string> names)
{
    string name;
    while (cin >> name)
    {
        if (cin.peek() == '\n')
        {
            break;
        }
        names.push_back(name);
    }
    names.push_back(name);
    getline(cin, name);
    return names;
}

int main()
{
    int time_slot_count;
    cin >> time_slot_count;
    vector<string> participants_name;
    participants_name = get_participant_names(participants_name);
    vector<vector<string>> votes(participants_name.size(), vector<string> (time_slot_count + 1, "IF_NECESSARY"));
    votes = adding_names_to_votes_vector(participants_name, votes);
    votes = get_votes(votes);
    final_result(votes, time_slot_count);
}
