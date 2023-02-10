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
    node *n;
    // TODO:
    // allocate node n
    // set data
    // set next to NULL
	n = (node *)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;

    return n;
}
int is_empty(node* const head)
{
    // TODO: 
    // check if head is NULL
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

void add_head(node **head, const int data)
{
    // TODO:
    // create node n with data
    // if empty list then set head to n
    // else set next of n to head, update head to n

	node *new_node = create_node(data);

	if (is_empty(*head))
	{
		*head = new_node;
		return;
	}

	new_node->next = *head;
	*head = new_node;
}

void remove_head(node **head)
{
    // TODO:
    // if empty list then return
    // else if head is the only node then free head and set head to NULL
	if (is_empty(*head))
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		free(*head);
		*head == NULL;
		return;
	}
	
	node *temp_node;
	temp_node = *head;
	*head = temp_node->next;

	free(temp_node);

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
