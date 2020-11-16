// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
Tree * buildTree(int * inArray, int * postArray, int size)
{
  int postInd = size - 1;
  Tree * binTree = malloc(sizeof(Tree));
  binTree -> root = buildNode(inArray, postArray, 0, size - 1, &postInd);
  return binTree;
}

TreeNode * buildNode(int * inArray, int * postArray, int strt, int end, int * postInd)
{
  //Zero Elements
  if (strt > end) {
    return NULL;
  }

  //Only one element
  else if (strt == end) {
    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = postArray[*postInd];
    node -> left = NULL;
    node -> right = NULL;
    * postInd = *postInd - 1;
    return node;
  }

  //Recursionn babyyyyy
  else {
    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = postArray[*postInd];
    int i = search(inArray, postArray[*postInd], strt, end); //Get the location of the post value in the inArray
    * postInd = *postInd - 1; //Used to iterate backwards through the post array
    node -> right = buildNode(inArray, postArray, (i + 1), end, postInd);
    node -> left = buildNode(inArray, postArray, strt, (i - 1), postInd);
    return node;
  }
}

int search(int * arr, int value, int strt, int end) {
  int i = 0;
  while (arr[i] != value && i < end) {
    i++;
  }
  return i;
}
#endif

#ifdef TEST_PRINTPATH
void printPath(Tree * tr, int val)
{
  searchTree(tr -> root, val);
}

int searchTree(TreeNode * node, int val) {
  //Base cases
  if (node == NULL) {
    return 0;
  }
  else if (node -> value == val) {
    printf("%d\n", val);
    return 1;
  }
  else {
    if (searchTree(node -> left, val)) {
      printf("%d\n", node -> value);
      return 1;
    }
    else if (searchTree(node -> right, val)) {
      printf("%d\n", node -> value);
      return 1;
    }
    else {
      return 0;
    }
  }
}
#endif
