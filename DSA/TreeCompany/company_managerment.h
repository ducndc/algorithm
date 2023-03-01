/**
 * author: Chung Duc Nguyen Dang
 * gmail:  nguyendangchungduc1999@gmail.com
 *
 * company_managerment.h
 *
 */
#ifndef COMPANY_MANAGERMENT_H
#define COMPANY_MANAGERMENT_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_STAFF	2
#define MAX_NAME	20

typedef struct staff_tree *child;

struct staff_tree {
	int id;
	char name[MAX_NAME];
	float sales;
	child staff[MAX_STAFF];
};

typedef struct staff_tree staff_tree_t;

staff_tree_t *create_staff_node();
staff_tree_t *create_staff_root();
void add_staff_to_company(staff_tree_t *root);
void post_order(staff_tree_t *const root);
void update_sales_in_company(staff_tree_t *const root);

#endif /* COMPANY_MANAGERMENT_H */

