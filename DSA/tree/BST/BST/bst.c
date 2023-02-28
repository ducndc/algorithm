//
//  bst.c
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "bst.h"

node* create_node(const int key)
{
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

void insert_child(node **child, int key)
{
    if ((*child) == NULL)
	{
		*child = (node*) malloc(sizeof(node));
		(*child)->key = key;
	}
    else insert_node(child, key);
}

void insert_node(node **root, const int key)
{
    // TODO:
    // - create a node n with key
    // - check if root is NULL then n is the root
    // - else insert n into the BST from root
    //      - if n->key == root->key then return because n is already in the BST
    //      - if n->key < root->key then insert n into the left child of root 
	//      - if n->key > root->key then insert n into the right child of root 
	node *n = create_node(key);

	if (*root == NULL)
	{
		
		node *n = create_node(key);
		*root = n;
		return;
	}

	if (n->key == (*root)->key)
		return;

	if (n->key < (*root)->key)
	{
		insert_child(&(*root)->left, key);
	}
	else
	{
		insert_child(&(*root)->right, key);
	}
}


node* create_bst(int *a, const int n)
{
    node *root = NULL;
    // TODO: call insert_node() to insert each element of a into the BST
	for (int i = 0; i < n; i++)
	{
		insert_node(&root, a[i]);
	}

    return root;
}
node* search_bst(node *root, const int key)
{
    // TODO
    // - if root is NULL then return NULL
    // - if root->key == key then return root
    // - if root->key > key then recursively search in the left child of root
    // - if root->key < key then recursively search in the right child of root
	if (root == NULL)
		return NULL;

	if (root->key == key)
		return root;

	if (root->key > key)
	{
		return search_bst(root->left, key);
	}

	if (root->key < key)
	{
		return search_bst(root->right, key);
	}

	return NULL;
}

void in_order(node *root)
{
    // TODO: implement in-order traversal
    if (root == NULL)
        return;

    in_order(root->left);
    printf("%d ", root->key);
	in_order(root->right);

}

node *delete_tree_node(node *root, const int key)
{
	if (root == NULL)
		return NULL;

	if (root->key < key)
		root->right = delete_tree_node(root->right, key);

	else if (root->key > key)
		root->left = delete_tree_node(root->left, key);
	else
	{
		if (root->left && root->right)
		{
			node *tmp = find_min_on_right(root->right);
			int temp_key;
			temp_key = root->key;
			root->key = tmp->key;
			tmp->key = temp_key;
			free(tmp);
		}
		else if (root->left)
		{
			node *tmp;
			tmp = root;
			root = root->left;
			free(tmp);
		}
		else if (root->right)
		{
			node *tmp;
			tmp = root;
			root = root->right;
			free(tmp);
		}
		else
		{
			free(root);
		}
	}

	return root;
}

node *find_min_on_right(node *root)
{
	if (root->left == NULL)
		return root;
	return find_min_on_right(root->left);
}
