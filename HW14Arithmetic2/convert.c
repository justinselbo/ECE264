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
  List * opList = malloc(sizeof(List));
  opList -> head = NULL;
  opList -> tail = NULL;
  List * outList = malloc(sizeof(List));
  outList -> head = NULL;
  outList -> tail = NULL;


  //Helper vars
  ListNode * curNode = arithlist -> head;
  int op = 0;
  char tempOp[WORDLENGTH];
  ListNode * opTail = NULL;
  int prevOp;
  ListNode * parenNodes = NULL;
  ListNode * iterNode = NULL;
  ListNode * tempNode = NULL;

  while (curNode != NULL) {
    //Check to see if its a number, if so add to the postfix list
    if (isOperator(curNode -> word) == -1) {
      addNode(outList, curNode -> word);
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
        prevOp = isOperator(opTail -> word);

        //Operator is not a parenthesis
        if (op < 3) {
          if (op == 2) {
            // if (prevOp == op) {
            //   addNode(outList, opTail -> word);
            //   deleteNode(opList, opTail);
            //   addNode(outList, tempOp);
            // }
            addNode(opList, tempOp);
          }
          else if (op == 1) {
            // if (prevOp == op) {
            //   addNode(outList, opTail -> word);
            //   deleteNode(opList, opTail);
            //   addNode(outList, tempOp);
            // }
            if (prevOp < 3) {
              iterNode = opList -> tail;
              while (iterNode != NULL && isOperator(iterNode -> word) != 3) {
                addNode(outList, iterNode -> word);
                deleteNode(opList, iterNode);
                iterNode = opList -> tail;
              }
              addNode(opList, tempOp);
            }
            else {
              addNode(opList, tempOp);
            }
          }
          else if (op == 0) {
            // if (prevOp == op) {
            //   addNode(outList, opTail -> word);
            //   deleteNode(opList, opTail);
            //   addNode(outList, tempOp);
            // }
            if (prevOp == 2) {
              iterNode = opList -> tail;
              while (iterNode != NULL && isOperator(iterNode -> word) != 3) {
                addNode(outList, iterNode -> word);
                deleteNode(opList, iterNode);
                iterNode = opList -> tail;
              }
              addNode(opList, tempOp);
            }
            else {
              addNode(opList, tempOp);
            }
          }
        }
        else if (op == 3) {
          addNode(opList, tempOp);
        }
        else if (op == 4) {
          parenNodes = opTail;
          while (isOperator(parenNodes -> word) != 3) {
            tempNode = parenNodes -> prev;
            addNode(outList, parenNodes -> word);
            deleteNode(opList, parenNodes);//opTail);
            parenNodes = tempNode;
          }
          deleteNode(opList, parenNodes);
        }
      }
    }
    curNode = curNode -> next;
  }

  //Add the rest of the operator nodes
  opTail = opList -> tail;
  while(opTail != NULL) {
    addNode(outList, opTail -> word);
    deleteNode(opList, opTail);
    opTail = opList -> tail;
  }

  ListNode * outNode = outList -> head;
  ListNode * arithNode = arithlist -> head;

  //Copy values over
  while (outNode != NULL) {
    strcpy(arithNode -> word, outNode -> word);
    outNode = outNode -> next;
    arithNode = arithNode -> next;
  }

  //Delete extra nodes
  while (arithNode != NULL) {
    tempNode = arithNode -> next;
    deleteNode(arithlist, arithNode);
    arithNode = tempNode;
  }

  deleteList(outList);
  deleteList(opList);
  
  return true;
}
#endif
