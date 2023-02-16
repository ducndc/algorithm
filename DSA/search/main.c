/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * main.c
 *
 */

#include <stdio.h>

#include "utils.h"

#define DB_LL

#ifndef DB_LL
#include "linked_list.h"
#else
#include "db_linked_list.h"
#endif

#define MAX_ARR_SIZE 5


int main()
{
	int arr[MAX_ARR_SIZE] = {9, 8, 1, 3, 2};

	printf("Max of array %d\n", find_max_rec(arr, MAX_ARR_SIZE));
	printf("Sum of array %d\n", sum_array_rec(arr, MAX_ARR_SIZE));

#ifndef DB_LL
	printf("Single Linked List\n");
	node* list = NULL;
	add_head(&list, 1);
	add_head(&list, 2);
	add_head(&list, 10);
	add_head(&list, 4);
	add_head(&list, 9);
	printf("Max of linked list %d\n", find_max_rec_of_ll(list));
	printf("Sum of linked list %d\n", sum_array_rec_of_ll(list));
#else
	printf("Doubly Linked List\n");
	node *head = NULL;
	add_tail(&head,5);
	add_tail(&head,2);
	add_tail(&head,3);
	add_tail(&head,0);
	print_list(head);
	insertion_sort(head,4);
	print_list(head);
#endif
	return 0;
}
