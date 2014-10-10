/** MakeCoffeeOrder Implimentation **/
#include "MakeCoffeeOrder.h"
#include "Coffee.h"
#include <iostream>

 MakeCoffeeOrder::MakeCoffeeOrder(Coffee coffee) {
	this->coffee = coffee;
}

void MakeCoffeeOrder::exe() {
	cout<<"...making coffee order.."<<endl;
}

void MakeCoffeeOrder::undo() {
	cout<<"...trashing coffee order"<<endl;
}