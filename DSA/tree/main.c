//
//  main.c
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

tree_node* build_test_tree(void);

int main(int argc, const char * argv[])
{
    tree_node *root = build_test_tree();
    
    printf("In-order :  ");  in_order(root);   printf("\n");
    printf("Pre-order:  ");  pre_order(root);  printf("\n");
    printf("Post-order: ");  post_order(root); printf("\n");
    
    clear_tree(&root);
    return 0;
}

tree_node* build_test_tree(void)
{
    tree_node* a = create_node('a');
    tree_node* b = create_node('b');
    tree_node* c = create_node('c');
    tree_node* d = create_node('d');
    tree_node* e = create_node('e');
    tree_node* f = create_node('f');
    tree_node* g = create_node('g');
    tree_node* h = create_node('h');
    tree_node* i = create_node('i');
    tree_node* j = create_node('j');
    tree_node* k = create_node('k');
    tree_node* l = create_node('l');
    tree_node* m = create_node('m');
    tree_node* n = create_node('n');
    tree_node* o = create_node('o');
    tree_node* p = create_node('p');
    
    a->children[0] = b; a->children[1] = c; a->children[2] = d;
    b->children[0] = e; b->children[1] = f;
    d->children[0] = g; d->children[1] = h; d->children[2] = i;
    e->children[0] = j; e->children[1] = k;
    g->children[0] = l; g->children[1] = m;
    k->children[0] = n; k->children[1] = o; k->children[2] = p;
    
    return a;
}
