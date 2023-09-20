#include <stdio.h>
#include "pqueue.atlibby.akirscht.h"

int main() {
    printf("Hello, World!\n");
    return 0;
}

int enqueue(PQueueNode **pqueue, int priority, void *data){
    // ** Pointer to a pointer -> So we can change the value of the pointer

    /*This will put the data in the priority queue in the correct place.
    If there is already one or more nodes in the list having the same priority as the data that you are enqueueing,
    then put the new node after all of the existing nodes having that priority. Return zero from this function.*/
    PQueueNode* front;

    //Creates pointer to a PQueueNode
    PQueueNode *newNode = /*(PQueueNode*)*/malloc(sizeof(PQueueNode));

    newNode->priority = priority;
    newNode->data = data;
    newNode->next = NULL;

    if (*pqueue == NULL) {
        // If the queue is empty, set front to the new node
        *pqueue = newNode;
    } else {
        PQueueNode *current = *pqueue;
        while (current->next != NULL && priority >= current->next->priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }


    return 0;
}

void *dequeue(PQueueNode **pqueue){

}

void *peek(PQueueNode *pqueue){

}

void printQueue(PQueueNode *pqueue, void (printFunction)(void*)){

}

int getMinPriority(PQueueNode *pqueue){

}

int queueLength(PQueueNode *pqueue){

}

void printThing(void *data){

}

