/** Invoker = Waitress **/

#include "Order.h"
#include <vector>
#include <iostream>
using namespace std;

class Waitress {
 std::vector<Order*> orderSheet;
public:
 	void takeOrder(Order* newOrder) {
 		this->orderSheet.push_back(newOrder);
 	}

 	void orderUp(int i) {
 		Order* order = this->orderSheet[i];
 		order->exe();
 	}

 	// void orderUp() {
 	// 	for (int i=0; i<this->orderSheet.size();i++) {
  //   		tthis->orderSheet[i].exe();
  //   	}
 	// }

 // 	void readOrderSheet(){
 // 		for( std::vector<Order*>::const_iterator i = this.orderSheet.begin(); i != this.orderSheet.end(); ++i) {
 //   			std::cout << i->exe() << ' ';
 // 		}
	// }
};
