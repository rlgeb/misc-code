/** MakeCakeOrder.h **/

#ifndef __MAKECAKEORDER_H__
#define __MAKECAKEORDER_H__

#include "Cake.h"
#include "Order.h"

class MakeCakeOrder: public Order {
 public:
 	Cake cake;

 	MakeCakeOrder(Cake cake);

    void exe();
    void undo();
};

#endif