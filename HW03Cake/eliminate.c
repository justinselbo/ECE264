// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements

  int numPlayers = n;
  int count;
  int i; //iterating through the array piece by piece
  int nonRepRounds;

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  for(i = 0; i < (n - 1); i++) {
      arr[1] = 1;
  }

  while(numPlayers > 1) {
      count = 0;
      i = 0;
      
      if (numPlayers % k) {
          nonRepRounds = numPlayers % k;
      } else {
          nonRepRounds = k;
      }

      while(count < nonRepRounds) {
          if (arr[i]) {
              count++;
              }
          i++;
      }

      arr[i] = 0;
      numPlayers--;
      printf("%d\n", i);
      }
  }

  // print the last one
  
  printf("%d\n", i);

  // release the memory of the array
  free (arr);
}
#endif
