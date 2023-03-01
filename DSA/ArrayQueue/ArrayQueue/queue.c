//
//  queue.c
//  ArrayQueue
//
//  Created by TungDT on 7/30/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "queue.h"

void clear_queue(void)
{
    front = rear = -1;
}
int is_empty(void)
{
    return front == -1 || front > rear;
}
int is_full(void)
{
    return rear == QUEUE_SIZE - 1;
}
void enqueue(const int n)
{
    // TODO: implement this function
	if (is_full()) overflow("full");
	if (is_empty()) front = 0;
	queue[++rear] = n;
}
int dequeue(void)
{
    // TODO: implement this function
    // check empty
    // check 1 element
    // more than 1 element
	if (is_empty()) overflow("empty");
	else { 
		int n = queue[front];
		if (front == queue) clear_queue();
		else front++;
		return n;
	}
}
int size(void)
{
    if (is_empty()) return 0;
    else return rear - front + 1;
}

void overflow(char* msg)
{
    printf("Error: %s\n", msg);
	exit(1);
}
