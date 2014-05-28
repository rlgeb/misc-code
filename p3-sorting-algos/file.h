/**************************************************
REBECCA GEBHARD
FILE HEADER FILE
***********************************************/


#ifndef __FILE_H__
#define __FILE_H__

#include <string>

using namespace std;


enum Algorithm{
  BUBBLE,
  HEAP,
  MERGE,
  QUICK,
  BUCKET,
  NONE
};

struct Key{
  long len;
  long start;
  long end;
};

class File{
 public:
  //memeber varibles
  Algorithm  algorithm;
  bool reverse;
  const char* output;
  const char* input;
  Key key;
  long max;
  long min;
  long numLines;

  //member functions
  File();  //ctor sets the default values
  bool isSet(const char* var); 
  //EFFECTS:  returns true if the var has been set and false otherwise
};


struct Site{
  long keyValue;
  string line;
  string url;
  string num;
  int firstNum;
};

#endif
