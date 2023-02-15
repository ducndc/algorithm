#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node_t;

node_t *create_new_node(int const data)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

int is_empty(node_t *head)
{
	return (head == NULL);
}
void insert_head(node_t **head, int data)
{
	node_t *new_node = create_new_node(data);

	if (is_empty(*head))
	{
		*head = new_node;
		new_node->next = *head;
		return;
	}

	node_t *p = *head;
	
	while (p->next != *head)
	{
		p = p->next;
	}
	
	new_node->next = *head;
	*head = new_node;
	p->next = new_node;
}

void delete_head(node_t **head)
{
	if (is_empty(*head)) return;
	node_t *p = *head;
	node_t *temp = *head;
	if ((*head)->next == *head)
	{
		p = *head;
		*head == NULL;
		free(p);
		return;
	}

	while (p->next != *head)
	{
		p = p->next;
	}

	*head = (*head)->next;
	p->next = *head;
	free(temp);

}

void print_list(node_t *head)
{
	node_t *p = head;

	while (p->next != head)
	{
		printf("[%d]->", p->data);
		p = p->next;
	}
	printf("[%d]->", p->data);
}

int main()
{
	node_t *node_list = NULL;
	insert_head(&node_list, 2);
	insert_head(&node_list, 3);
	
	insert_head(&node_list, 4);
	print_list(node_list);
	delete_head(&node_list);
	print_list(node_list);

	return 0;
}
