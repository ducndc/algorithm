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
    // TODO: allocate stack, set top = -1
	stack = (int *)calloc(1, stack_size * sizeof(int));
	top = -1;
	
}
void clear_stack(void)
{
    // TODO: deallocate stack, set top = -1
	free(stack);
	top = -1;
}
void push(const int n)
{
    // TODO: If full then reallocate stack, 
    // increase stack_size by INC_SIZE then update top
	if (is_full())
	{
		stack = realloc(stack, stack_size + INC_SIZE);
	}
	stack[++top] = n;
}

int is_empty(void)
{
    return top == -1;
}
int is_full(void)
{
    return top == stack_size - 1;
}

int pop(void)
{
    if (!is_empty()) return stack[top--];
    else
    {
        printf("Invalid postfix!\n");
        exit(1);
    }
}
int get_size(void)
{
    return top + 1;
}


