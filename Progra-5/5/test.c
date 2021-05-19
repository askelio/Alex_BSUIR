#include "Queue.c"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void TestIsEmpty(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    assert(IsEmpty(queue) == true);
    Queue* queue1 = GenerateSupermarket();
    assert(IsEmpty(queue) == false);
}

void TestGetSize(){
    Queue* queue = GenerateSupermarket();
    assert(GetSize(queue) == 10);
}

#undef main

int main(){
    TestIsEmpty();
    TestGetSize();
    return 0;
}