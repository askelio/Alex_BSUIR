#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    int space;
    int service;
    struct item* ptrNext;
    struct item* ptrPrev;
} Item;

typedef struct Queue {
    Item* head; 
    Item* tail;
    int size;
} Queue;

void Push(Queue* people,Item* person);

int GetSize(Queue* people);

Item* Pick(Queue* people);

bool IsEmpty(Queue* people);

void Pop(Queue* people);

int get_rand();

Item* GeneratePerson();

Queue* GenerateSupermarket();

void Delete(Queue* people);