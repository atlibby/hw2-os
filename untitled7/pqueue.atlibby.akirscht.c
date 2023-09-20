#include <stdio.h>
#include <stdlib.h>
#include "pqueue.atlibby.akirscht.h"

// This will put the data in the priority queue in the correct place. If there is already one or more nodes in
//the list having the same priority as the data that you are enqueueing, then put the new node after all of the
//existing nodes having that priority. Return zero from this function.
int enqueue(PQueueNode **pqueue, int priority, void *data){
// ** Pointer to a pointer -> So we can change the value of the pointer

    /*This will put the data in the priority queue in the correct place.
    If there is already one or more nodes in the list having the same priority as the data that you are enqueueing,
    then put the new node after all of the existing nodes having that priority. Return zero from this function.*/
    PQueueNode* front;

    //Creates pointer to a PQueueNode
    PQueueNode *newNode = (PQueueNode*)malloc(sizeof(PQueueNode));

    newNode->priority = priority;
    newNode->data = data;
    newNode->next = NULL;

    if (*pqueue == NULL) {
        // If the queue is empty, set front to the new node
        *pqueue = newNode;
} else if (priority < (*pqueue)->priority) {
        // If the new node has a lower priority than the front of the queue, set the new node to the front
        newNode->next = *pqueue;
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

// Remove the front of the list and return the data from that list node (not the list node itself). If the pqueue
//is empty, then return NULL. Free the queue node itself in your function (but not the data!)
void *dequeue(PQueueNode **pqueue){
    if (*pqueue == NULL) {
        return NULL;
    }
    PQueueNode *front = *pqueue;
    void *data = front->data;
    *pqueue = front->next;
    free(front);
    return data;
}

// Return the data from the first node in the pqueue (not the node itself). If the pqueue is empty, then return
//NULL. The peek operation does not actually remove a node from the pqueue!
void *peek(PQueueNode *pqueue){
    if (pqueue == NULL) {
        return NULL;
    }
    return pqueue->data;
}

//Print the data from each node in the queue. The second parameter is the name of the function that will be
//used to print the data of each node.
void printQueue(PQueueNode *pqueue, void (printFunction)(void*)){
    PQueueNode *current = pqueue;
    while (current != NULL) {
        printFunction(current->data);
        current = current->next;
    }
}

// Return the priority of the first node in the pqueue. If the pqueue is empty, then return -1.
int getMinPriority(PQueueNode *pqueue){
    if (pqueue == NULL) {
        return -1;
    }
    return pqueue->priority;
}

// Return the number of nodes in the pqueue.
int queueLength(PQueueNode *pqueue){
    int count = 0;
    PQueueNode *current = pqueue;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Print the name and weight of the Thing pointed to by data.
void printThing(void *data){
    Thing *thing = (Thing*)data;
    printf("%s (%u lbs)\n", thing->name, thing->weight);
}

