/** MakeCakeOrder.cpp **/

#include "MakeCakeOrder.h"

MakeCakeOrder::MakeCakeOrder(Cake cake) {
	this->cake = cake;
}

void MakeCakeOrder::exe() {
	cake.bake();
}

void MakeCakeOrder::undo() {
	cake.trash();
}

