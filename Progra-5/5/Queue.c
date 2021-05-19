 #include "Queue.h"

void Push(Queue* people,Item* person){
    person->ptrPrev = person->ptrNext = NULL;
    if(!people->head){
        people->head = people->tail = person;
    }
    else{
        person->ptrPrev = people->tail;
        people->tail->ptrNext = person;
        people->tail = person;
    }
    people->size++;
}

Item* Pick(Queue* people){
    return people->head;
}

void Pop(Queue* people){
    if (!people)
        return;
    Item* temp = people->head;
    people->head = people->head->ptrNext;
    free(temp);
    people->size--;
}

int GetSize(Queue* people){ return people->size; }

bool IsEmpty(Queue* people){
    if (!people)
    {
        return true;
    }
    return false;
}

void Delete(Queue* people){
    Item* temp = people->head;
    while(temp->ptrNext){
        temp = temp->ptrNext;
        free(temp->ptrPrev);
    }
    free(temp);   
}

int get_rand() {
    return rand() % (30 - 0 + 1) + 0;
}

Item* GeneratePerson(){
    int space , service;
    space = get_rand(); service = get_rand();
    Item* person = (Item*)malloc(sizeof(Item)); 
    if(!person)
        return person;
    person->space = space;
    person->service = service;
    return person;
}

Queue* GenerateSupermarket(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = 0; queue->head = queue->tail = NULL;
    if (!queue)
        return queue;
    Item* person;
    while (queue->size <= 10) {
        person = GeneratePerson();
        Push(queue, person);
    }
    return queue;
}