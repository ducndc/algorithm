//
//  stack.h
//  ArrayStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

extern int stack[];
extern int top;

void clear_stack(void);
int is_empty(void);
int is_full(void);
void push(const int n);
int pop(void);
int size(void);

#endif /* stack_h */
