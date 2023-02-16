/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * db_linked_list.h
 *
 */

#ifndef DB_LINKED_LIST_H
#define DB_LINKED_LIST_H

#include <stdlib.h>

typedef struct str_node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(const int data);

void add_tail(node **head, const int data);

int is_empty(node * const head);

void print_list(node * const head);

void insertion_sort(node *head, int n);

void swap_node(node **p, node **q);

#endif /* DB_LINKED_LIST_H */
