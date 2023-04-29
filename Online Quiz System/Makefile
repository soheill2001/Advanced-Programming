CC := g++ -std=c++11
EXE_FILE=quizMaker
BUILD_DIR=build

$(EXE_FILE): ${BUILD_DIR}/main.o ${BUILD_DIR}/Question.o ${BUILD_DIR}/Short_Answer.o ${BUILD_DIR}/I_O.o ${BUILD_DIR}/Elearn.o ${BUILD_DIR}/Multiple_Choice.o ${BUILD_DIR}/Multiple_Answer.o ${BUILD_DIR}/Single_Answer.o
	$(CC) ${BUILD_DIR}/main.o ${BUILD_DIR}/Question.o ${BUILD_DIR}/Short_Answer.o ${BUILD_DIR}/I_O.o ${BUILD_DIR}/Multiple_Choice.o ${BUILD_DIR}/Multiple_Answer.o ${BUILD_DIR}/Single_Answer.o ${BUILD_DIR}/Elearn.o -o $(EXE_FILE)

${BUILD_DIR}/main.o: main.cpp Elearn.hpp
	$(CC) -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Question.o: Question.cpp Question.hpp Define.hpp
	$(CC) -c Question.cpp -o ${BUILD_DIR}/Question.o

${BUILD_DIR}/Short_Answer.o: Short_Answer.cpp Short_Answer.hpp Question.hpp
	$(CC) -c Short_Answer.cpp -o ${BUILD_DIR}/Short_Answer.o

${BUILD_DIR}/I_O.o: I_O.cpp I_O.hpp Multiple_Answer.hpp Short_Answer.hpp Single_Answer.hpp
	$(CC) -c I_O.cpp -o ${BUILD_DIR}/I_O.o

${BUILD_DIR}/Elearn.o: Elearn.cpp Elearn.hpp Multiple_Answer.hpp Short_Answer.hpp Single_Answer.hpp I_O.hpp
	$(CC) -c Elearn.cpp -o ${BUILD_DIR}/Elearn.o

${BUILD_DIR}/Multiple_Choice.o: Multiple_Choice.cpp Multiple_Choice.hpp Question.hpp
	$(CC) -c Multiple_Choice.cpp -o ${BUILD_DIR}/Multiple_Choice.o

${BUILD_DIR}/Single_Answer.o: Single_Answer.cpp Single_Answer.hpp Multiple_Choice.hpp
	$(CC) -c Single_Answer.cpp -o ${BUILD_DIR}/Single_Answer.o

${BUILD_DIR}/Multiple_Answer.o: Multiple_Answer.cpp Multiple_Answer.hpp Multiple_Choice.hpp
	$(CC) -c Multiple_Answer.cpp -o ${BUILD_DIR}/Multiple_Answer.o

clean:
	rm -rf $(EXE_FILE) build/ && mkdir -p build