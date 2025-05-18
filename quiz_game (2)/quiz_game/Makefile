CXX = g++
CXXFLAGS = -std=c++17

all: quiz_game

quiz_game: main.o quiz.o utils.o
	$(CXX) -o quiz_game main.o quiz.o utils.o

main.o: main.cpp quiz.h
	$(CXX) $(CXXFLAGS) -c main.cpp

quiz.o: quiz.cpp quiz.h utils.h
	$(CXX) $(CXXFLAGS) -c quiz.cpp

utils.o: utils.cpp utils.h
	$(CXX) $(CXXFLAGS) -c utils.cpp

clean:
	rm -f *.o quiz_game