//
//  main.c
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "bst.h"

int main(int argc, const char * argv[])
{
    int a[7] = {4, 9, 12, 8, 3, 10, 7};
    node* bst = create_bst(a, 7);
    in_order(bst);
    
    printf("\n");
    
    if (search_bst(bst, 8)) printf("Found!\n");
    else printf("Not found!\n");
    
    if (search_bst(bst, 18)) printf("Found!\n");
    else printf("Not found!\n");

	bst = delete_tree_node(bst, 4);
	in_order(bst);
	printf("\n");
    return 0;
}
