/** Coffee Class **/

#include "Coffee.h"
#include <iostream>

using namespace std;

Coffee::Coffee() {
	this->name = "Coffee";
	this->price = 2.5;
}

void Coffee::brew() {
	cout<<"...brewing coffee..."<<endl;
}

void Coffee::trash() {
	cout<<"trashing this coffee!"<<endl;
}
