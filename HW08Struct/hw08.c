// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  //Open file and check success
  FILE * readFile = fopen(filename, "r");
  if (readFile == NULL) {return -1;}

  int numElems = 0;

  //Count number of vectors in binary file
  while(!feof(readFile)) {
    Vector vecArr;
    if (fread(&vecArr, sizeof(Vector), 1, readFile) == 1){
      numElems++;
    }
  }

  fclose(readFile);
  return numElems;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  //open file and check success
  FILE * readFile = fopen(filename, "r");
  if (readFile == NULL) {return false;}

  int numVecs = 0;
  numVecs = fread(&vecArr[0], sizeof(Vector), size, readFile);

  //Check to make sure fread does everything correctly and numelems matches up
  if (numVecs != size) {return false;} //not enough elements
  int nextByte = fgetc(readFile);
  if (nextByte != EOF) {return false;} //more data than expected

  //Everything worked successfuly
  fclose(readFile);
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  //Recast type
  const Vector * ptr1 = (const Vector *) p1;
  const Vector * ptr2 = (const Vector *) p2;
  //Grab x values
  int xVal1 = ptr1 -> x;
  int xVal2 = ptr2 -> x;

  //Compare x values
  if (xVal1 < xVal2) {return -1;}
  else if (xVal1 > xVal2) {return 1;}

  //X values are the same, compare y values
  else {
    //Grab y values
    int yVal1 = ptr1 -> y;
    int yVal2 = ptr2 -> y;

    //Compare y values
    if (yVal1 < yVal2) {return -1;}
    else if (yVal1 > yVal2) {return 1;}

    //Y values are the same, compare z values
    else {
      //Grab z values
      int zVal1 = ptr1 -> z;
      int zVal2 = ptr2 -> z;

      //Compare z values
      if (zVal1 < zVal2) {return -1;}
      else if (zVal1 > zVal2) {return 1;}

      //All values are the same
      else {return 0;}
    }
  }

}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  //Open file and check success
  FILE * writeFile = fopen(filename, "w");
  if (writeFile == NULL) {return false;}

  //Write to file
  int numWrites = 0;
  numWrites = fwrite(vecArr, sizeof(Vector), size, writeFile);
  
  //Check for errors
  if (numWrites != size) {
    fclose(writeFile);
    return false;
  }

  fclose(writeFile);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
