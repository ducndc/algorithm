//
//  avl.c
//  AVL
//
//  Created by TungDT on 7/19/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "avl.h"

node* create_node(const int key)
{
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 0;
    return n;
}

void clear_avl(node** root)
{
    if (*root == NULL) return;
    clear_avl(&(*root)->left);
    clear_avl(&(*root)->right);
    free(*root);
    *root = NULL;
}
int get_height(node *n)
{
    if (n == NULL) return 0;
    
    int lh = left_height(n);
    int rh = right_height(n);
    
    return max(lh, rh);
}

int left_height(node *n)
{
    if (n->left == NULL) return 0;
    else return 1 + n->left->height;
}
int right_height(node *n)
{
    // TODO: same as left height
	if (n->right == NULL) return 0;
	else return 1 + n->right->height;
}

int balance_factor(node* n)
{
    // TODO:
    // - if n is NULL then return 0
    // - get left height and right height
    // - return left height - right height
	if (n == NULL) return 0;
	return (left_height(n) - right_height(n));
}

int max(const int a, const int b)
{
    return a > b ? a : b;
}

node* l_rotation(node* n)
{
    // rotate left on node n
    node *right_child = n->right;
    n->right = right_child->left;
    right_child->left = n;
    // update height on n and right child
    n->height = get_height(n);
    right_child->height = get_height(right_child);
    return right_child;
}

node* r_rotation(node* n)
{
    // TODO
    // - rotate right on node n
	node *left_child = n->left;
	n->left = left_child->right;
	left_child->right = n;
    // - update height on n and left child
	n->height = get_height(n);
	left_child->height = get_height(left_child);
	return left_child;
}

node* lr_rotation(node* n)
{
    // left rotation on left subtree
    n->left = l_rotation(n->left);
    // right rotation on n
    n = r_rotation(n);
    return n;
}
node* rl_rotation(node* n)
{
    // TODO
    // right rotation on right subtree
    // left rotation on n
	n->right = r_rotation(n->right);
	n = l_rotation(n);
	return n;
}
node* rebalance_rightsubtree(node* root)
{
    // if tree is balanced then return root
    if (balance_factor(root) < 2) return root;
    
    // if tree is left heavy
    if (balance_factor(root->left) >= 0)
        return r_rotation(root);
    else // if tree is right heavy
        return lr_rotation(root);
}
node* rebalance_leftsubtree(node* root)
{
    // TODO: same as right subtree
    // if tree is balanced then return root
	if (balance_factor(root) > -2) return root;

    // if tree is right heavy then rotate left
	if (balance_factor(root->right) >= 0)
		return l_rotation(root);
    
    // if tree is left heavy then rotate right-left
	else
		return rl_rotation(root);
}

node* insert_node(node* root, const int key)
{
    if (root == NULL) return create_node(key);
    
    if (root->key < key) // insert to right subtree
    {
        // insert node on right subtree
        root->right = insert_node(root->right, key);
        // rebalance on left subtree
        root = rebalance_leftsubtree(root);
    }
    else // insert to left subtree
    {
        // TODO: same as right subtree
		root->left = insert_node(root->left, key);
		root = rebalance_rightsubtree(root);
    }
    root->height = get_height(root);
    return root;
}

node* delete_node(node* root, const int key)
{
    if (root == NULL) return NULL;
    
    if (root->key < key)
    {
        root->right = delete_node(root->right, key);
        root = rebalance_rightsubtree(root);
    }
    else if (root->key > key)
    {
        // TODO: same as right subtree
		root->left = delete_node(root->left, key);
		root = rebalance_leftsubtree(root);
    }
    else // delete node at root
    {
        if (root->right != NULL) // has right subtree
        {
            // find min node on right subtree
			node *min_node = find_min(root->right);
            // copy min node's key to root's key
			root->key = min_node->key;
            // delete min node on right subtree
			delete_node(root->right, min_node->key);
            // rebalance on right subtree
			rebalance_rightsubtree(root);
        }
        else // has no right subtree
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
    }
    root->height = get_height(root);
    return root;
}

node* find_min(node* root)
{
    if (root->left == NULL) return root;
    return find_min(root->left);
}

void in_order(node *root)
{
    if (root == NULL) return;
    in_order(root->left);
    printf("%d ", root->key);
    in_order(root->right);
}
