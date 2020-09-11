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
  int i = -1; //iterating through the array piece by piece
  //int nonRepRounds;

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  for(i = 0; i < (n - 1); i++) {
      arr[i] = i;
  }

  while(numPlayers > 1) {
      count = 0;
     // i = -1;
      
     //Different method for choosing cake (this one is for starting at the begining every time)
     // if (k <= numPlayers) {
          //nonRepRounds = k;
     // } else {
          //nonRepRounds = k % numPlayers;
      //}

      while(count < k) {

	  if (i < (n - 1)) {
	      i++;
          } else {
              i = 0;
          }

          if (arr[i] > -1) {
              count++;
              } 
      }

      arr[i] = -1;
      numPlayers--;
      printf("%d\n", i);
  }

  // print the last one
  for(i = 0; i < (n - 1); i++) {
      if (arr[i] > -1) {
	  printf("%d\n", i);
          }
  }  


  // release the memory of the array
  free (arr);
}
#endif
