/******************************
Rebecca Gebhard
eecs281
p2
**************************/

#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__

#include <iostream>
#include <string>
#include "file.h"

using namespace std;

 const string ERROR = "error\n";


class iterAlreadyExists; 

class DynamicArray{

 public:
  DynamicArray(); //ctr
  ~DynamicArray();  //dctr
  DynamicArray(const DynamicArray &copyMe); //cctr
  DynamicArray& operator = (const DynamicArray &copyMe);//opovd
  Site& operator[](unsigned int loc); //allow index
  
  Site* first;
  void Delete();//deletes it 
  void SetSize(int size); //changes the size
  void Empty(); //empty arr
  void Copy(const DynamicArray &copyMe); //copy copyMe to arr
  void Append(const Site &element); //add new elt
  unsigned int getSize(); //return sizeUsed
  
 private:
  Site* arr;
  int sizeUsed; //size in use/filled
  int sizeTotal; //size allocated
  const static int initSize = 500; //inital allocated size
  const static int enlargeAmt = 2;  //expand factor
};




#endif
