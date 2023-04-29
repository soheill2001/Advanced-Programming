CC := g++ -std=c++11
EXE_FILE=utravel.out
BUILD_DIR=build


$(EXE_FILE): ${BUILD_DIR}/main.o ${BUILD_DIR}/Flight.o ${BUILD_DIR}/Airline.o ${BUILD_DIR}/User.o ${BUILD_DIR}/Utravel.o ${BUILD_DIR}/Airline_Filter.o ${BUILD_DIR}/Main_Filter.o ${BUILD_DIR}/City_Filter.o ${BUILD_DIR}/Errors.o ${BUILD_DIR}/Flights_Info.o ${BUILD_DIR}/User_Input.o ${BUILD_DIR}/GET.o ${BUILD_DIR}/POST.o ${BUILD_DIR}/DELETE.o ${BUILD_DIR}/Main_IO.o
	$(CC) ${BUILD_DIR}/main.o ${BUILD_DIR}/Flight.o ${BUILD_DIR}/Airline.o ${BUILD_DIR}/User.o ${BUILD_DIR}/Utravel.o ${BUILD_DIR}/Airline_Filter.o ${BUILD_DIR}/Main_Filter.o ${BUILD_DIR}/City_Filter.o ${BUILD_DIR}/Errors.o ${BUILD_DIR}/Flights_Info.o ${BUILD_DIR}/User_Input.o ${BUILD_DIR}/GET.o ${BUILD_DIR}/POST.o ${BUILD_DIR}/DELETE.o ${BUILD_DIR}/Main_IO.o -o $(EXE_FILE)

${BUILD_DIR}/main.o: main.cpp Utravel.hpp Main_IO.hpp
	$(CC) -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Flight.o: Flight.cpp Flight.hpp Defines.hpp Flights_Info.hpp
	$(CC) -c Flight.cpp -o ${BUILD_DIR}/Flight.o

${BUILD_DIR}/Airline.o: Airline.cpp Airline.hpp Flight.hpp
	$(CC) -c Airline.cpp -o ${BUILD_DIR}/Airline.o

${BUILD_DIR}/User.o: User.cpp User.hpp Ticket.hpp Defines.hpp
	$(CC) -c User.cpp -o ${BUILD_DIR}/User.o

${BUILD_DIR}/Utravel.o: Utravel.cpp Utravel.hpp Airline.hpp User.hpp Errors.hpp Main_Filter.hpp
	$(CC) -c Utravel.cpp -o ${BUILD_DIR}/Utravel.o

${BUILD_DIR}/Flights_Info.o: Flights_Info.cpp Flights_Info.hpp I_O.hpp
	$(CC) -c Flights_Info.cpp -o ${BUILD_DIR}/Flights_Info.o

${BUILD_DIR}/User_Input.o: User_Input.cpp User_Input.hpp I_O.hpp
	$(CC) -c User_Input.cpp -o ${BUILD_DIR}/User_Input.o

${BUILD_DIR}/GET.o: GET.cpp GET.hpp User_Input.hpp
	$(CC) -c GET.cpp -o ${BUILD_DIR}/GET.o

${BUILD_DIR}/POST.o: POST.cpp POST.hpp User_Input.hpp
	$(CC) -c POST.cpp -o ${BUILD_DIR}/POST.o

${BUILD_DIR}/DELETE.o: DELETE.cpp DELETE.hpp User_Input.hpp
	$(CC) -c DELETE.cpp -o ${BUILD_DIR}/DELETE.o

${BUILD_DIR}/Main_IO.o: Main_IO.cpp Main_IO.hpp GET.hpp POST.hpp DELETE.hpp Flights_Info.hpp Main_Filter.hpp
	$(CC) -c Main_IO.cpp -o ${BUILD_DIR}/Main_IO.o

${BUILD_DIR}/Errors.o: Errors.cpp Errors.hpp User.hpp Defines.hpp Airline.hpp
	$(CC) -c Errors.cpp -o ${BUILD_DIR}/Errors.o

${BUILD_DIR}/Main_Filter.o: Main_Filter.cpp Main_Filter.hpp Flight_Data.hpp
	$(CC) -c Main_Filter.cpp -o ${BUILD_DIR}/Main_Filter.o

${BUILD_DIR}/City_Filter.o: City_Filter.cpp City_Filter.hpp Main_Filter.hpp
	$(CC) -c City_Filter.cpp -o ${BUILD_DIR}/City_Filter.o

${BUILD_DIR}/Airline_Filter.o: Airline_Filter.cpp Airline_Filter.hpp Main_Filter.hpp
	$(CC) -c Airline_Filter.cpp -o ${BUILD_DIR}/Airline_Filter.o

clean:
	rm -rf build/ && mkdir -p build