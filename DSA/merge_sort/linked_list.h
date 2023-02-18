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
typedef struct str_list
{
    node *head;
    node *tail;
    int n;
} linked_list;

node* create_node(const int data);
int is_empty(linked_list list);
void add_head(linked_list *list, const int data);
void add_tail(linked_list *list, const int data);
void print_list(linked_list list);
void clear_list(linked_list *list);

void merge_sort(linked_list *list);
void merge(linked_list *list, linked_list *left, linked_list *right);

#endif /* linked_list_h */
