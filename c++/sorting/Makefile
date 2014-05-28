OBJ = DynamicArray.o file.o sort.o
CPPFLAGS = -O3

all: $(OBJ)
	g++ -Wall -Werror $(CPPFLAGS) $(OBJ) -o proj

sort.o: file.h sort.cpp 
	g++ $(CPPFLAGS) -c sort.cpp  -o sort.o

file.o: file.h file.cpp
	g++ $(CPPFLAGS) -c file.cpp -o file.o

DynamicArray.o: DynamicArray.h DynamicArray.cpp 
	g++ $(CPPFLAGS) -c DynamicArray.cpp -o DynamicArray.o


clean:
	rm -rf $(OBJ)  proj
