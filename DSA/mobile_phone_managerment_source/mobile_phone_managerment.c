#include <stdlib.h>
#include <stdio.h>

#include "mobile_phone_managerment.h"

mobile_phone_t* add_a_new_mobile_phone_information()
{
	mobile_phone_t *new_mobile_phone;
	new_mobile_phone = (mobile_phone_t *)malloc(sizeof(mobile_phone_t));
	
	printf("Enter new mobile phone information\n");
	printf("Code of mobile phone:	");
	scanf("%s", &new_mobile_phone->code);
	printf("Name of mobile phone:	");
	scanf("%s", &new_mobile_phone->name);
	printf("Price of mobile phone:	");
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
		*head = new_mobile_phone_t;
		return;
	}
	
	mobile_phone_t *next_mobile_phone;
	next_mobile_phone = *head;

	while (next_mobile_phone->next != NULL)
	{
		if (new_mobile_phone->price > next_mobile_phone->next->price)
		{
			new_mobile_phone_t->next = *head;
			*head = new_mobile_phone_t;
		}
		next_mobile_phone = next_mobile_phone->next;
	}
}

mobile_phone_t *search_mobile_phone_by_code(mobile_phone_t **head, int code)
{

}

void remove_mobile_phone_in_list_by_code(mobile_phone_t **head)
{
	if (is_empty(*head))
	{
		printf("No mobile phone in list");
		return;
	}

	int code;
	printf("Enter code of mobile phone:	");
	scanf("%d", &code);

	if ((*head)->next == NULL && ((*head)->code == code))
	{
		free(*head);
		*head == NULL;
		return;
	}

	mobile_phone_t *next_mobile_phone = *head->next;
	mobile_phone_t *prev_mobile_phone = *head->next;

	while (next_mobile_phone->next != NULL)
	{
		if (next_mobile_phone->code == code)
		{
			mobile_phone_t *temp_mobile_phone = next_mobile_phone;
			prev_mobile_phone->next = temp_mobile_phone_t->next;
			free(temp_mobile_phone);
		}
		prev_mobile_phone = next_mobile_phone;
		next_mobile_phone = next_mobile_phone->next;
	}
}

void print_list(mobile_phone_t* const head)
{
    if (is_empty(head)) printf("Empty list!\n");
    else
    {
        mobile_phone_t *p = head;
        while (p != NULL)
        {
            printf("[%d]->", p->data);
            p = p->next;
        }
        printf("[]\n");
    }
}
