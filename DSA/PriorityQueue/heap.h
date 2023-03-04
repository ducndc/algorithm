//
//  heap.h
//  PriorityQueue
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 12

typedef struct
{
    int key;
    int priority; // higher priority will be dequeued first
    int order;    // order of insertion, lower order will be dequeued first
} element;

extern int qsize;

void swap(element *a, element *b);
void print_queue(element* queue);
void heapify(element* queue, int i);     // heapify from index i
void enqueue(element* queue, element e);
element dequeue(element* queue);
int greater(element a, element b);       // compare if a is "greater" than b by priority and order
int is_empty(void);

#endif /* heap_h */
