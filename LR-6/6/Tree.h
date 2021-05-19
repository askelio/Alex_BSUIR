#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    struct Tree* left;
    struct Tree* right;
    int data;
} Tree;

Tree* AddNode(Tree** node, int data);

Tree* CreateParent(int data);

void FreeTree(Tree* root);

void PreOrder(Tree* node);

void CutTree(Tree* node) ;

bool IsEmpty(Tree* node);