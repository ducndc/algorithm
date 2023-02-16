//
//  linked_list.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "utils.h"

node* create_node(const int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
int is_empty(node* const head)
{
    return head == NULL;
}

void add_head(node **head, const int data)
{
    node *n = create_node(data);
    if (is_empty(*head)) *head = n;
    else
    {
        n->next = *head;
        *head = n;
    }
    
}
void remove_head(node **head)
{
    if (is_empty(*head)) return;
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}

void print_list(node* const head)
{
    if (is_empty(head)) printf("Empty list!\n");
    else
    {
        node *p = head;
        while (p != NULL)
        {
            printf("[%d]->", p->data);
            p = p->next;
        }
        printf("[]\n");
    }
}

void clear_list(node **head)
{
    if (is_empty(*head)) return;
    while (*head != NULL)
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}

void insertion_sort(node *head)
{
    if (is_empty(head)) return;      // 0 items
    if (head->next == NULL) return;  // 1 items

    node *p = head->next;
    while (p != NULL)
    {   
        int temp = p->data;
        node *prev = find_prev(head, p);
        while (prev != NULL && prev->data > temp)
        {
            swap_node(&prev, &prev->next);
            prev = find_prev(head, prev);
        }
        if (prev != NULL) prev->next->data = temp;

        p = p->next;
    }
    
}

void swap_node(node **p, node **q)
{
    int temp = (*p)->data;
    (*p)->data = (*q)->data;
    (*q)->data = temp;
}

node* find_prev(node *head, node *p)
{
    node *q = head;
    while (q != NULL)
    {
        if (q->next == p) return q;
        q = q->next;
    }
    return NULL;
}

int find_max_rec_of_ll(node *head)
{
    if (head->next == NULL) return head->data;
    return (MAX_2_ELEMENTS(head->data, find_max_rec_of_ll(head->next)));
}

int sum_array_rec_of_ll(node *head)
{
    if (head->next == NULL) return head->data;
    return (SUM_2_ELEMENTS(head->data, sum_array_rec_of_ll(head->next)));
}