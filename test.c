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
#include "queue.h"

void main()
{
    printf("Welcome to the testing for a queue!\n");

    struct queue que;

    //Initialization test
    Initialize(&que, 4);
    printf("front: %d\nback: %d\nsize: %d\n", que.front, que.back, que.size);

    //Enqueue items
    Enqueue(&que, 10);
    Enqueue(&que, 20);
    Enqueue(&que, 30);
    Enqueue(&que, 40);
    Enqueue(&que, 50);
    for(int i = que.front; i < que.back; i++)
    {
        printf("%d: %d\n", i, que.values[i]);
    }

    //Dequeue items
    Dequeue(&que);
    Dequeue(&que);
    Dequeue(&que);
    Dequeue(&que);
    for(int i = que.front; i < que.back; i++)
    {
        printf("%d: %d\n", i, que.values[i]);
    }

    printf("front: %d\nback: %d\nsize: %d\n", que.front, que.back, que.size);
}