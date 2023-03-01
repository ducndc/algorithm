/**
 *	author: Chung Duc Nguyen Dang
 *	email: nguyendangchungduc1999@gmail.com
 *
 *	mobile_phone_managerment.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mobile_phone_managerment.h"

mobile_phone_t *add_a_new_mobile_phone_information()
{
	mobile_phone_t *new_mobile_phone;
	new_mobile_phone = (mobile_phone_t *)malloc(sizeof(mobile_phone_t));
	
	printf("Enter new mobile phone information\n");
	printf("Code of mobile phone:		");
	scanf("%s", &new_mobile_phone->code);
	printf("Name of mobile phone:		");
	scanf("%s", &new_mobile_phone->name);
	printf("Price of mobile phone:		");
	scanf("%d", &new_mobile_phone->price);
	printf("Inventory of mobile phone:	");
	scanf("%d", &new_mobile_phone->inventory);

	new_mobile_phone->next = NULL;

    return new_mobile_phone;
}

int is_empty(mobile_phone_t* const head)
{
	if (head == NULL)
	{
		return 1;
	}
	return 0;
}

void add_mobile_phone_in_list(mobile_phone_t **head)
{
	mobile_phone_t *new_mobile_phone = add_a_new_mobile_phone_information();

	if (is_empty(*head))
	{
		*head = new_mobile_phone;
		return;
	}
	
	mobile_phone_t *next_mobile_phone;
	mobile_phone_t *prev_mobile_phone;
	next_mobile_phone = *head;
	prev_mobile_phone = *head;

	if (new_mobile_phone->price >= next_mobile_phone->price) 
	{
		new_mobile_phone->next = *head;
		*head = new_mobile_phone;
		return;
	}
	
	if (new_mobile_phone->price <= next_mobile_phone->price && 
			next_mobile_phone->next == NULL)
	{
		(*head)->next = new_mobile_phone;
		return;
	}

	prev_mobile_phone = next_mobile_phone;
	next_mobile_phone = next_mobile_phone->next;

	while (next_mobile_phone != NULL)
	{
		if (new_mobile_phone->price >= next_mobile_phone->price)
		{
			new_mobile_phone->next = next_mobile_phone;
			prev_mobile_phone->next = new_mobile_phone;
			break;
		}

		prev_mobile_phone = next_mobile_phone;
		next_mobile_phone = next_mobile_phone->next;
	}
}

void remove_mobile_phone_in_list_by_code(mobile_phone_t **head)
{
	if (is_empty(*head))
	{
		printf("No mobile phone in list\n");
		return;
	}

	char code[MAX_CODE];
	printf("Enter code of mobile phone:	");
	scanf("%s", &code);

	mobile_phone_t *next_mobile_phone = *head;

	if (((*head)->next == NULL) && (!strcmp((*head)->code, code)))
	{
		free(*head);
		*head = NULL;
		return;
	}

	if (!strcmp((*head)->code, code))
	{
		mobile_phone_t *temp_mobile_phone = *head;
		*head = temp_mobile_phone->next;
		free(temp_mobile_phone);
		return;
	}

	mobile_phone_t *prev_mobile_phone = *head;

	while (next_mobile_phone != NULL)
	{
		printf("%s\n", next_mobile_phone->code);
		
		if (!strcmp(next_mobile_phone->code, code))
		{
			mobile_phone_t *temp_mobile_phone = next_mobile_phone;
			prev_mobile_phone->next = temp_mobile_phone->next;
			free(temp_mobile_phone);
			return;
		}
		prev_mobile_phone = next_mobile_phone;
		next_mobile_phone = next_mobile_phone->next;
	}
	
	printf("No mobile phone have code %s\n", code);
}

void edit_inventory_number_of_mobile_phone_by_code(mobile_phone_t *head)
{
	if (is_empty(head))
	{
		printf("No mobile phone in list\n");
		return;
	}

	char code[MAX_CODE];
	int new_inventory;

	printf("Edit inventory number of mobile phone by code\n");
	printf("Enter code of mobile phone:	");
	scanf("%s", &code);

	mobile_phone_t *next_mobile_phone = head;

	while (next_mobile_phone != NULL)
	{
		if (!strcmp(next_mobile_phone->code, code))
		{
			printf("Enter new inventory number of %s:	",
					next_mobile_phone->name);
			scanf("%d", &new_inventory);
			next_mobile_phone->inventory = new_inventory;
			return;
		}
		next_mobile_phone = next_mobile_phone->next;
	}

	printf("No mobile phone have %s\n", code);
}

void search_mobile_phone_by_price(mobile_phone_t *head)
{
	if (is_empty(head))
	{
		printf("No mobile phone in list\n");
		return;
	}
	
	int min_price;
	int price;

	printf("Search mobile phone by price\n");
	printf("Enter price of mobile phone:	");
	scanf("%d", &price);

	if (head->next == NULL)
	{
		printf("Goal mobile phone is %s\n", head->name); 
		printf("No up threshhold\n");
		printf("No down threshhold\n");
		return;
	}

	mobile_phone_t *next_mobile_phone = head;
	mobile_phone_t *right_mobile_phone = head;
	mobile_phone_t *prev_right_mobile_phone = head;
	min_price = next_mobile_phone->price - price;

	if (min_price < 0)
	{
		printf("Goal mobile phone is %s\n", right_mobile_phone->name); 
		printf("No up threshhold\n");
		printf("Down threshhold is %s\n", head->next->name);
	}

	while (next_mobile_phone != NULL)
	{
		if (abs(next_mobile_phone->price - price) < min_price)
		{
			min_price = next_mobile_phone->price - price;
			prev_right_mobile_phone = right_mobile_phone;
			right_mobile_phone = next_mobile_phone;
		}
		next_mobile_phone = next_mobile_phone->next;
	}

	if (right_mobile_phone->next == NULL)
	{
		printf("Goal mobile phone is %s\n", right_mobile_phone->name); 
		printf("Upper threshhold is %s\n", prev_right_mobile_phone->name);
		printf("No down threshhold\n");
	}
}

void print_mobile_phone_list(mobile_phone_t *head)
{
	if (is_empty(head))
	{
		printf("No mobile phone in list\n");
		return;
	}

	mobile_phone_t *next_mobile_phone = head;
	
	while (next_mobile_phone != NULL)
	{
		printf("=========================\n");
		printf("Phone code:	%s\n", next_mobile_phone->code);
		printf("Phone name:	%s\n", next_mobile_phone->name);
		printf("Price:		%d$\n", next_mobile_phone->price);
		printf("Inventory:	%d\n", next_mobile_phone->inventory);
		next_mobile_phone = next_mobile_phone->next;
	}
}

void print_instruction()
{
	printf("\n[1] Add new mobile phone\n");
	printf("[2] Remove a new mobile phone\n");
	printf("[3] Edit mobile phone information\n");
	printf("[4] Search mobile phone information by price\n");
	printf("[5] Print mobile phone list\n");
	printf("[6] End\n\n");
	printf("Choose option:	");
}

void reverse_mobile_phone_list(mobile_phone_t **head)
{
	mobile_phone_t* prev = NULL;
	mobile_phone_t* current = *head;
	mobile_phone_t* next = NULL;

	while (current != NULL) 
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
}
