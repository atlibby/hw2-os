//
// Created by Andrew Libby on 9/20/23.
//

#ifndef UNTITLED7_PQUEUE_ATLIBBY_AKIRSCHT_H
#define UNTITLED7_PQUEUE_ATLIBBY_AKIRSCHT_H

#define MAX_NAME_LENGTH 63

typedef struct {
    unsigned int weight;
    char name[1 + MAX_NAME_LENGTH];
} Thing;

typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;



int enqueue(PQueueNode **pqueue, int priority, void *data);

void *dequeue(PQueueNode **pqueue);

void *peek(PQueueNode *pqueue);

void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

int getMinPriority(PQueueNode *pqueue);

int queueLength(PQueueNode *pqueue);

void printThing(void *data);




#endif //UNTITLED7_PQUEUE_ATLIBBY_AKIRSCHT_H
