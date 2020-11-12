// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

Tree * buildTree(int * inArray, int * postArray, int size)
{
  if (size == 0) {
    Tree * tempTree = malloc(sizeof(Tree));
    tempTree -> root = NULL;
    return tempTree;
  }
  //Base case for terminating recursion
  else if (size == 1) {
    //Initialize and set
    Tree * tempTree = malloc(sizeof(Tree));
    TreeNode * tempLeaf = malloc(sizeof(TreeNode));
    tempLeaf -> left = NULL;
    tempLeaf -> right = NULL;
    tempLeaf -> value = inArray[0];
    tempTree -> root = tempLeaf;
    return tempTree;
  }
  //Base case for terminating recursion
  else if (size == 2) {
    //Initialize
    Tree * tempTree = malloc(sizeof(Tree));
    TreeNode * tempRoot = malloc(sizeof(TreeNode));
    TreeNode * tempLeaf = malloc(sizeof(TreeNode));
    tempLeaf -> left = NULL;
    tempLeaf -> right = NULL;

    //If it needs to be a left node
    if (inArray[1] == postArray[1]) {
      //Set values
      tempLeaf -> value = inArray[0];
      tempRoot -> right = NULL;
      tempRoot -> value = inArray[1];
      tempRoot -> left = tempLeaf;
    }
    //If it needs to be a right node
    else if (inArray[0] == postArray[1]) {
      //Set values
      tempLeaf -> value = inArray[1];
      tempRoot -> left = NULL;
      tempRoot -> value = inArray[0];
      tempRoot -> right = tempLeaf;
    }

    //Point tree to root and return
    tempTree -> root = tempRoot;
    return tempTree;
  }
  else {
    int lastVal = postArray[size - 1];
    int i = 0;

    //Iterate through to find location in inArray
    while (i < size && inArray[i] != lastVal) {
      i++;
    }

    Tree * mainTree = malloc(sizeof(Tree));
    TreeNode * tempNode = malloc(sizeof(TreeNode));
    tempNode -> value = postArray[size - 1];
    int j = 0;

    if (i == (size - 1)) {
      tempNode -> right = NULL;
      Tree * leftTree = NULL;

      int * tempPost = malloc(sizeof(int) * (size - 1));
      int * tempIn = malloc(sizeof(int) * (size - 1));

      for (j = 0; j < (size - 2); j++) {
        tempPost[j] = postArray[j];
        tempIn[j] = inArray[j];
      }

      leftTree = buildTree(inArray, postArray, (size - 1));
      tempNode -> left = leftTree -> root;
      

      free(leftTree);
      free(tempPost);
      free(tempIn);
      mainTree -> root = tempNode;
      return mainTree;
    }
    else if (i == 0) {
      tempNode -> left = NULL;
      Tree * rightTree = NULL;

      int * tempPost = malloc(sizeof(int) * (size - 1));
      int * tempIn = malloc(sizeof(int) * (size - 1));

      for (j = 0; j < (size - 2); j++) {
        tempPost[j] = postArray[j];
      }
      for (j = 1; j < (size - 1); j++) {
        tempIn[j] = inArray[j];
      }

      rightTree = buildTree(inArray, postArray, (size - 1));
      tempNode -> right = rightTree -> root;

      free(rightTree);
      free(tempPost);
      free(tempIn);
      mainTree -> root = tempNode;
      return mainTree;
    }
    else {
      Tree * tempTree = NULL; 
      Tree * tempTree2 = NULL;

      int * tempPostL = malloc(sizeof(int) * (i));
      int * tempInL = malloc(sizeof(int) * (i));
      int * tempPostR = malloc(sizeof(int) * (size - i - 1));
      int * tempInR = malloc(sizeof(int) * (size - i - 1));

      for (j = 0; j < i; j++) {
        tempPostL[j] = postArray[j];
      }
      for (j = 0; j < i; j++) {
        tempInL[j] = inArray[j];
      }
      for (j = 0; j < (size - i - 1); j++) {
        tempInR[j] = inArray[i + j + 1];
      }
      for (j = 0; j < (size - i - 1); j++) {
        tempPostR[j] = postArray[i + j];
      }

      tempTree = buildTree(tempInL, tempPostL, i);
      tempNode -> left = tempTree -> root;

      tempTree2 = buildTree(tempInR, tempPostR, (size - i - 1));
      tempNode -> right = tempTree2 -> root;

      mainTree -> root = tempNode;
      free(tempTree);
      free(tempTree2);
      free(tempPostL);
      free(tempInL);
      free(tempPostR);
      free(tempInR);
      //mainTree -> root = tempNode;
      return mainTree;
    }
  }
}
#endif
