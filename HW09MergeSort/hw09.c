// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  
  //Open file and check success
  FILE * readFile = fopen(filename, "r");
  if (readFile == NULL) {return false;}

  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false

  if (fseek(readFile, 0, SEEK_END) != 0) {
    fclose(readFile);
    return false;
  }

  // use ftell to determine the size of the file
  int fileSize = ftell(readFile);
  
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false

  if (fseek(readFile, 0, SEEK_SET) != 0) {
    fclose(readFile);
    return false;
  }

  // the number of integers is the file's size divided by
  // size of int  
  * size = (fileSize / sizeof(int));

  // allocate memory for the array
  * arr = malloc(sizeof(int) * (*size));

  // if malloc fails, fclose and return false
  if (* arr == NULL) {
    fclose(readFile);
    return false;
  }

  // use fread to read the number of integers in the file
  int numRead = fread(* arr, sizeof(int), * size, readFile);

  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  if (numRead != *size) {
    free(* arr);
    fclose(readFile);
    return false;
    }
  int nextByte = fgetc(readFile);
  nextByte = fgetc(readFile);
  if (nextByte != EOF) {
    free(* arr);
    fclose(readFile);
    return false;
    }
  
  // if fread succeeds
  // close the file
  fclose(readFile);
  
  // update the argument for the array address
  // update the size of the array
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * writeFile = fopen(filename, "w");

  // if fopen fails, return false
  if (writeFile == NULL) {return false;}  

  // use fwrite to write the entire array to a file
  int numWrites = fwrite(arr, sizeof(int), size, writeFile);

  // check whether all elements of the array have been written
  // fclose
  // if not all elements have been written, return false
  // if all elements have been written, return true

  if (numWrites != size) {
    fclose(writeFile);
    return false;
  }

  return true;

}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing
  if (l > r) {return;}
  // int sizeL = m - l + 1; //size of left part of array
  // int sizeR = r - m;     //size of right part of array
  // if ((sizeL == 1) || sizeR == 0) {return;}

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write
  int * tempSort = malloc(sizeof(int) * (r - l + 1));

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array
  int a = 0; //iterating thru merged array
  int i = l;     //iterating thru first array
  int j = m + 1; //iterating thru second array

  //iterates thre both lists, comparing each element and putting them in appr. order
  //one array will not be totally appended
  while (i <= m && j <= r) {
    if (arr[i] >= arr[j]) {
      tempSort[a] = arr[j];
      j++;
      a++;
    }
    else {
      tempSort[a] = arr[i];
      i++;
      a++;
    }
  }
  
  //Adds the rest of the missing elements
  for(i = i; i <= m; i++) {
    tempSort[a] = arr[i];
    a++;
  }
  for(j = j; j <= r; j++) {
    tempSort[a] = arr[j];
    a++;
  }
  
  a = 0;
  //Copying the temporary sorted array to original array
  for(i = l; i <= r; i++) {
    arr[i] = tempSort[a];
    a++;
  }

  
  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if ((l > r) || (l == r)) {return;}

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
  int m = (l + r) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);

} 
#endif
