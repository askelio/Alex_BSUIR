#include "Tree.c"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void TestCreateTree(){
    Tree* tree = CreateParent(3);
    assert(tree->data == 3);
}

void TestAddNode(){
    Tree* tree = CreateParent(3);
    AddNode(&tree,5);
    AddNode(&tree,1);
    assert(tree->left->data == 1);
    assert(tree->right->data == 5);
}

#undef main

int main(){
    TestCreateTree();
    TestAddNode();
    return 0;
}