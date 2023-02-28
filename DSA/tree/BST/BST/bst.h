//
//  bst.h
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdlib.h>
#include <stdio.h>

typedef struct str_node node;

struct str_node
{
    int key;
    node *left;
    node *right;
};

node* create_node(const int key);             // create a single node
void insert_node(node **root, const int key); // insert a node into a BST from root
void insert_child(node **child, node* n);     // insert a node into a BST from a child
node* create_bst(int *a, const int n);        // create a BST from an array
node* search_bst(node *root, const int key);  // search a node that contains a key in a BST
void in_order(node *root);                    // print a BST in-order
node *delete_tree_node(node *root, const int key);

node *find_min_on_right(node *root);

#endif /* bst_h */
