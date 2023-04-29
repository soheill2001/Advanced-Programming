#include "Utravel.hpp"
#include "Main_IO.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Utravel travel;
    Main_IO IO(&travel);
    IO.read_file_data(argv[1]);
    IO.get_user_command();
    //travel.read_flights_data(argv[1]);
    
    
    //travel.get_user_command();
    //travel.print();
}