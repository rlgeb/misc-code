OBJ = Waitress.o MenuItem.o Cake.o Coffee.o NoOrder.o MakeCakeOrder.o MakeCoffeeOrder.o Customer.o
CPPFLAGS = -O3

all: $(OBJ)
	g++ -Wall -Werror $(CPPFLAGS) $(OBJ) -o proj

Waitress.o: Waitress.cpp
	g++ $(CPPFLAGS) -c Waitress.cpp -o Waitress.o

MenuItem.o: MenuItem.cpp
	g++ $(CPPFLAGS) -c MenuItem.cpp -o MenuItem.o

Cake.o: Cake.h Cake.cpp
	g++ $(CPPFLAGS) -c Cake.cpp -o Cake.o

Coffee.o: Coffee.h Coffee.cpp
	g++ $(CPPFLAGS) -c Coffee.cpp -o Coffee.o

NoOrder.o: Order.h NoOrder.h NoOrder.cpp
	g++ $(CPPFLAGS) -c NoOrder.cpp -o NoOrder.o

MakeCakeOrder.o: Order.h MakeCakeOrder.h MakeCakeOrder.cpp
	g++ $(CPPFLAGS) -c MakeCakeOrder.cpp -o MakeCakeOrder.o

MakeCoffeeCommand.o: Order.h MakeCoffeOrder.h MakeCoffeOrder.cpp
	g++ $(CPPFLAGS) -c MakeCakeOrder.cpp -o MakeCakeOrder.o

Customer.o: Customer.cpp
	g++ $(CPPFLAGS) -c Customer.cpp -o Customer.o

clean:
	rm -rf $(OBJ)  proj
