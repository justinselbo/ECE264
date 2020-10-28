// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false 
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  //File open
  FILE * readFile = fopen(filename, "r");
  if (readFile == NULL) {return false;}

  //Make sure arithlist is useable and not NULL
  if (arithlist == NULL) {return false;}

  char tempword[WORDLENGTH];

  while (!feof(readFile)) {
    if (fgets(tempword, WORDLENGTH, readFile) != NULL) {
      //Add line as a new node to the arithlist
      addnode(arithlist, tempword);
    }
    else {
      //Free and close
      deletelist(arithlist);
      fclose(readFile);
      return false;
    }
  }

  fclose(readFile);
  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
  if (arithlist == NULL) {return;}

  ListNode * head = arithlits -> head;

  while (head != NULL) {
    Node * nextNode = head -> next;
    free(head);
    head = nextNode;
  }
}
#endif

#ifdef TEST_ADDNODE
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if (arithlist == NULL) {return;}

  //Create new node with word
  ListNode * newNode = malloc(WORDLENGTH);
  newNode -> word = {0};
  strcpy(nedNode -> word[WORDLENGTH], word);
  //newNode -> word = word;

  //Check to see if a node exists
  if (arithlist -> head == NULL && arithlist -> tail == NULL) {
    //no nodes exist, set prev and next to null
     newNode -> prev == NULL;
     newNode -> next == NULL;
    
    //Update arithlist
     arithlist -> head == newNode;
     arithlist -> tail == newNode;
  }
  else {
    //get last node
    ListNode * lastNode = arithlist -> tail;

    //Set the new node as the last node
    lastNode -> next = newNode;
    newNode -> prev = lastNode;
    newNode -> next = NULL;

    //Set arithlist to point to new tail
    arithlist -> tail = newNode;
  }
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  if (arithlist == NULL) {return false;}
  if (artihlist -> head == NULL && arithlist -> tail == NULL) {return false;}

  ListNode * head = arithlist -> head;
  ListNode * tail = arithlist -> tail;

  if (head -> word == ln -> word) {
    //Set next node up to be new head, free original head, and update arithlist
    ListNode * nextNode = head -> next;
    nextNode -> prev = NULL;
    free(head);
    arithlist -> head = nextNode;
    return true;
  }
  else if (tail -> word == ln -> word) {
    //Set prev node to be new tail, free original tail, and udpdate arithlist
    ListNode * prevNode = tail -> prev;
    prevNode -> next = NULL;
    free(tail);
    arithlist -> tail = prevNode;
    return true;
  }
  else {
    ListNode * p = tail;
    ListNode * q = p -> prev;
    while ((q != NULL) && ((q -> word) != (ln -> word))) {
      p = p -> prev;
      q = q -> prev;
    }
    if (q != NULL) {
      ListNode * nextNode = q -> prev;
      p -> prev = nextNode;
      nextNode -> next = p;
      free (q);
      return true;
    }
    return false;
  }
  //return true;
}
#endif