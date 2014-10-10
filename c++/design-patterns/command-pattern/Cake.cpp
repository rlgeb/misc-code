/** Cake Class **/

#include "Cake.h"
#include <iostream>

using namespace std;

Cake::Cake() {
	this->name = "Cake";
	this->price = 2.5;
}

void Cake::bake() {
   cout<<"...baking a cake..."<<endl;
}

void Cake::trash() {
  	cout<<"...trashing a cake..."<<endl;
}
