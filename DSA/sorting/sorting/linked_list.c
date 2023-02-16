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
    // TODO: write your code here
	// for (int i = 1; i < n; i++)
	// {
	//	int temp = a[i];
	//	int j = i - 1;
	//	for (; j >= 0 && a[j] > temp; j--)
	//		a[j+1] = a[i];
	//	a[j + 1] = temp;
	//	}
	//
	if (is_empty(head) || (head->next == NULL))
	{
		return;
	}

	node *next_node = head->next;
	node *current_node = head;

	while (next_node != NULL)
	{
		next_node = next_node->next;
		int temp_value = next_node->data;
		node *prev_node = find_prev(head, next_node);
		while (prev_node != head && prev_node->data > temp)
		{
			swap_node(&prev_node, &p);
			prev_node = find_prev(head, prev);
		}
		prev_node->next->data = temp;
	}
}

void swap_node(node **p, node **q)
{
    // TODO: write your code here
	int temp = (*p)->data;
	(*p)->data = (*q)->data;
	(*q)->data = temp;
}

node *find_prev(node *head, node *p)
{
	node *
}
