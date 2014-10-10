/** Command Interface **/

#ifndef __ORDER_H__
#define __ORDER_H__

class Order {
 public:

    virtual void exe() = 0;
    virtual void undo() = 0;
};

#endif