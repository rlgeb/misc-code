/** MakeCoffeeOrder.h **/

#ifndef __MAKECOFFEEORDER_H__
#define __MAKECOFFEEORDER_H__

#include "Order.h"
#include "Coffee.h"

class MakeCoffeeOrder: public Order {
 public:
 	Coffee coffee;

 	MakeCoffeeOrder(Coffee coffee);
    void exe();
    void undo();
};

#endif