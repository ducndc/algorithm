/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * company_managerment.c
 *
 */

#include "company_managerment.h"

staff_tree_t *create_staff_node()
{
	staff_tree_t *new_staff = (staff_tree_t *)malloc(sizeof(staff_tree_t));

	if (new_staff == NULL)
	{
		printf("malloc fail!");
		return NULL;
	}

	printf("Enter ID of staff: ");
	scanf("%d", &new_staff->id);
	printf("Enter name of staff: ");
	scanf("%s", &new_staff->name);
	printf("Enter sales of staff: ");
	scanf("%f$", &new_staff->sales); 

	return new_staff;
}

staff_tree_t *create_staff_root()
{
	staff_tree_t *new_root = (staff_tree_t *)malloc(sizeof(staff_tree_t));

	if (new_root == NULL)
	{
		printf("malloc fail!");
		return NULL;
	}

	new_root->id = 0;
	printf("Enter name of company: ");
	scanf("%s", &new_root->name);

	new_root->sales = 0; 

	return new_root;
}

void add_staff_to_company(staff_tree_t *root)
{
	int i = 0;
	for (i = 0; i < MAX_STAFF; i++)
	{
		root->staff[i] = create_staff_node();
	}
}

void post_order(staff_tree_t *const root)
{
    if (root == NULL)
        return;

	for (int i = 0; i < MAX_STAFF; i++)
		post_order(root->staff[i]);
	printf("ID	:	%d \n", root->id);
    printf("Name	:	%s \n", root->name);
	printf("Sales	:	%f \n", root->sales);

}

void update_sales_in_company(staff_tree_t *const root)
{
	if (root == NULL)
		return;

	for (int i = 0; i < MAX_STAFF; i++)
	{
		if (root->staff[i] == NULL)
			continue;
		update_sales_in_company(root->staff[i]);
		root->sales += root->staff[i]->sales * 0.3;
	}
	root->sales = root->sales * 0.7;
}
