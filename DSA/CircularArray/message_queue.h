//
//  message_queue.h
//  CircularArray
//
//  Created by TungDT on 8/1/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef message_queue_h
#define message_queue_h

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5
#define TRUE 1
#define FALSE 0

extern int front;
extern int rear;
extern char* msg_queue[BUFFER_SIZE];

//void init_queue(void);
void clear_queue(void);
int is_empty(void);
int is_full(void);
void enqueue(char* msg);
char* dequeue(void);
int size(void);
void overflow(char* msg);

#endif /* message_queue_h */
