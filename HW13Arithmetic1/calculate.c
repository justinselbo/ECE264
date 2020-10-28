// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  
  //Checks to see if the input list is valid
  ListNode * iterNode = arithlist -> head;
  int numOperands = 0;
  if (isOperator(iterNode -> word) > 0) {
    return false;
  }

  // go through the list until there is only node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true
  
  ListNode * curNode = arithlist -> tail;
  ListNode * searchNode = curNode -> prev;

  int numOperands = 0;
  int i = 0;
  char * nonNums;
  int operand = 0;
  ListNode * operand1 = NULL;
  ListNode * operand2 = NULL;
  int operandNum1 = 0;
  int operandNum2 = 0;
  int operator = 0;
  int newNum = 0;

  while (arithlist -> head != arithlist -> tail && curNode != NULL) {
    if (isOperator(curNode) > -1) {
      //Find next two operands
      ListNode * operatorNode = curNode;
      operator = isOperator(operatorNode);
      i = 0;
      numOperands = 0;
      searchNode = curNode -> prev;
      while(searchNode != NULL && numOperands != 2) {
        if (isOperator(searchNode) == -1) {
          if (numOperands == 0) {operand1 = searchNode;}
          else {operand2 = searchNode;}
          numOperands++;
          i++;
        }
        searchNode = searchNode -> prev;
      }
    }
    if (seardNode == NULL && numOperands != 2) {
      //There are not two available operands for the operators
      return false;
    }
    else {
      //Check to make sure only integers, and not other characters
      operandNum1 = strtol(operand1 -> word, &nonNums, 10);
      operandNum2 = strtol(operand2 -> word, &nonNums, 10);

      //Do the required maths
      if (operator == 0) {
        newNum = operandNum1 + operandNum2;
        sprintf(operand2 -> word, "%d", newNum); //AFUNADIUGNAIUGDNAD LOOK RIGHT HERE NOT STORED CORRECTLY
        deleteNode(arithlist, operand1);
        deleteNode(arithlist, operatorNode);
      }
      else if (operator == 1) {
        newNum = operandNum2 - operandNum1;
        sprintf(operand2 -> word, "%d", newNum); //AFUNADIUGNAIUGDNAD LOOK RIGHT HERE NOT STORED CORRECTLY
        deleteNode(arithlist, operand1);
        deleteNode(arithlist, operatorNode);
      }
      else if (operator == 2) {
        newNum = operandNum2 * operandNum1;
        operand2 -> word = newNum //AFUNADIUGNAIUGDNAD LOOK RIGHT HERE NOT STORED CORRECTLY
        deleteNode(arithlist, operand1);
        deleteNode(arithlist, operatorNode);
      }
    }
    curNode = curNode -> next;
  }
  
  // if more than one node left, return false
  if (arithlist -> head != arithlist -> tail) {return false;}

  // if the remaining node is an operator, return false
  if (isOperator(arithlist -> head) != -1) {return false;}

  // if everything is OK, return true
  deleteList(arithlist);
  return true;
}
#endif
