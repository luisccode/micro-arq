CXX = g++
FLAGS = -I../include/
OBJ = main.o  Brain.o Entity.o functions.o
SRC = ../src/

test: $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(FLAGS) $^ -c


Brain.o: $(SRC)Brain.cpp
	$(CXX) $(FLAGS) $^ -c

Entity.o: $(SRC)Entity.cpp
	$(CXX) $(FLAGS) $^ -c

functions.o: $(SRC)functions.cpp
	$(CXX) $(FLAGS) $^ -c

clean:
	rm -rf *.o test