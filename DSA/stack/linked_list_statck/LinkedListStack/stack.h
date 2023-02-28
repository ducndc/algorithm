//
//  stack.h
//  LinkedListStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct str_position position;
struct str_position
{
    int x;
    int y;
    char c;
};
typedef struct str_move move;
struct str_move
{
    position pos;
    move* next;
};

move* create_move(position pos);
int is_empty(move* stack);
void push(move** stack, position pos);
position pop(move** stack);
void clear_stack(move** stack);
position* to_array(move* stack);
int get_size(move* stack);

#endif /* stack_h */
