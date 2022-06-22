/****************************************
*Name: Hunter Page
*File Name: queue.c
*Date Last Modified: 6/22/2022
*
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>
#include "queue.h"

//initializes the queue to its default values and the size of the queue
void Initialize(struct queue* queue, int size)
{
	queue->front = 0;
	queue->back = 0;
	queue->size = size;
	queue->values = malloc(sizeof(int)*size);
}


//adds a number to the queue
void Enqueue(struct queue* queue, int record)
{
	//if we are full, add to the queue
	if(Full(queue) == 1)
	{
		Resize(queue);
	}

	queue->values[queue->back] = record;
	queue->back++;
}

//Changes the front of the queue so that a number is
//inaccessible, or removed from the queue
void Dequeue(struct queue* queue)
{
	queue->front++;	
}

//grabs the 'first' item entered into the queue
int Front(struct queue* que, int record)
{
	return que->values[que->front];
}

//grabs the last item entered into the queue
int Back(struct queue* que)
{
	return que->values[que->back];
}

//set the amount of records that can be held in the queue
void Resize(struct queue* queue)
{
	queue->size = queue->size*2;
	queue->values = (int *) realloc(queue->values, sizeof(int)*queue->size);
}

//returns whether the queue is full
//0: not full
//1: full
int Full(struct queue* queue)
{
	if(queue->back == queue->size)
	{
		return 1;
	}

	return 0;
}