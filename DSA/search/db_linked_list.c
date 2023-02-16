/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * db_linked_list.c
 *
 */
#include <stdio.h>

#include "db_linked_list.h"

node *create_node(const int data)
{
	node *n = (node*)malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void add_tail(node **head, const int data)
{
	node *n = create_node(data);

	if (is_empty(*head))
		*head = n;
	else
	{
		node *temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = n;
		n->prev = temp;
	}
}

int is_empty(node * const head)
{
	return head == NULL;
}

void print_list(node * const head)
{
	node *p = head;
	while (p != NULL)
	{
		printf("[%d] ", p->data);
		p = p->next;
	}
	printf("\n");
}

void insertion_sort(node *head, int n)
{
	if (is_empty(head))
		return;

	if (head->next == NULL)
		return;

	node *p = head->next;

	while (p != NULL)
	{
		int temp = p->data;
		node *prev = p->prev;

		while ((prev != NULL) && (prev->data > temp))
		{
			swap_node(&prev->next,&prev);
			prev = prev->prev;
		}
		if (prev != NULL)
		{
			node *temp_node = prev->next;
			temp_node->data = temp;
		}
		p = p->next;
	}
}

void swap_node(node **p, node **q)
{
	int temp = (*p)->data;
	(*p)->data = (*q)->data;
	(*q)->data = temp;
}