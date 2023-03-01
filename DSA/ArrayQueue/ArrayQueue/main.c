//
//  main.c
//  ArrayQueue
//
//  Created by TungDT on 7/30/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

int front = -1;
int rear = -1;
int queue[QUEUE_SIZE];

int main(int argc, const char * argv[])
{
    enqueue(5); enqueue(10); enqueue(8);
    while (!is_empty()) printf("%d ", dequeue());
    
    for (int i = 0; i <= QUEUE_SIZE; i++) enqueue(i);
    return 0;
}
