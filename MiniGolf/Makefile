CC := g++ -std=c++14
CCFLAGS += -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
EXE_FILE=minigolf.out
BUILD_DIR=build

$(EXE_FILE): ${BUILD_DIR}/main.o ${BUILD_DIR}/Game_Loop.o ${BUILD_DIR}/rsdl.o ${BUILD_DIR}/Golf.o ${BUILD_DIR}/Grass.o ${BUILD_DIR}/Water.o ${BUILD_DIR}/Sand.o ${BUILD_DIR}/Ball.o ${BUILD_DIR}/Final.o ${BUILD_DIR}/Wall.o ${BUILD_DIR}/Moving_Wall.o
	$(CC) ${BUILD_DIR}/main.o ${BUILD_DIR}/rsdl.o ${BUILD_DIR}/Game_Loop.o ${BUILD_DIR}/Golf.o ${BUILD_DIR}/Grass.o ${BUILD_DIR}/Water.o ${BUILD_DIR}/Sand.o ${BUILD_DIR}/Ball.o ${BUILD_DIR}/Final.o ${BUILD_DIR}/Wall.o ${BUILD_DIR}/Moving_Wall.o $(CCFLAGS) -o $(EXE_FILE)

${BUILD_DIR}/main.o: main.cpp Game_Loop.hpp Golf.hpp
	$(CC) -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/rsdl.o: RSDL/src/rsdl.hpp RSDL/src/rsdl.cpp
	$(CC) -c RSDL/src/rsdl.cpp -o ${BUILD_DIR}/rsdl.o

${BUILD_DIR}/Game_Loop.o: Game_Loop.cpp Game_Loop.hpp Golf.hpp RSDL/src/rsdl.hpp
	$(CC) -c Game_Loop.cpp -o ${BUILD_DIR}/Game_Loop.o

${BUILD_DIR}/Golf.o: Golf.cpp Golf.hpp Final_Area.hpp Ball.hpp
	$(CC) -c Golf.cpp -o ${BUILD_DIR}/Golf.o

${BUILD_DIR}/Grass.o: Grass_Area.cpp Grass_Area.hpp Defines.hpp RSDL/src/rsdl.hpp
	$(CC) -c Grass_Area.cpp -o ${BUILD_DIR}/Grass.o

${BUILD_DIR}/Water.o: Water_Area.cpp Water_Area.hpp RSDL/src/rsdl.hpp
	$(CC) -c Water_Area.cpp -o ${BUILD_DIR}/Water.o

${BUILD_DIR}/Sand.o: Sand_Area.cpp Sand_Area.hpp Defines.hpp RSDL/src/rsdl.hpp
	$(CC) -c Sand_Area.cpp -o ${BUILD_DIR}/Sand.o

${BUILD_DIR}/Final.o: Final_Area.cpp Final_Area.hpp Grass_Area.hpp Water_Area.hpp Sand_Area.hpp Defines.hpp RSDL/src/rsdl.hpp Wall.hpp Moving_Wall.hpp Ball.hpp
	$(CC) -c Final_Area.cpp -o ${BUILD_DIR}/Final.o

${BUILD_DIR}/Ball.o: Ball.cpp Ball.hpp RSDL/src/rsdl.hpp Defines.hpp Final_Area.hpp
	$(CC) -c Ball.cpp -o ${BUILD_DIR}/Ball.o

${BUILD_DIR}/Wall.o: Wall.cpp Wall.hpp RSDL/src/rsdl.hpp Defines.hpp
	$(CC) -c Wall.cpp -o ${BUILD_DIR}/Wall.o

${BUILD_DIR}/Moving_Wall.o: Moving_Wall.cpp Moving_Wall.hpp RSDL/src/rsdl.hpp Defines.hpp
	$(CC) -c Moving_Wall.cpp -o ${BUILD_DIR}/Moving_Wall.o

clean:
	rm -rf build/ && mkdir -p build