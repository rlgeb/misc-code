/** Coffee Class **/

#ifndef __COFFEE_H__
#define __COFFEE_H__

#include "MenuItem.h"
#include <iostream>

using namespace std;

class Coffee:MenuItem {
 public:
   Coffee();
   void brew();
   void trash();

};

#endif