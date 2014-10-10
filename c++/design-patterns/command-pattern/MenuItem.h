#ifndef __MENUITEM_H__
#define __MENUITEM_H__

#include <string>
using namespace std;

class MenuItem {
protected:
  string name; 
  float price;

 public:
  string getName();
  float getPrice();
};

#endif