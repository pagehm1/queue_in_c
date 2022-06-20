/****************************************
*Name: Hunter Page, pagehm1@etsu.edu
*File Name: queue.c
*Date Last Modified: 6/20/2022
*
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>
#include <queue.h>

//Initializes the queue to its default values, including the size of the queue
void Initialize(struct queue* queue)
{
	queue->front = 0;
	queue->back = 0;
	queue->id = 0;
	queue->size = 1024;
	queue->values = malloc(sizeof(int)*1024);
}

//initializes the queue to its default values and the size of the queue
void Initialize(struct queue* queue, int size)
{
	queue->front = 0;
	queue->back = 0;
	queue->id = 0;
	queue->size = size;
	queue->values = malloc(sizeof(int)*size);
}


//adds a number to the queue
void Enqueue(struct queue* queue, int record)
{
	//if we are full, add to the queue
	if(Full(queue) == 1)
	{
		Resize(queue, 1);
	}
	else
	{
		//initialize the front of the queue
		if(queue->front == -1)
		{
			queue->front = 0;
		}

		queue->values[queue->back] = record;

		queue->back++;
	}
}

//Changes the front of the queue so that a number is
//inaccessible, or removed from the queue
void Dequeue(struct queue* threadHolder)
{
	if(threadHolder->front == -1 || threadHolder->front > threadHolder->back)
	{
		printf("Thread is empty");
	}
	
	threadHolder->front++;	
}

//grabs the 'first' item entered into the queue
int Front(struct queue* que, int record)
{
	return que->values[que->front];
}

//grabs the last item entered into the queue
int End(struct queue* que)
{
	return que->values[que->back];
}

//set the amount of records that can be held in the queue based on the size passed in
void Resize(struct queue* queue, int size)
{
	queue->values = (int *) realloc(queue->values, size);
}

//set the amount of records that can be held in the queue
void Resize(struct queue* queue)
{
	queue->size = queue->size*2;
	queue->values = (int *) realloc(queue->values, queue->size);
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

