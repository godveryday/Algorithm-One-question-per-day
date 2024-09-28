#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"Binary_Tree.h"
#include"Tree_Queue.h"
#define MAX 50

void bfs(tree_t *root);


int main()
{   
    char array[MAX];
    printf("Input a string : ");
    scanf(" %s", array);
    while(getchar()!='\n');

    int length = strlen(array);
    tree_t *root = create_tree(array, 0, length);

    printf("Pre-order : ");
    pre_order(root);
    printf("\n");
    
    printf("In-order : ");
    in_order(root);
    printf("\n");
    
    printf("Post-order : ");
    post_order(root);
    printf("\n");

    printf("Breadth First : ");
    bfs(root);
    printf("\n");

    return 0;
}

void bfs(tree_t *root)
{
    if (root == NULL)
        return;

    tree_queue_t *queue = create_queue();
    enqueue(queue, root);

    while (!is_empty(queue))
    {
        tree_t *current = dequeue(queue);
        printf("%c", current->data);

        if (current->left != NULL)
            enqueue(queue, current->left);

        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    free(queue); 
}