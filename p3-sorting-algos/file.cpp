/*********************************
REBECCA GEBHARD 
PROJ1-FILE IMPLIMENTATION
********************************/
#include "file.h"
#include <iostream>
#include <string>
using namespace std;


File::File(){
  algorithm = NONE;
  reverse = false;
  output = "";
  input = "none";
  Key k;
  k.start = -10;
  k.end = -10;
  key = k;
}
    

bool File::isSet(const char* c){

  if(strcmp(c,"Algorithm")==0){
    if(algorithm==NONE)
      {
	return false;
      }
  return true;
  }

  else if(strcmp(c,"Key")==0){
    if(key.start==-10 && key.end==-10){
      return false;
    }
    return true;
  }
  
  else if(strcmp(c,"Reverse")==0){
    if(reverse==false){
      return false;
    }
    return true;
  }
  
  else if(strcmp(c,"Output")==0){
    if(output==""){
      return false;
    }
    return true;
  }
  
  else if(strcmp(c,"Input")==0){
    if(input=="none"){
     return false;
    }
    return true;
  } 
  return false;
}
