/****************************
REBECCA GEBHARD
sort.cpp header file
*****************************/

#ifndef __SORT_H__
#define __SORT_H__

//avoid literals
//numbers 
 const unsigned int BUCKET_NUM = 10;
 const int ERROR_INT = -1;
 const unsigned int ONE = 1;
 const unsigned int BUBBLESORT_INT = 0;
 const unsigned int HEAPSORT_INT = 1;
 const unsigned int MERGESORT_INT = 2;
 const unsigned int QUICKSORT_INT = 3;
 const unsigned int BUCKETSORT_INT = 4;
 const unsigned int TWO = 2;
 const unsigned int NINE = 9;
//strings 
 const string RANGE_ERROR="none of the key falls within the expected range\n";
 const string BAD_FILE = "bad input file\n";
 const string SPACE = " ";
 const string EMPTY_STR = "";
 const string NEWLINE = "\n";
 const string BAD_ARGS = "Bad arrguments!\n";
 const string COMMA = ",";
 const string COMMANDS_STR = "commands:\n";
 const string BUBBLE_STR = "-b sort using bubble sort\n";
 const string HEAP_STR = "-h sort using heapsort\n";
 const string MERGE_STR = "-m sort using merge sort\n";
 const string QUICK_STR = "-q sort using quicksort\n";
 const string BUCKET_STR = "-B sort using Bucket Sort\n";
 const string OPT_STR= "-O sort using the optimal sort \n";
 const string REV_STR = "-r reverse the sort (put lines in descending order of keys)\n";
 const string INPUT_STR = "-i filename (use named input file)\n";
 const string OUTPUT_STR = "-o filename (use named output file)\n";
 const string KEY_STR = "-k m,n (sort key is columns m through n, m and n are ints)\n";
 const string HELP_STR = "-H print a help message and exit\n";
//flags
 char KEY[] = "Key";
 char REVERSE[] = "Reverse";
 char INPUT[] = "Input";
 char ALGO[] = "Algorithm";
 char OUTPUT[] = "Output";
//input options
 char b[]="-b";
 char h[]="-h";
 char m[] ="-m";
 char q[]="-q";
 char B[]="-B";
 char O[]="-O";
 char r[]="-r";
 char inp[]= "-i";
 char out[]="-o";
 char k[]="-k";
 char H[]="-H";

void printReverse(Site* S,File &file);
//EFFECTS:prints out the sorted sites in order from largest to smallest to the 
//specified output file 

void printSites(Site* S, File &file);
//EFFECTS:prints out the sorted sites in order from smallest to largest to the 
//specified output file

void bubbleSort(Site *A);
//EFFECTS: Sorts the array of sites A using the bublesort algorithm
//MODIFIES: A

void maxHeapify(Site *A, int i);
//EFFECTS: fixes the heap so that that it fufills the 
//condition that the parent is > the children
//MODIFIES: A

void buildMaxHeap(Site* A);
//EFFECTS: builds a max heap to start by calling maxheapify

void  HeapSort(Site *A);
//EFFECTS: Sorts the array of sites A using the heap algorithm
//MODIFIES: A

void merge(Site* A, int first, int last, int middle);
//EFFECTS: combines two sorted lists by comparing the first of each and
// choosing the next smallest
//MODIFIES: A
void mergeSort(Site* A,int first,int last);
//EFFECTS: Sorts the array of sites A using the mergesort algorithm
//MODIFIES: first,last

int partition(Site* A, int first, int last);
//EFFECTS: partistions the array so that one element is in its known
// correct spot
//MODIFIES: A

void QuickSort(Site *A, int first, int last);
//EFFECTS: Sorts the array of sites A using the quicksort algorithm
//MODIFIES: first,last

bool sortComp(Site A, Site B);
//EFFECTS: used for stl sort ()

void BucketSort(Site* A, File& file);
//EFFECTS: Sorts the array of sites A using the bucketsort algorithm
//MODIFIES: A

void BucketSortRead( File& file);
//EFFECTS: buckets the site when read in based on 1st #, and then calls
//bucket sort again (double bucket sort kinda)
//MODIFIES: file

int determineKey(File & file, string aline);
//EFFECTS: finds the key in the string of digits from the file
//MODIFIES: file

Site* readFile(File& file);
//EFFECTS: reads in the lines of the file and stores them for use
//MODIFIES: file

void readCommands(int argc, char* argv[], File& file);
//EFFECTS:  reads and sets the desired commands of the user given in 
//the command line
//MODIFIES: file


#endif
