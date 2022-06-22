#ifndef QUEUE_H
#define QUEUE_H

#include <semaphore.h>
#include <pthread.h>
#include <limits.h>

struct queue 
{
	int front;  //keeps track of the index on the front of the queue
	int back;   //keeps track of the end of the end of the queue
	int size;   //how big the queue is
	int *values; //holder of the queue info
};

void Enqueue(struct queue* queue, int record);

void Dequeue(struct queue* threadHolder);

int Front(struct queue* queue, int record);

int Back(struct queue* queue);

int Empty(struct queue* queue);

int Full(struct queue* queue);

void Resize(struct queue* queue);

void Initialize(struct queue* queue, int size);

void Uninitialize(struct queue* queue);


#endif