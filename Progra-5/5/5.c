#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Queue.c"

int main(){
    int Time;
    int size = 0, waiting = 0, maxWaiting = 0;
    Queue* queue = GenerateSupermarket();
    Item* person;
    srand(time(NULL));
    printf("Enter full time ");
    scanf("%d", &Time);
    while (Time >= 0)
    {
        if (IsEmpty(queue) && Time >= 0)
            queue = GenerateSupermarket();
        person = Pick(queue);
        waiting += person->service - person->space;
        Time -= (person->service + person->space);
        if (waiting < 0)
            waiting = 0;
        if (waiting > maxWaiting)
            maxWaiting = waiting;
        printf("For %d person wait for %d, service for %d\n", size, waiting, person->service);
        Pop(queue);
        size++;
    }

    printf("Quantity : %d\nMax waiting : %d\n", size, maxWaiting);
    Delete(queue);
    system("pause");
    return 0;
}

