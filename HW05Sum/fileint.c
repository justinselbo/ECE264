// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  
  int num;
  * sum = 0;

  FILE * readFile = fopen(filename, "r");
  
  //make sure file openes correctly
  if (readFile == NULL) 
  {
    return false;
  }
  
  //read and add the numbers
  while(fscanf(readFile, "%d", & num) == 1)
    {
      * sum += num;
    }
  
  fclose(readFile);

  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //

  FILE * writeFile = fopen(filename, "w");
  
  //make sure it opened for writing
  if (writeFile == NULL)
    {
      return false;
    }
  
  fprintf(writeFile, "%d", sum);

  //close file
  fclose(writeFile);

  return true;
}
#endif
