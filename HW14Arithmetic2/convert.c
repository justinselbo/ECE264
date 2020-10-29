// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
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
// *** You MUST modify the convert function
// ***
#ifdef TEST_CONVERT
bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  
  //Create lists for operators and postfix list
  opList = malloc(sizeof(List));
  opList -> head = NULL;
  opList -> tail = NULL;
  outList = malloc(sizeof(List));
  outList -> head = NULL;
  outList -> tail = NULL;

  //Helper vars
  ListNode * curNode = arithlist -> head;
  ListNode * searchNode = curNode;
  int op = 0;
  char tempOp[WORDLENGTH] = NULL;
  ListNode * opTail = NULL;
  int prevOp;
  ListNode * parenNodes = NULL;

  while (curNode != NULL) {
    //Check to see if its a number, if so add to the postfix list
    if (isOperator(curNode -> word) == -1) {
      addNode(numList, curNode -> word);
    }
    else {
      //Convert to appropriate symbol
      op = isOperator(curNode -> word);
      if (op == 0) {
        sprintf(tempOp, "%c\n", 43);
      }
      else if (op == 1) {
        sprintf(tempOp, "%c\n", 45);
      }
      else if (op == 2) {
        sprintf(tempOp, "%c\n", 42);
      }
      else if (op == 3) {
        sprintf(tempOp, "%c\n", 40);
      }
      else if (op == 4) {
        sprintf(tempOp, "%c\n", 41);
      }

      //Check to see if oplist is empty
      if (opList -> head == NULL && opList -> tail == NULL) {
        addNode(opList, tempOp);
      }
      else {
        opTail = opList -> tail;
        prevOp = isOperator(opList -> tail);

        //Operator is not a parenthesis
        if (op < 3) {
          if (op < prevOp && prevOp < 3) {
            //Pop and push to output stack, add new operator
            addNode(outList, opTail -> word);
            deleteNode(opList, opTail -> word);
            addNode(opList, tempOp);
          }
          else if (op >= prevOp || prevOp >= 3) {
            addNode(opList, tempOp);
          }
        }
        else if (op == 3) {
          addNode(opList, tempOp);
        }
        else if (op == 4) {
          parenNodes = opTail;
          while (isOperator(parenNodes -> word) != 3) {
            addNode(outList, parenNodes -> word);
            deleteNode(opList, opTail -> word);
            parenNodes = parenNodes -> prev;
          }
          deleteNode(parenNodes);
        }
      }
    }
    curNode = curNode -> next;
  }

  //Add the rest of the operator nodes
  opTail = opList -> tail;
  while(opTail != NULL) {
    addNode(outList, opTail -> word);
    deleteNode(opList, opTail -> word);
    opTail = opTail -> prev;
  }

  
  return true;
}
#endif
