//
//  queue.h
//  ArrayQueue
//
//  Created by TungDT on 7/30/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>

#define QUEUE_SIZE 100

extern int front;
extern int rear;
extern int queue[];

void clear_queue(void);
int is_empty(void);
int is_full(void);
void enqueue(const int n);
int dequeue(void);
int size(void);
void overflow(char* msg);

#endif /* queue_h */    
