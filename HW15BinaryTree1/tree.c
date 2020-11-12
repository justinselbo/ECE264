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
  return buildNode(inArray, postArray, 0, size - 1, size - 1);
}
#endif

#ifdef TEST_BUILDNODE
TreeNode * buildNode(int * inArray, int * postArray, int strt, int end, int postInd)
{
  //0 Elements
  if (strt > end) {
    return NULL;
  }

  //Only one element
  else if (str == end) {
    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = inArray[0];
    node -> left = NULL;
    node -> right = NULL;
    return node;
  }

  //Recursionn babyyyyy
  else {
    TreeNode * node = malloc(sizeof(TreeNode));
    node -> value = postArray[postInd];
    int i = search(inArray, postArray[postInd], strt, end);
    node -> left = buildNode(inArray, postArray, strt, (start + i - 1), (start + i - 1));
    node -> right = buildNode(inArray, postArray, (i + 1), end, (postInd - 1));
  }
}
#endif

#ifdef TEST_SEARCH
int search(int * arr, int value, int strt, int end) {
  int i = 0;
  while (arr[i] != value && i < end) {
    i++;
  }
  return i;
}
#endif