OBJ = DynamicArray.o file.o p3.o
CPPFLAGS = -O3

all: $(OBJ)
	g++ -Wall -Werror $(CPPFLAGS) $(OBJ) -o proj3

p3.o: file.h p3.cpp 
	g++ $(CPPFLAGS) -c p3.cpp  -o p3.o

file.o: file.h file.cpp
	g++ $(CPPFLAGS) -c file.cpp -o file.o

DynamicArray.o: DynamicArray.h DynamicArray.cpp 
	g++ $(CPPFLAGS) -c DynamicArray.cpp -o DynamicArray.o


clean:
	rm -rf $(OBJ)  proj3
