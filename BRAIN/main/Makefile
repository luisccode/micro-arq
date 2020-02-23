CXX = g++
FLAGS = -I../include/
OBJ = main.o  Brain.o Entidad.o 
SRC = ../src/

test: $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) $(FLAGS) $^ -c


Brain.o: $(SRC)Brain.cpp
	$(CXX) $(FLAGS) $^ -c

Entidad.o: $(SRC)Entidad.cpp
	$(CXX) $(FLAGS) $^ -c

clean:
	rm -rf *.o test