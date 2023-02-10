//
//  linked_list.h
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

typedef struct str_node * link;
struct str_node
{
    int data;
    link next;
};

typedef struct str_node node;

node* create_node(const int data);
int is_empty(node* const head);
void add_head(node **head, const int data);
void remove_head(node **head);
void print_list(node* const head);
void clear_list(node **head);


#endif /* linked_list_h */
