//
//  heap.c
//  PriorityQueue
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "heap.h"


void swap(element *a, element *b)
{
    element temp = *a;
    *a = *b;
    *b = temp;
}

void print_queue(element* queue)
{
    for (int i = 0; i < qsize; i++)
        printf("[%d, %d, %d] ", queue[i].key, queue[i].priority, queue[i].order);
    printf("\n");
}

void heapify(element* queue, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int imax = i;
    
    if (left < qsize && greater(queue[left], queue[imax]))
        imax = left;
    if (right < qsize && greater(queue[right], queue[imax]))
        imax = right;
    
    if (imax != i)
    {
        swap(&queue[i], &queue[imax]);
        heapify(queue, imax);
    }
}

// compare if a is "greater" than b by priority and order
int greater(element a, element b)
{
    // TODO:
    // First compare by priority
    // Then compare by order (remind: queue is FIFO)
	if (a.priority > b.priority) return 1;
	if (a.priority < b.priority) return 0;
	if (a.order > b.order) return 0;
	return 1;
}

void enqueue(element* queue, element e)
{
    // TODO:
    // Check if queue is full then print error message and exit
    // If queueis not full, add e to the end of the queue
    // Then heapify the whole tree bottom-up
	if (qsize > MAX_SIZE) {
		exit(1);
	}
	else {
		queue[qsize] = e;
		qsize += 1;
		for (int i = qsize/2 - 1; i >= 0; i--) {
			heapify(queue, i);
		}
	}
}

element dequeue(element* queue)
{
    // TODO:
    // Check if queue is empty then print error message and exit
    
    // Get 1st element, save to e
    // Swap 1st element with last element
    // Remove last element by decreasing size of queue
    // Heapify new tree at the root
    // Return e
	if (is_empty()) {
		exit(1);
	}
	element tmp = queue[0];
	swap(&queue[0], &queue[qsize-1]);
	qsize -= 1;
	heapify(queue, 0);
	return tmp;

}

int is_empty()
{
    return qsize == 0;
}
