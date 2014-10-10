/** MenuItem Implimentation **/

#include "MenuItem.h"
#include <string>
using namespace std;

string MenuItem::getName() { 
	return this->name;
}

float MenuItem::getPrice() {
	return this->price;
}
