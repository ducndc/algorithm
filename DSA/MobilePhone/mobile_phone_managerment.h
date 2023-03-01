/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * mobile_phone_managerment.h
 *
 */

#ifndef MOBILE_PHONE_MANAGERMENT_H
#define MOBILE_PHONE_MANAGERMENT_H

#define MAX_CODE	10
#define MAX_NAME	20

typedef struct mobile_phone link;

struct mobile_phone {
	char code[MAX_CODE];
	char name[MAX_NAME];
	int price;
	int inventory;
	link *next;
};

typedef struct mobile_phone mobile_phone_t;

mobile_phone_t *add_a_new_mobile_phone_information();

int is_empty(mobile_phone_t* const head);

void add_mobile_phone_in_list(mobile_phone_t **head);

void remove_mobile_phone_in_list_by_code(mobile_phone_t **head);

void edit_inventory_number_of_mobile_phone_by_code(mobile_phone_t *head);

void search_mobile_phone_by_price(mobile_phone_t *head);

void print_mobile_phone_list(mobile_phone_t *head);

void print_instruction();

void reverse_mobile_phone_list(mobile_phone_t **head);

#endif


