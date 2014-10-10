/** Client Class **/

#include <iostream>
#include "Waitress.cpp"
#include "Cake.h"
#include "MakeCakeOrder.h"
#include "Coffee.h"
#include "MakeCoffeeOrder.h"

using namespace std;

class Customer {
 public:
 	Customer() {
 		
 	}

    void createOrder() {
    	Waitress waitress = Waitress();

        Coffee coffee = Coffee();
        Order* makeCoffeeOrder = new MakeCoffeeOrder(coffee);

    	Cake cake = Cake();
    	Order* makeCakeOrder = new MakeCakeOrder(cake);

    	waitress.takeOrder(makeCoffeeOrder);
    	waitress.takeOrder(makeCakeOrder);

    	waitress.orderUp(0);
        waitress.orderUp(1);

    }

};


/* Run a demo */
int main(int argc, char* argv[]) {
	cout<<"Starting the Bakery Command Pattern Demo\n";
    Customer becca = Customer();
    becca.createOrder();

	return 0;
}