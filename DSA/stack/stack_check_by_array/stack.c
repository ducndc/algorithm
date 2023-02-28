//
//  stack.c
//  ArrayStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "stack.h"

void clear_stack()
{
    top = -1;
}
int is_empty()
{
    return top == -1;
}
int is_full()
{
    return top == STACK_SIZE - 1;
}
void push(const int n)
{
    if (!is_full()) stack[++top] = n;
    else printf("Stack overflow!\n");
}
int pop()
{
    if (!is_empty()) return stack[top--];
    else 
    {
        printf("Stack underflow!\n");
        exit(1);
    }
}
int size()
{
    return top + 1;
}
