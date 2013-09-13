/*****************************
REBECCA GEBHARD
EECS281-PROJ3
***************************/

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include "file.h"
#include "DynamicArray.h"
#include "p3.h" 

using namespace std;

//////////////////////////////////////////////////////////
void printReverse(DynamicArray& S,File & file){
//for bucket sort it's zero based
  if(file.algorithm==BUCKETSORT_INT){
    for(int i=S.getSize(); i>=0; i--){
      if(S[i].line != EMPTY_STR){ //put in some blank line
	cout<<S[i].line<<NEWLINE;
      } 
    }
  }
//all others are 1 based
  else{
    for(int i=S.getSize(); i>0; i--){
      if(S[i].line != EMPTY_STR){ //put in some blank line
	cout<<S[i].line<<NEWLINE;
      } 
    }
  }
  return;
}

///////////////////////////////////////////////////////////

void printSites(DynamicArray& S, File &file){
  if(file.isSet("Reverse")){
    printReverse(S, file);
    return;
  }
//for bucket sort it starts at zero
  if(file.algorithm==BUCKETSORT_INT){
    for(int i=0; i<S.getSize();i++){
      if(S[i].line != EMPTY_STR){ //put in some blank line
        cout<<S[i].line<<NEWLINE;
      }
    }
  }
//all others are 1 based
  else{
    for(int i=ONE; i<S.getSize();i++){
      if(S[i].line != EMPTY_STR){ //put in some blank line
        cout<<S[i].line<<NEWLINE;
      }
    }
  }
  return;
}
///////////////////////////////////////////////BUBBLE SORT
void bubbleSort(DynamicArray& A) {
  
  for (int i=ONE;i<A[0].keyValue; i++){
    for (int j=A[0].keyValue;j>i;j--){
      if(A[j].keyValue<A[j-ONE].keyValue){
	Site temp;
	temp=A[j];
	A[j]=A[j-ONE];
	A[j-ONE]=temp;
      } 
      //tie use url
      else if(A[j].keyValue == A[j-ONE].keyValue && A[j].url<A[j-ONE].url){
        Site temp;
	temp=A[j];
	A[j]=A[j-ONE];
	A[j-ONE]=temp;
      }
    }
  }
  
  return;
}

/////////////////////////////////////////////////////////HEAP SORT

void maxHeapify(DynamicArray& A, int i){
//left child index
  int l;
  l = TWO*i;
  //right child index
  int r;
  r = TWO*i+ONE;
  
  int largest=i;
  if(l<=A[0].keyValue && A[l].keyValue>A[i].keyValue){
    largest = l;
  } 
  //tie breaker use url
  else if(l<=A[0].keyValue && A[l].keyValue==A[i].keyValue && 
	  A[l].url>A[i].url){
    largest = l;
  }
  else{
    largest = i;
  }
  
  if(r<=A[0].keyValue && A[r].keyValue>A[largest].keyValue){
    largest = r;
  }
  //tie breaker use url
  else if(r<=A[0].keyValue && A[r].keyValue==A[largest].keyValue &&
	  A[r].url>A[largest].url){
    largest = r;
  }
  if(largest!=i){
    Site temp;
    temp=A[i];
    A[i]=A[largest];
    A[largest]=temp;
    maxHeapify(A,largest);
  }
}

void buildMaxHeap(DynamicArray& A){
  for(int i=A[0].keyValue/TWO; i> 0;i--){
    maxHeapify(A,i);
  }
}

void  HeapSort(DynamicArray& A){ 
  
  buildMaxHeap(A); 
  
  int len=A[0].keyValue;
  for (int i=len; i>ONE;i--){
    Site temp=A[ONE];
    A[ONE]=A[i];
    A[i]=temp;
    A[0].keyValue--;		
    maxHeapify(A,ONE);
  }
  
  return;
}

///////////////////////////////////////////////////////MERGE SORT

void merge(DynamicArray& A, int first, int last, int middle){
  
  int sizel=middle-first+ONE;
  int sizer=last-middle;
  Site* left=new Site[sizel+ONE];
  Site* right=new Site[sizer+ONE];
  
  for(int i=0;i<sizel;i++){
    left[i]=A[first+i];
  }
  
  for(int j=0; j<sizer;j++){
    right[j]=A[middle+j+ONE];
  }
  left[sizel].keyValue=ERROR_INT;
  right[sizer].keyValue=ERROR_INT;

  int i=0;
  int j=0;
  
  for(int k=first; k<= last; k++){
    if(right[j].keyValue==ERROR_INT){    //the right side is empty
      A[k]=left[i];
      i++;
    }
    else if(left[i].keyValue==ERROR_INT){    //the left side is empty  
      A[k]=right[j];
      j++;
    }
    else if(left[i].keyValue<right[j].keyValue){
      A[k]=left[i];
      i++;
    }
    //tie breaker
    else if(left[i].keyValue==right[j].keyValue){
      if(left[i].url<right[j].url){
        A[k] = left[i];
        i++;
      }
      else{
        A[k] = right[j];
        j++;
      }
    }
    else{
      A[k]=right[j];
      j++;
    }
  }
  delete []left;
  delete []right;
}

void mergeSort(DynamicArray& A,int first,int last){
  if(first<last){
    int middle=(first+last)/TWO;
    mergeSort(A,first,middle);
    mergeSort(A,middle+ONE,last);
    merge(A,first,last,middle);
  }
  
  return;
}

///////////////////////////////////////////////////////////////QUICK SORT
int partition(DynamicArray& A, int first, int last){
  int key = A[last].keyValue;   //as of now keep it here then do 3 median
  string url = A[last].url;
  int i=first-ONE;
  for(int j=first; j<last;j++){
    if(A[j].keyValue<key || (A[j].keyValue==key  && A[j].url<url)){
      i++;
      Site temp;
      temp=A[i];
      A[i]=A[j];
      A[j]=temp;
    }
  }
  Site temp2 = A[i+ONE];
  A[i+ONE]=A[last];
  A[last]=temp2;
  return i+ONE;
}


void QuickSort(DynamicArray& A, int first, int last){
  
  if(first<last){
    int pivot=partition(A, first, last);
    QuickSort(A, first, pivot-ONE);
    QuickSort(A,pivot+ONE,last);
  }
}
////////////////////////////////////////////////////////////BUCKET SORT

bool sortComp(Site A, Site B){
  if(A.keyValue < B.keyValue){
    return true;
  }
  else if(A.keyValue == B.keyValue && A.url < B.url){
    return true;
  }      
  return false;
}

void BucketSort(DynamicArray& A, File& file){
  int range=(file.max-file.min);
  //nothing in this bucket
  if(A.getSize() == 0){
    return;
  }
  
  //partition the array bucket sizes
  int part = (int)((range/A.getSize())/TWO);
  
  //can't divide by zero so just make sure
  if(part == 0){
    part = ONE;
  }
  
  //make the bucket array
  int numBuckets = (file.max-file.min)/part+ONE;
  DynamicArray* B = new DynamicArray[numBuckets+ONE];

  //BUCKET THEM 
  
  //loop through the sites
  for(int i=0; i<A.getSize(); i++){
    int bucket = (int)((A[i].keyValue-file.min)/part);
    //past the end put in last one
    if(bucket > numBuckets){
      bucket = numBuckets;
    }
    B[bucket].Append(A[i]);
  }
  
  //move them back to A
  int aSpot = 0;
  for(int i=0; i<numBuckets+ONE; i++){
    for(int j=0; j<B[i].getSize();j++){
      A[aSpot] = B[i][j];
      aSpot++;
    }
  }
  delete []B;
  
  //append a last element to get full range [first,last)
  Site s;
  s.keyValue = ERROR_INT;
  A.Append(s);
  //stl sort() the buckets
  sort(A.first,A.first+A.getSize()-ONE, sortComp);
  
  return;
}
//////////////////////////////////////////////////////////////

void determineKey(File & file, string aline, Site &s){
 
  if(!file.isSet("Key")){
    s.keyValue = atoi(aline.c_str());
    aline = aline[0];
    s.firstNum = atoi(aline.c_str());
  }
  else if(aline.length()<file.key.start){ 
    //none of the key falls within the range
    cerr<<RANGE_ERROR<<endl;
    exit(1);
  }
  
  else if(file.key.end==ERROR_INT || file.key.end>aline.length()){
    //len -1 for 0 start
    s.keyValue = atoi(aline.substr(file.key.start,aline.length()).c_str());
    s.firstNum = atoi(aline.substr(file.key.start, 1).c_str());
  }
  else{
    int sep = file.key.end - file.key.start + 1;
    s.keyValue = atoi(aline.substr(file.key.start,sep).c_str());
    s.firstNum = atoi(aline.substr(file.key.start, 1).c_str());
  }
}

////////////////////////////////////////////////////////////////////////

void BucketSortRead( File& file){
  string aline;
  Site s;
  s.keyValue=0;
  //used for bucket sort
  file.max = ERROR_INT;
  file.min=0;
  //the buckets using first number as key so 
  //0,1,2,3,4,5,6,7,8,9
  DynamicArray* BucketList = new DynamicArray[BUCKET_NUM];
  //max and min for the double bucket sort
  File* BucketMaxMin = new File[BUCKET_NUM];
  
  //file is given in the command line
  if(file.isSet("Input")){  
    ifstream inFile;
    inFile.open(file.input);
    if(inFile.fail()){
      cerr<<BAD_FILE<<flush;
      exit(1);
    }
    while(inFile.good()){
      getline(inFile, aline);
      s.line = aline;
      int len = aline.length();
      //ignore entry lines
      if(aline==EMPTY_STR){
        continue;       
      }
      //use to split the # and url
      int loc = aline.find(SPACE); 
      //there is no url just a number
      if(loc == string::npos){   
	determineKey(file, aline, s);
        s.url = EMPTY_STR; 
        s.num = aline;
      }
      else{
        string num = aline.substr(0,loc); 
  	determineKey(file, num, s);
        s.url = EMPTY_STR;
        s.num = aline;
      }
      if(s.keyValue>BucketMaxMin[s.firstNum].max){
        file.max=s.keyValue;
      }
      if(s.keyValue < BucketMaxMin[s.firstNum].min || 
	 BucketMaxMin[s.firstNum].min == ERROR_INT){
	file.min=s.keyValue;
      }
      BucketList[s.firstNum].Append(s);
    }     
  }
  //input file read through the command line
  else{ 
    while(cin.good()){
      getline(cin,aline);
      //ignore the blank lines
      if(aline==EMPTY_STR){
	continue;
      }
      s.line = aline;
      int loc = aline.find(SPACE);
      //there is no url just a number
      if(loc == string::npos){  
	determineKey(file, aline, s); 
	s.url = EMPTY_STR;
	s.num = aline;
      }
      else{
	string num = aline.substr(0,loc);
	determineKey(file, num, s);
	// s.num = num;
	s.url = aline.substr(loc+ONE);
      }
      if(s.keyValue>BucketMaxMin[s.firstNum].max){
	file.max=s.keyValue;
      }
      if(s.keyValue < BucketMaxMin[s.firstNum].min || 
	 BucketMaxMin[s.firstNum].min == ERROR_INT){
	file.min=s.keyValue;
      }
      BucketList[s.firstNum].Append(s);
    }
  }
  //double bucket sort :)
  for(int i=0; i<BUCKET_NUM; i++){
    BucketSort(BucketList[i], BucketMaxMin[i]);
    printSites(BucketList[i], file);
  }
  
  return;
}


//////////////////////////////////////////////////////////////////////////
void readFile(DynamicArray& S, File& file){
  string aline;
  //used for bucket sort
  file.max=ERROR_INT;
  file.min=ERROR_INT;
  
  //file is given in the command line
  if(file.isSet("Input")){  
    ifstream inFile;
    inFile.open(file.input);
    if(inFile.fail()){
      cerr<<BAD_FILE<<flush;
      exit(1);
    }
    //set the first value to size-> now 1 based  
    Site s;
    s.keyValue=0;
    S.Append(s);
    
    while(inFile.good()){
      getline(inFile, aline);
      int len = aline.length();
      //ignore entry lines
      if(aline==EMPTY_STR){
        continue;       
      }
      s.line = aline;
      //use to split the # and url
      int loc = aline.find(SPACE); 
      
      //there is no url just a number
      if(loc == string::npos){   
	determineKey(file, aline, s);
        s.url = EMPTY_STR;
        s.num = aline;
      }
      else{
        string num = aline.substr(0,loc); 
	determineKey(file, num, s);
        s.url = EMPTY_STR;
        s.num = aline;
      }
      if(s.keyValue > file.max){
	file.max = s.keyValue;
      }
      if(s.keyValue < file.min || file.min==ERROR_INT){
	file.min = s.keyValue;
      }
      S.Append(s);
    }     
  }
  //input file read through the command line
  else{ 
    Site s;
    s.keyValue = 0;
    S.Append(s);
    
    while(cin.good()){
      getline(cin,aline);
      if(aline==EMPTY_STR){
	continue;
      }
      s.line = aline;
      int loc = aline.find(SPACE);
      if(loc == string::npos){   //there is no url just a number
	determineKey(file, aline, s); 
	s.url = EMPTY_STR;
	s.num = aline;
      }
      else{
	string num = aline.substr(0,loc);
	determineKey(file, num, s);
	s.num = num;
	s.url = aline.substr(loc+ONE);
      }
      if(s.keyValue>file.max){
	file.max=s.keyValue;
      }
      if(s.keyValue < file.min || file.min == ERROR_INT){
	file.min=s.keyValue;
      }
      S.Append(s);
    }
  }
  file.numLines = S.getSize()-ONE;
  S[0].keyValue = S.getSize()-ONE;
  return;
}

      
void readCommands(int argc, char* argv[], File& file){  
  //flags that can be set
  
  if(argc>NINE){
    cerr<<BAD_ARGS<<flush;
    exit(1);
  }
  //no flags set
  if(argc==ONE){
    file.key.start=0;
    file.key.end=ERROR_INT;
    return ;
  }
    
  //iterate over the agrs list
  for(int i=ONE; i<argc; i++){
    //BUBBLE SORT -b	
    if(strcmp(argv[i],b)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      file.algorithm=BUBBLE;
    }
    //HEAP SORT -h
    else if(strcmp(argv[i],h)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
	exit(1);
      }  
      file.algorithm=HEAP;
    }
    //MERGE SORT -m
    else if(strcmp(argv[i],m)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      file.algorithm=MERGE;
    }
    //QUICK SORT -q
    else if(strcmp(argv[i],q)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
        exit(1);
      }
      file.algorithm=QUICK;
    }
    //BUCKET SORT -B
    else if(strcmp(argv[i],B)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      file.algorithm=BUCKET;
    }
    //OPTIMAL SORT -O
    else if(strcmp(argv[i],O)==0){
      if(file.isSet("Algorithm")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      // leave it set to NONE
    }
    // Reverse sort -r
    else if(strcmp(argv[i],r)==0){
      if(file.isSet("Reverse")){
	cerr<<BAD_ARGS;
	//double check you don't just keep changing it
	exit(1);
      }
      file.reverse=true;
    }
    //output file -o
    else if(strcmp(argv[i],out)==0){
      if(file.isSet("Output")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      if(i<argc-ONE){
	i++;
	file.output=argv[i];
      }
      else{
	cerr<<BAD_ARGS;
	exit(1);
      }
      
    }
    //input file -i
    else if(strcmp(argv[i],inp)==0){
      if(file.isSet("Input")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      if(i<argc-ONE){
	i++;
	file.input=argv[i];
      }
      else{
	cerr<<BAD_ARGS;
	exit(1);
      }
    }
    //Key -k
    else if(strcmp(argv[i],k)==0){
      if(file.isSet("Key")){
	cerr<<BAD_ARGS;
	exit(1);
      }
      
      if(i<argc-ONE){
	i++;
	char comma[]= ",";
	string line=string(argv[i]);
	int loc=line.find(COMMA);
	int len=line.length();
	
	if(loc==len-ONE){//comma at the end
	  file.key.start=atoi(&line[0])-ONE;
	  file.key.end=ERROR_INT;
	}
	else if(loc==0){//comma is at the begining
	  file.key.start=0;
	  file.key.end=atoi(&line[ONE])-ONE;
          if(file.key.end == ERROR_INT){
            cerr<<BAD_ARGS;
 	    exit(1);
          }
	}
	else if(loc>0 && loc<len){ //comma is somewhere in the middle
	  file.key.start=atoi(line.substr(0,loc).c_str())-ONE;
	  file.key.end=atoi(line.substr(loc+ONE,len-ONE).c_str())-ONE;
	  if(file.key.start>file.key.end || file.key.end==ERROR_INT){
	    cerr<<BAD_ARGS;
	    exit(1);
	  }
	}
	else if(loc==string::npos && atoi(line.c_str())){//no comma
	  file.key.end=-ONE;
	  file.key.start=atoi(line.c_str())-ONE;
	  
	}
	else{  //no key given IS THIS AN ERROR
	  cerr<<BAD_ARGS;
	  exit(1);
	  i--;
	  file.key.start=0;
	  file.key.end=ERROR_INT;
	}
      }
      else{
	file.key.start=0;
	file.key.end=ERROR_INT;
      }
    }
    //HELP -H
    else if(strcmp(argv[i], H)==0){
      if(argc != TWO){
	cerr<<BAD_ARGS;
	exit(0);
      }
      cout<<COMMANDS_STR;
      cout<<BUBBLE_STR;
      cout<<HEAP_STR;
      cout<<MERGE_STR;
      cout<<QUICK_STR;
      cout<<BUCKET_STR;
      cout<<OPT_STR;
      cout<<REV_STR;
      cout<<INPUT_STR;
      cout<<OUTPUT_STR;
      cout<<KEY_STR;
      cout<<HELP_STR;
      exit(0);
    }
    //idk what your giving me exit    
    else{
      cerr<<argv[i]<<BAD_ARGS;
      exit(1);
    }    
  }

  if(!file.isSet("Key")){
    file.key.start=0;
    file.key.end=ERROR_INT;
  }
  //added based on the -k 0
  if(file.key.start==ERROR_INT){
    cerr<<BAD_ARGS;
    exit(1);
  } 
  return ;
}

////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]){
  //contains info about flie/flags
  File file;
  
  readCommands(argc, argv, file);
  //if use bucket sort then read file differently
  if(file.algorithm==BUCKETSORT_INT){
    BucketSortRead(file);
  }
  //to keep track of the sites
  DynamicArray S;
  readFile(S, file);
  
  if(file.algorithm==BUBBLESORT_INT){
    bubbleSort(S);
  }
  else if(file.algorithm==HEAPSORT_INT){
    HeapSort(S);
  }
  else if(file.algorithm==MERGESORT_INT){
    mergeSort(S,ONE,S[0].keyValue);
  }
  else if(file.algorithm==QUICKSORT_INT){
    QuickSort(S,ONE,S[0].keyValue); 
  }
  else{//My choice
    mergeSort(S,ONE,S[0].keyValue);
  }
  printSites(S,file);
  
  return 0;
  
}
