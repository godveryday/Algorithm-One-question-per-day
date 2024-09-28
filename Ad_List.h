#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

typedef struct node 
{
    int vertex;
    struct node* next;
}node_t;

typedef struct graph
{
    node_t *head;
    int vertexCnt;
}graph_t;

typedef struct queue
{
    int rear, front;
    int *arr;
    int count, size;
}queue_t;


graph_t* create_graph(FILE *fptr);
void add_undirected_edge(graph_t *pgrp , int src, int dst);
void add_directed_edge(graph_t* pgrp , int src, int dst);
void traverse(graph_t *pgrp);
void DFS(graph_t *pgrp, int src, bool *visit);
void BFS(graph_t *pgrp, int src);

queue_t *create_queue(graph_t *grp);
void enqueue(queue_t *queue, int item);
int dequeue(queue_t *queue);
bool Is_queue_empty(queue_t *queue);
bool Is_queue_full(queue_t *queue);


int fine_vertexCnt(FILE *fptr);
int find_starting_vertex(FILE *fptr);


graph_t* create_graph(FILE *fptr)
{
    char space, src, dst;

    graph_t *pgrp = (graph_t *)malloc(sizeof(graph_t));
    if(pgrp == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }

    int size = fine_vertexCnt(fptr);    

    pgrp->vertexCnt = size;
    pgrp->head = (node_t *)malloc(sizeof(node_t)*size);

    for(int i=0; i<pgrp->vertexCnt; i++)
    {
        pgrp->head[i].vertex = i;
        pgrp->head[i].next = NULL;
    }

    space = fgetc(fptr);
    while(fscanf(fptr, " %c %c", &src, &dst) == 2)
    {
        if(isalpha(src) && isalpha(dst))
        {
            add_directed_edge(pgrp, (src - 'A'), (dst-'A'));
        }
        else
        {
            printf("Invaild input\n");
            return NULL;
        }
    }

    fclose(fptr);
    return pgrp;
}


void add_directed_edge(graph_t* pgrp , int src, int dst)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->vertex = dst;
    new_node->next = NULL;

    if(pgrp->head[src].next == NULL)
    {
        pgrp->head[src].next = new_node;
    }
    else
    {
        node_t *temp = pgrp->head[src].next;
        pgrp->head[src].next = new_node;
        new_node->next = temp;
    }

}

void add_undirected_edge(graph_t* pgrp , int src, int dst)
{
    add_directed_edge(pgrp, src, dst);
    add_directed_edge(pgrp, dst, src);
}


void traverse(graph_t *pgrp)
{
    if(pgrp->vertexCnt == 0)
    {
        printf("graph is empty");
        return;
    }
    
    for(int i=0; i<pgrp->vertexCnt; i++)
    {
        printf("%c : " ,pgrp->head[i].vertex + 'A');
        node_t *temp = pgrp->head[i].next;

        while(temp != NULL)
        {
            printf("%c ", temp->vertex + 'A');
            temp = temp->next;
        }
        printf("\n");
    }
}



queue_t *create_queue(graph_t *grp)
{
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    
    queue->front = queue->rear = -1;
    queue->arr = (int *)malloc(sizeof(int)*grp->vertexCnt);

    queue->count = 0;
    queue->size = grp->vertexCnt;

    return queue;
}

void enqueue(queue_t *queue, int item)
{
    if(Is_queue_full(queue) == 0)
    {
        queue->rear = (queue->rear+1) % queue->size;
        queue->arr[queue->rear] = item;
        queue->count+=1;
    }

    else
    {
        printf("queue is full");
        exit(1);
    }
}


int dequeue(queue_t *queue)
{
    int item;
    if(Is_queue_empty(queue) == 0)
    {
        queue->front = (queue->front+1) % queue->size;
        item = queue->arr[queue->front];
        queue->count-=1;
        return item;
    }

    else    
    {
        printf("queue is empty");
        exit(1);
    }
}


bool Is_queue_full(queue_t *queue)
{
    if(queue->count == queue->size)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool Is_queue_empty(queue_t *queue)
{
    if(queue->front == queue->rear)
    {
        return true;
    }

    else
    {
        return false;
    }
}



int fine_vertexCnt(FILE *fptr)
{
    bool visited[20] = {false};
    int vertexCnt = 0;
    char space, src;
    space = fgetc(fptr);

    while(fscanf(fptr, " %c", &src) == 1)
    {
        if(isalpha(src) && !visited[src - 'A'])
        {
            vertexCnt++;
            visited[src-'A'] = true;
        }
    }
    rewind(fptr);

    return vertexCnt;
}


int find_starting_vertex(FILE *fptr) 
{
    char start_vertex;
    if (fscanf(fptr, " %c", &start_vertex) != 1 || !isalpha(start_vertex)) 
    {
        printf("Invalid data in the file for the starting vertex.\n");
        return -1; 
    }
    rewind(fptr);
    return start_vertex - 'A'; 
}

/* checkcheckcheckcheckcheckcheckcheckcheck  */
void DFS(graph_t *pgrp, int src, bool *visit)
{
    printf("%c ", pgrp->head[src].vertex + 'A');
    visit[src] = true;

    node_t *curptr = pgrp->head[src].next;

    while(curptr != NULL)
    {
        if(!visit[curptr->vertex])
        {
            DFS(pgrp, curptr->vertex, visit);
        }
        curptr = curptr->next;
    }

}


void BFS(graph_t *pgrp, int src)
{
    bool *visit = (bool *)malloc(sizeof(bool) * pgrp->vertexCnt);
    
    for(int i=0; i<pgrp->vertexCnt; i++)
    {
        visit[i] = false;
    }

    queue_t *queue = create_queue(pgrp);
    if(queue == NULL)
    {
        printf("memory allocate failed");
        return;
    }

    enqueue(queue, src);
    visit[src] = true;

    while(Is_queue_empty(queue) != true)
    {
        int current = dequeue(queue);
        printf("%c ",  current + 'A');
        node_t *curptr = pgrp->head[current].next;

        while(curptr != NULL)
        {
            if(!visit[curptr->vertex])
            {
                enqueue(queue, curptr->vertex);
                visit[curptr->vertex] = true;
            }
            curptr = curptr->next;
        }
    }
}