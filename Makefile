CXX=g++  
CXXFLAGS=-g -fsanitize=address -std=c++20 -I include/

all: main

main: ladder.o 
	$(CXX)  src/ladder_main.cpp -o main src/ladder.o $(CXXFLAGS)

ladder.o: src/ladder.cpp 
	$(CXX)  -c $< -o src/ladder.o $(CXXFLAGS)

clean:
	rm src/*.o main