//
//  main.c
//  PriorityQueue
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "heap.h"

int qsize = 0;
#define MAX_SIZE 12

int main(int argc, const char * argv[])
{
    int keys[] =       {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int priorities[] = {1, 1, 1, 1, 2, 1, 3, 2, 1, 1,  3,  1};
    int n = 12;
    element queue[n];
    
    printf("Queue:\n");
    for (int order = 0; order < n; order++)
    {
        element e = {keys[order], priorities[order], order};
        enqueue(queue, e);
    }
    print_queue(queue);
    
    printf("Dequeue:\n");
    while (!is_empty())
    {
        element e = dequeue(queue);
        printf("[%d, %d, %d] ", e.key, e.priority, e.order);
    }
    printf("\n");
    
    return 0;
}
