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

typedef struct mobile_phone *link;

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

void remove_mobile_phone_in_list(mobile_phone_t **head, int code);

void edit_mobile_phone_information_in_list(mobile_phone_t **head, int code);

void search_mobile_phine_in_list(mobile_phone_t **head, int price);

void print_mobile_phone_list(mobile_phone_t **head);




