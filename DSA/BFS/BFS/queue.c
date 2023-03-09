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
    return front == -1;
}
int is_full(void)
{
    return rear == QUEUE_SIZE - 1;
}
void enqueue(const int n)
{
    if (is_empty())
    {
        front = rear = 0;
        queue[front] = n;
    }
    else if (!is_full())
    {
        queue[++rear] = n;
    }
    else overflow("Queue is full!\n");
}
int dequeue(void)
{
    if (is_empty())
    {
        overflow("Queue is empty!\n");
        return 0;
    }
    else if (front == rear)
    {
        int n = queue[front];
        clear_queue();
        return n;
    }
    else return queue[front++];
}
int size(void)
{
    if (is_empty()) return 0;
    else return rear - front + 1;
}

void overflow(char* msg)
{
    printf("Error: %s\n", msg);
}
