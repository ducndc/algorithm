//
//  message_queue.c
//  CircularArray
//
//  Created by TungDT on 8/1/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "message_queue.h"
#include <string.h>
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
    if (front == rear + 1) return TRUE;
    if (front == 0 && rear == BUFFER_SIZE - 1) return TRUE;
    return FALSE;
}
void enqueue(char* msg)
{
    if (is_full()) overflow("Queue is full!");
    else
    {
        if (is_empty()) front = 0;
        rear = (rear + 1) % BUFFER_SIZE;
        msg_queue[rear] = msg;
    }
}
char* dequeue(void)
{
    if (is_empty()) overflow("Queue is empty!");
    else
    {
        char* msg = msg_queue[front];
        if (front == rear) clear_queue();
        else front = (front + 1) % BUFFER_SIZE;
        return msg;
    }

}
int size(void)
{
    if (front <= rear) return rear - front + 1;
    else return BUFFER_SIZE - front - rear + 1;
}
void overflow(char* msg)
{
    printf("%s\n", msg);
    exit(1);
}
