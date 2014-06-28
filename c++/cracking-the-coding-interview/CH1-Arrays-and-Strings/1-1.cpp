/**
1.1 
Impliment an algorithm to has all unique ascii characters.
Do not use lib data structures.
**/

#include <iostream>
#include <string.h>
using namespace std;

const unsigned int ASCII_SIZE = 256;

int main(int argc, char* argv[]){
  //validate input
  if(argc != 2){
    cout<<"please input a string\n";
    return 1;
  }
 
  char* inputStr = argv[1];
  int inputStrSize = strlen(inputStr);
  
  if(inputStrSize > ASCII_SIZE) {
    cout<<"NOT UNIQUE\n";
  }
  //check the cstring
  bool* charUsed = new bool[ASCII_SIZE];
  for(int i=0; i<inputStrSize; i++){
    int currentChar = (int)inputStr[i];
    if(charUsed[currentChar]){
        cout<<"NOT UNIQUE\n";
        return 0;
    }
    charUsed[currentChar] = 1;
  }
  cout<<"UNIQUE\n"; 
  return 0;
}
