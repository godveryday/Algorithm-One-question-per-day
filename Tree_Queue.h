#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Binary_Tree.h"

typedef struct queue_node
{
    tree_t *data;
    struct queue_node *next;
} queue_node_t;

typedef struct
{
    queue_node_t *front, *rear;
} tree_queue_t;

tree_queue_t *create_queue();
bool is_empty(tree_queue_t *queue);
void enqueue(tree_queue_t *queue, tree_t *data);
tree_t *dequeue(tree_queue_t *queue);


tree_queue_t *create_queue()
{
    tree_queue_t *queue = (tree_queue_t *)malloc(sizeof(tree_queue_t));
    if (queue == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }

    queue->front = queue->rear = NULL;
    return queue;
}

bool is_empty(tree_queue_t *queue)
{
    return (queue->front == NULL);
}

void enqueue(tree_queue_t *queue, tree_t *data)
{
    queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
    if (new_node == NULL)
    {
        printf("memory allocate failed");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

tree_t *dequeue(tree_queue_t *queue)
{
    if (is_empty(queue))
    {
        return NULL;
    }   

    queue_node_t *temp = queue->front;
    tree_t *data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}