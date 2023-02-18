//
//  tree.c
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "tree.h"

tree_node* create_node(const char data)
{
    tree_node* n = (tree_node*) malloc(sizeof(tree_node));
    n->data = data;
    
    for (int i = 0; i < MAX_CHILDREN; i++)
        n->children[i] = NULL;
    
    return n;
}

void clear_tree(tree_node **root)
{
    // TODO
    // - check if root is NULL then return
    // - clear all children of root by calling clear_tree() recursively
    // - free root
    // - set root to NULL
    if (*root == NULL) return;

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        clear_tree(&(*root)->children[i]);
    }

    free(*root);
    *root = NULL;
}
void in_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    // - print left child by calling in_order() recursively
    // - print root data
    // - print right children by calling in_order() recursively
    if (root == NULL)
        return;

    in_order(root->children[0]);
    printf("%c ", root->data);

    for (int i = 1; i < MAX_CHILDREN; i++)
        in_order(root->children[i]);

}

void pre_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    // - print root data
    // - print left child by calling pre_order() recursively
    // - print right children by calling pre_order() recursively
    if (root == NULL)
        return;
    printf("%c ", root->data);
    pre_order(root->children[0]);
    
    for (int i = 1; i < MAX_CHILDREN; i++)
        pre_order(root->children[i]);
}

void post_order(tree_node * const root)
{
    // TODO
    // - check if root is NULL then return
    // - print left child by calling post_order() recursively
    // - print right children by calling post_order() recursively
    // - print root data
    if (root == NULL)
        return;

    for (int i = 0; i < MAX_CHILDREN; i++)
        post_order(root->children[i]);

    printf("%c ", root->data);
}
