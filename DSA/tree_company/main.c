/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * main.c
 *
 */

#include <stdio.h>

#include "company_managerment.h"

int main()
{
	staff_tree_t *root = NULL;

	root = create_staff_root();

	add_staff_to_company(root);

	for (int i = 0; i < MAX_STAFF; i++)
	{
		add_staff_to_company(root->staff[i]);
	}

	post_order(root);

	update_sales_in_company(root);

	post_order(root);

	return 0;
}
