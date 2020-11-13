// ***
// *** DO NOT modify this file
// ***

#ifndef TREE_H
#define TREE_H

typedef struct tnode
{
  int value;
  struct tnode * left;
  struct tnode * right;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;

void freeTree(Tree * tr);
void preOrder(Tree * tr, char * filename);
Tree * buildTree(int * inArray, int * postArray, int size);
TreeNode * buildNode(int * inArray, int * postArray, int left, int right, int * postInd);
int search(int * arr, int value, int strt, int end);
#endif
