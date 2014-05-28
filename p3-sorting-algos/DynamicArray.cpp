/******************************
Rebecca Gebhard
Dynamic Array implimentation
**************************/

#include <iostream>
#include <string>
#include "DynamicArray.h"
#include "file.h"

using namespace std;

void DynamicArray::Delete(){
  if(arr != NULL){
    delete []arr;
    arr = NULL;
    first = NULL;
  }
}
void DynamicArray::SetSize(int size){
  if(arr != NULL){
    delete []arr;
  }
  sizeUsed = size + 1;//no zeros
  sizeTotal = sizeUsed * enlargeAmt;
  arr = new Site[sizeTotal];
  first = arr;
} 
DynamicArray::DynamicArray(){

    sizeUsed = 0;
    sizeTotal = initSize;
    arr = new Site[sizeTotal];
    if(arr == NULL){
      cout<<ERROR<<endl;
      exit(1);
    }
    first = arr;
}

DynamicArray::~DynamicArray(){
  if(arr != NULL){
    delete []arr;
    arr = NULL;
    first = NULL;
  }
}

void DynamicArray::Empty(){
  if(arr != NULL){
    delete []arr;
    arr = NULL;
    first = NULL;
  }

  sizeUsed = 0;
  sizeTotal = initSize;
  arr = new Site[sizeTotal];
  first = arr;
}
    

DynamicArray::DynamicArray(const DynamicArray &copyMe){
  arr = new Site[copyMe.sizeTotal];
  first = arr;
  Copy(copyMe);
  sizeTotal = copyMe.sizeTotal;
  sizeUsed = copyMe.sizeUsed;
}

DynamicArray& DynamicArray::operator=(const DynamicArray &copyMe){
  if(this == &copyMe){
    return *this;
  }
  if(arr != NULL){
    delete []arr;
  }
  arr = new Site[copyMe.sizeTotal];
  first = arr;
  sizeTotal = copyMe.sizeTotal;
  sizeUsed = copyMe.sizeUsed;
  Copy(copyMe);
  return *this;
}

Site& DynamicArray::operator[](unsigned int loc){
  if(loc>=0 && loc<sizeUsed){
    return arr[loc];
  }
}

void DynamicArray::Copy(const DynamicArray &copyMe){
  for(int i=0; i<copyMe.sizeUsed; i++){
    arr[i] = copyMe.arr[i];
  }
}

void DynamicArray::Append(const Site &element){

  sizeUsed++; 
  //0 - sizeTotal-1 so if its == need to resize as well
  if(sizeUsed >= sizeTotal){
    sizeTotal = enlargeAmt * sizeTotal;
    Site *temp= NULL;
    temp = new Site[sizeTotal];

    for(int i=0; i<sizeUsed-1; i++){
      temp[i] = arr[i];
    }
    if(arr != NULL){
      delete []arr;
      arr = NULL;
    }
    arr = temp;
    first = arr;
  }
  
  arr[sizeUsed-1] = element;
}

unsigned int DynamicArray::getSize(){
  return sizeUsed;
}
 



