#include <stdbool.h>
#include "Tree.h"


Tree* CreateParent(int data) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (!tree)
        return tree;
    tree->data = data;
    tree->left = NULL; tree->right = NULL;
    return tree;
}

Tree* AddNode(Tree** node, int data) {
    if (!(*node)) {
        *node = (Tree*)malloc(sizeof(Tree));
        if (!*node)
            return NULL;
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->data = data;
    }
    else {
        if (data < (*node)->data)
        {
            AddNode(&(*node)->left, data);
        }
        else
        {
            AddNode(&(*node)->right, data);
        }
    }
    return *node;
}

void PreOrder(Tree* node) {
    if (!node)
        return;
    printf("%d", node->data);
    PreOrder(node->left);
    PreOrder(node->right);
}

void FreeTree(Tree* root) {
    if (!root)
        return;
    if (root->left)
        FreeTree(root->left);
    if (root->right)
        FreeTree(root->right);
    free(root);
}

bool IsEmpty(Tree* node)
{
   if (node == NULL)
       return false;
   if (node->left == NULL && node->right == NULL)
       return true;
   return false;
}

void CutTree(Tree* node) {
    if (!node)
        return;
    if (IsEmpty(node->left) && IsEmpty(node->right))
    {
        free(node->left);
        node->left = NULL;
    }
    else 
    {
        CutTree(node->left);
        CutTree(node->right);
    }
}