// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  int i = 0; //Step counter used for iterating through the file
  int chr;

  FILE * readFile = fopen(filename, "r");
  
  //check to make sure file openes correctly
  if (readFile == NULL) {
    return false;
  }
    
  //iterate through the file and increase the index of characters seen
  while((chr = fgetc(readFile)) != EOF)
    {
      counts[chr]++;
      i++;
    }

  //close file
  fclose(readFile);

  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
  
  int i; 
  
  for(i = 0; i < size - 1; i++)
    {
      if (counts[i] > 0)
	{
	  printf("%d, ", i);
	  if (((i >= 65) && (i <= 90)) || ((i >= 97) && (i <= 122)))
	    {
	      printf("%c, ", i);
	    }
	  else
	    {
	      printf(" , ");
	    }
	  
	  printf("%d\n", counts[i]);
	}
    }
}
#endif
