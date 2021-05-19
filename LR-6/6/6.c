#include <stdio.h>
#include <stdlib.h>
#include "Tree.c"

int main(){
    Tree* tree = CreateParent(3);
    AddNode(&tree, 5);
    AddNode(&tree, 1);
    AddNode(&tree, 2);
    AddNode(&tree, 4);
    AddNode(&tree, 6);
    
    PreOrder(tree);

    CutTree(tree);
    PreOrder(tree);
    FreeTree(tree);
    system("pause");
    return 0;
}