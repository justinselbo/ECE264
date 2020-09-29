// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  int num;
  int numInts = 0;

  FILE * readFile = fopen(filename, "r");

  //make sure file openes correctly
  if (readFile == NULL) 
  {
    return -1;
  }

  while(fscanf(readFile, "%d", & num) == 1) {
    numInts++;
  }

  fclose(readFile);

  return numInts;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  int num;
  int i = 0;

  FILE * readFile = fopen(filename, "r");

  //make sure file openes correctly
  if (readFile == NULL) {
    return false;
  }

  while(fscanf(readFile, "%d", & num) == 1) {
    //Check to make sure we are not over the size
    if ((i + 1) > size) {
      return false;
    }

    intArr[i] = num;
    i++;
  }

  //Check for appropriate size again
  if(i != size) {
    return false;
  }

  fclose(readFile);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.

  const int * ptr1 = (const int *) p1;
  const int * ptr2 = (const int *) p2;

  int num1 = * ptr1;
  int num2 = * ptr2;

  if (num1 > num2) {
    return 1;
    }
  else if (num1 == num2) {
    return 0;
  }
  else {
    return -1;
  }
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
  int i = 0;

  FILE * writeFile = fopen(filename, "w");

  //make sure file openes correctly
  if (writeFile == NULL) {
    return false;
  }

  //Writes to the file
  while((i + 1) <= size) {
    fprintf(writeFile, "%d\n", intArr[i]);
    i++;
  }

  fclose(writeFile);

  return true;
}
#endif
