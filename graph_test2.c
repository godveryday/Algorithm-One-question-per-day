#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct graph
{
    int vertex_count;
    int **arr;
}graph_t;

typedef struct fstack
{
    char arr[10];
    int top;
    int count;
}fstack_t;


fstack_t* create_fstack();
bool search_fstack(fstack_t *fstack, char temp);
void push_fstack(fstack_t *fstack, char temp);
void traverse_fstack(fstack_t *fstack);

graph_t* create_grp(int count);
void insert_grp();


int main()
{
    fstack_t *fstack = create_fstack();

    FILE *fptr = fopen("graph.txt", "r+");
    if(fptr == NULL)
    {
        printf("file open failed\n");
        exit(1);
    }

    while(feof(fptr)== 0)
    {
        char temp = fgetc(fptr);
        if(!search_fstack(fstack , temp) && temp != '\n' && temp != ' ' && temp != EOF)
        {
            push_fstack(fstack, temp);
        }
    }

    traverse_fstack(fstack);
    graph_t *grp = create_grp(fstack->count);


    return 0;
}


fstack_t* create_fstack()
{
    fstack_t *fstack = (fstack_t*)malloc(sizeof(fstack_t));
    if(fstack == NULL)
    {
        printf("memory allocate failed\n");
        return NULL;
    }

    fstack->count = 0;
    fstack->top = -1;
}


bool search_fstack(fstack_t *fstack, char temp)
{
    for(int i=0; i<fstack->count; i++)
    {
        if(fstack->arr[i] == temp)
        {
            return true;
        }
    }
    return false;
}

void push_fstack(fstack_t *fstack, char temp)
{
    if(fstack->count >= (sizeof(fstack->arr)/sizeof(fstack->arr[0])))
    {
        printf("arr is full\n");
        return;
    }

    fstack->arr[++fstack->top] = temp;
    fstack->count++;
    return;
}

void traverse_fstack(fstack_t *fstack)
{
    if(fstack->top == -1)
    {
        printf("arr is empty\n");
        return;
    }

    for(int i=0; i<fstack->count; i++)
    {
        printf("%c ", fstack->arr[i]);
    }
}


graph_t* create_grp(int count)
{
    graph_t *pgrp;
    pgrp->vertex_count = count;
    pgrp->arr = (int **)malloc(sizeof(int *)*count);
    if(pgrp->arr == NULL)
    {
        printf("memory allocate failed\n");
        return NULL;
    }

    for(int i=0; i<count; i++)
    {
        pgrp->arr[i] = (int *)calloc(count, sizeof(int));
    }

    return pgrp;
}