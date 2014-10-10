/** NoCommand Implimentation **/
#ifndef __NOORDER_H__
#define __NOORDER_H__

#include "Order.h"

class NoOrder: public Order {
 public:
    void exe();
    void undo();
};

#endif