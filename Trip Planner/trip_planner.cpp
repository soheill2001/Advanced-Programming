#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string PLACE_NAME = "name";
const string OPEN_TIME = "openingTime";
const string CLOSE_TIME = "closingTime";
const string COMMA_SEPERATOR = ",";
const string LOCATION_TO_VISIT_DIVIDER = "---";
const int DURATION_BETWEEN_PLACES = 30;
const int MAX_TIME_TO_STAY = 60;
const int MIN_TIME_TO_STAY = 15;
const int ONE_HOUR_AS_MIN = 60;
const int STRING_TO_INT = 48;
const char* HOUR_MIN_FORMAT = "%H:%M";

struct visit
{
    string name;
    string arrive;
    string left;
};

struct place
{
    string name;
    string open_time;
    string close_time;
    string rank;
};

struct visit_time
{
    int opening_time;
    int closing_time;
    int arriving_time;
};

void swap(vector<place> &places, int index)
{
    place temp;
    for (int j = 0; j < index; j++)
    {
        for (int i = 0; i < index; i++)
        {
            temp = places[i];
            if (stoi(places[i].rank) > stoi(places[i + 1].rank))
            {
                places[i] = places[i + 1];
                places[i + 1] = temp;
            }
        }
    }
}

int string_to_time(string visit_time)
{
    int hour = (visit_time[0] - STRING_TO_INT) * 10 + (visit_time[1] - STRING_TO_INT);
    int min = (visit_time[3] - STRING_TO_INT) * 10 + (visit_time[4] - STRING_TO_INT);
    return (hour * ONE_HOUR_AS_MIN + min);
}

string time_display(string time_of_place)
{
    int min = stoi(time_of_place) % ONE_HOUR_AS_MIN;
    int hour = stoi(time_of_place) / ONE_HOUR_AS_MIN;
    string hour_to_display = to_string(hour), min_to_display = to_string(min);
    if (to_string(hour).length() == 1)
    {
        hour_to_display = "0" + to_string(hour);
    }
    if (to_string(min).length() == 1)
    {
        min_to_display = "0" + to_string(min);
    }
    return hour_to_display + ":" + min_to_display;
}

void print_result(vector<visit> visit_plan)
{
    for (int i = 0; i < visit_plan.size(); i++)
    {
        cout << "Location " << visit_plan[i].name << endl
                << "visit from " << time_display(visit_plan[i].arrive)
                    << " until " << time_display(visit_plan[i].left) << endl
                        << LOCATION_TO_VISIT_DIVIDER << endl;
    }
}

struct visit can_go(visit visited, place places, struct visit_time &times)
{
    visited.name = places.name;
    visited.arrive = to_string(times.arriving_time);
    if (times.closing_time - times.arriving_time >= MAX_TIME_TO_STAY)
    {
        times.arriving_time += MAX_TIME_TO_STAY;
        visited.left = to_string(times.arriving_time);
    }
    else
    {
        times.arriving_time += times.closing_time - times.arriving_time;
        visited.left = to_string(times.arriving_time);
    }
    times.arriving_time += DURATION_BETWEEN_PLACES;
    return visited;
}

vector<visit> goal_checker(vector<place> places, vector<visit> visit_plan)
{
    struct visit visited;
    struct visit_time times;
    times.arriving_time = string_to_time(places[0].open_time);
    for (int i = 0; i < places.size(); i++)
    {
        if (string_to_time(places[i].open_time) >= times.arriving_time + DURATION_BETWEEN_PLACES || string_to_time(places[i].open_time) >= times.arriving_time)
        {
            times.arriving_time = string_to_time(places[i].open_time);
        }
        times.opening_time = string_to_time(places[i].open_time);
        times.closing_time = string_to_time(places[i].close_time);
        if (times.closing_time - times.arriving_time >= MIN_TIME_TO_STAY && times.arriving_time >= times.opening_time)
        {
            visited = can_go(visited, places[i], times);
            visit_plan.push_back(visited);
        }
    }
    return visit_plan;
}

vector<place> sorting_place_by_rank(vector<place> places)
{
    int index = 0;
    for (int i = 0; i < places.size(); i++)
    {
        for (int j = index; j < places.size(); j++)
        {
            if (places[index].open_time == places[index + 1].open_time)
            {
                index++;
            }
        }
        swap(places, index);
    }
    return places;
}

vector<place> sorting_place_by_opening_hour(vector<place> places)
{
    vector<place> sorted;
    int size = places.size();
    for (int j = 0; j < size; j++)
    {
        int min = 0;
        for (int i = 0; i < places.size() - 1; i++)
        {
            int open_time_1 = string_to_time(places[min].open_time);
            int open_time_2 = string_to_time(places[i + 1].open_time);
            if (open_time_1 - open_time_2 >= 0)
            {
                min = i + 1;
            }
        }
        sorted.push_back(places[min]);
        places.erase(remove_if(places.begin(), places.end(), [&](place const& new_place){return new_place.name == sorted[sorted.size() - 1].name;}), places.end());
    }
    return sorted;
}

vector<visit> find_best_visit_plan(vector<place> places)
{
    vector<place> sorted_place = sorting_place_by_opening_hour(places);
    sorted_place = sorting_place_by_rank(sorted_place);
    vector<visit> visit_plan;
    visit_plan = goal_checker(sorted_place, visit_plan);
    return visit_plan;
}

struct place what_to_add(string word, string attribute, struct place new_place)
{
    if (attribute == PLACE_NAME)
    {
        new_place.name = word;
    }
    else if (attribute == OPEN_TIME)
    {
        new_place.open_time = word;
    }
    else if (attribute == CLOSE_TIME)
    {
        new_place.close_time = word;
    }
    else
    {
        new_place.rank = word;
    }
    return new_place;
}

vector<place> saving_places_data(vector<vector<string>> rows, vector<place> data)
{
    int index = 1;
    while (index < rows.size())
    {
        place new_place;
        for (int i = 0; i < rows[0].size(); i++)
        {
            string attribute = rows[0][i];
            string word = rows[index][i];
            new_place = what_to_add(word, attribute, new_place);
        }
        index++;
        data.push_back(new_place);
    }
    return data;
}

vector<string> line_divider(string attributes, vector<string> row)
{
    while (attributes.length() > 0)
    {
        string word;
        int comma_index = attributes.find(COMMA_SEPERATOR);
        if (comma_index == -1)
        {
            row.push_back(attributes);
            attributes.erase();
        }
        else
        {
            word = attributes.substr(0, comma_index);
            attributes.erase(0, comma_index + 1);
            row.push_back(word);
        }
    }
    return row;
}

vector<place> read_from_file(char* file_name)
{
    vector<vector<string>> rows{};
    vector<place> data;
    ifstream input(file_name);
    string attributes;
    int index = 0;
    while (getline(input, attributes))
    {
        rows.push_back({});
        rows[index] = line_divider(attributes, rows[index]);
        index ++;
    }
    data = saving_places_data(rows, data);
    return data;
}

int main(int argc, char* argv[])
{
    vector<place> places = read_from_file(argv[1]);
    vector<visit> visit_plan = find_best_visit_plan(places);
    print_result(visit_plan);
}