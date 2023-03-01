//
//  stack.c
//  ArrayStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "stack.h"

void init_stack(void)
{
    stack = (int*) malloc(stack_size * sizeof(int));
    top = -1;
}
void clear_stack(void)
{
    if (stack != NULL) {
        top = -1;
        free(stack);
        stack = NULL;
    }
}
int is_empty(void)
{
    return top == -1;
}
int is_full(void)
{
    return top == stack_size - 1;
}
void push(const int n)
{
    if (is_full())
    {
        stack_size += INC_SIZE;
        stack = (int*) realloc(stack, stack_size * sizeof(int));
    }
    stack[++top] = n;
}
int pop(void)
{
    if (!is_empty()) {
        return stack[top--];
    } else {
        printf("Empty stack!\n");
        exit(1);
    }
}
int get_size(void)
{
    return top + 1;
}


