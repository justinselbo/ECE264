// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
  //Initlizations
  ListNode * head = malloc(sizeof(ListNode));
  head -> value = 0;
  int i = 0;
  ListNode * n = head;

  //Maked the linked list
  for (i = 1; i < valn; i++) {
      n -> next = malloc(sizeof(ListNode));
      n = n -> next;
      n -> value = i;
  }
  
  //Sets last node equal to head to make it circular
  n -> next = NULL;

  return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
// #ifdef DEBUG
//   // this #ifdef ... #endif should be inside the condition *BEFORE* a
//   // node' value is printed and it is deleted
//   ListNode * todelete = p;
//   printListNode (todelete); 
// #endif
  int i = 1;
  ListNode * p = head;
  ListNode * q = p -> next;

  while (head -> next != NULL) {

    //Setting q
    if (p -> next == NULL) {
      q = head;
    }
    else {
      q = p -> next;
    }

    if (i == valk) {
      //Printing
      #ifdef DEBUG
        ListNode * todelete = p;
        printListNode (todelete); 
      #endif

      //Deleting and reseting nodes
      printf("%d\n", p -> value);
      head = deleteNode(head, p);
      p = q;
      q = q -> next;
      i = 1;
    }
    else {
      if (p -> next == NULL) {
        p = head;
      }
      else {
        p = p -> next;
        q = q -> next;
      }
      i++;
    }
  }
  printf("%d\n", p -> value);
  free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  if (head == NULL) {
    return NULL;
  }
  else if (todelete == NULL) {
    return head;
  }
  else if (todelete -> value == head -> value) {
    return head -> next;
  }
  else {
    ListNode * p = head;
    ListNode * q = p -> next;
    while ((q != NULL) && ((q -> value) != (todelete -> value))) {
      p = p -> next;
      q = q -> next;
    }
    if (q != NULL) {
      p -> next = q -> next;
      free (q);
    }
    return head;
  }
}
#endif
