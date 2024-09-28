#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define element char

typedef struct tree
{
    element data;
    struct tree *left, *right;
}tree_t;


tree_t *create_tree(element* array, int index, int size);
void pre_order(tree_t *root);
void in_order(tree_t *root);
void post_order(tree_t *root);

tree_t *create_tree(element* array, int index, int size)
{
    if(index < size)
    {
        tree_t *new_node = (tree_t*)malloc(sizeof(tree_t));
        if(new_node == NULL)
        {
            printf("memory allocate failed");
            return NULL;
        }

        new_node->data = array[index];
        

        new_node->left = create_tree(array, 2 * index + 1, size);
        new_node->right = create_tree(array, 2 * index + 2 , size);
        return new_node;
    }
    
    else
    {
        return NULL;
    }
}


void pre_order(tree_t *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%c", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(tree_t *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        in_order(root->left);
        printf("%c", root->data);
        in_order(root->right);
    }
}

void post_order(tree_t *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        post_order(root->left);
        post_order(root->right);
        printf("%c", root->data); 
    }
}

