//
//  linked_list.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

#define DUCNDC

node* create_node(const int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

int is_empty(linked_list list)
{
    return list.head == NULL;
}

void add_head(linked_list *list, const int data)
{
    node *n = create_node(data);
    n->next = list->head;
    list->head = n;
    if (list->tail == NULL)
        list->tail = n;
    list->n++;
}

void add_tail(linked_list *list, const int data)
{
    node *n = create_node(data);
    if (list->tail == NULL)
        list->head = list->tail = n;
    else
    {
        list->tail->next = n;
        list->tail = n;
    }
    list->n++;
}

void print_list(linked_list list)
{
    node *p = list.head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void clear_list(linked_list *list)
{
    node *p = list->head;
    while (p != NULL)
    {
        node *q = p;
        p = p->next;
        free(q);
    }
    list->head = NULL;
    list->tail = NULL;
    list->n = 0;
}

void merge_sort(linked_list *list)
{
    if (list->n <= 1)
        return;
    linked_list left, right;
    left.head = right.head = NULL;
    left.tail = right.tail = NULL;

    left.n = right.n = 0;

    // TODO:
    // - copy half of list to left
    // - copy the other half to right
    // - call merge_sort to sort left
    // - call merge_sort to sort right
    // - clear list
    // - call merge to merge left and right to list
#ifdef DUCNDC
    node *p = list->head;
    for (int i = 0; i < (int)(list->n / 2); i++)
    {
        add_tail(&left, p->data);
        p = p->next;
    }
    for (int i = (int)(list->n/2); i < list->n; i++)
    {
        add_tail(&right, p->data);
        p = p->next;
    }
    merge_sort(&left);
    merge_sort(&right);
    clear_list(list);
    merge(&list, &left, &right);
#endif
}

void merge(linked_list *list, linked_list *left, linked_list *right)
{
    node *p = left->head;
    node *q = right->head;
    while (p != NULL && q != NULL)
    {
        // TODO: add the smaller one to list until one of p or q is NULL
        if (p->data < q->data)
        {
            add_tail(&list, q->data);
            q = q->next;
        }
        else
        {
            add_tail(&list, p->data);
            p = p->next;
        }
    }
    // TODO: add the remaining nodes of p or q to list
    while (p != NULL)
    {
        add_tail(&list, p->data);
        p = p->next;
    }
    while (q != NULL)
    {
        add_tail(&list, q->data);
        q = q->next;
    }
    clear_list(left);
    clear_list(right);
}