#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct graph
{
    int vertex_count;
    int **arr;
}graph_t;

int find_vertexCnt(FILE *fptr);
graph_t* create_graph(FILE *fptr);
void undirected_edge(graph_t *grp, int src, int dst, int cost);
void directed_edge(graph_t *grp, int src, int dst, int cost);
void traverse(graph_t* grp);
void DFS(graph_t* grp, int start, bool visited[]);
void BFS(graph_t* grp, int start);
void MST(graph_t *pgrp, int start_vertex);
void shortest_path(graph_t *pgrp, int start_vertex);
int find_starting_vertex(FILE *fptr);



int find_vertexCnt(FILE *fptr) 
{
    char vertex;
    bool visited[100] = {false}; 

    int vertex_count = 0;

    while (fscanf(fptr, " %c", &vertex) == 1) {
        if (isalpha(vertex) && !visited[vertex - 'A']) {
            vertex_count++; 
            visited[vertex - 'A'] = true;
        }
    }

    rewind(fptr); 
    return vertex_count;
}


graph_t* create_graph(FILE *fptr)
{
    int size, cost;
    char src, dst;
    
    size = find_vertexCnt(fptr);

    graph_t* grp = (graph_t*)malloc(sizeof(graph_t));
    if(grp == NULL)
    {
        printf("memory allocate failed\n");
        fclose(fptr);
        return NULL;
    }

    grp->vertex_count = size;  
    grp->arr = (int **)malloc(sizeof(int*)*size);

    for(int i =0; i<size; i++)
    {
        grp->arr[i] = (int *)calloc(size, sizeof(int));
    }

    rewind(fptr);
    fgetc(fptr);

    while (fscanf(fptr, " %c", &src) == 1 && fscanf(fptr, " %c", &dst) == 1 && fscanf(fptr, " %d", &cost) == 1) 
    {
        if (isalpha(src) && isalpha(dst)) 
        {
            undirected_edge(grp, src - 'A', dst - 'A', cost);
        } 
        else 
        {
            printf("Invalid data in the file.\n");
            break;
        }
    }

    for(int i=0; i<grp->vertex_count; i++)
    {
        for(int j=0; j<grp->vertex_count; j++)
        {
            if(grp->arr[i][j] == 0)
            {
                grp->arr[i][j] = 1000;
            }
        }
    }

    fclose(fptr);
    return grp;
}

void undirected_edge(graph_t *grp, int src, int dst, int cost)
{
    grp->arr[src][dst] = cost;
    grp->arr[dst][src] = cost;
}


void directed_edge(graph_t *grp, int src, int dst, int cost)
{  
    grp->arr[src][dst] = cost;
}


void traverse(graph_t* grp)
{
    int i, j;
    printf("The graph is :\n");

    for (i = 0; i < grp->vertex_count; i++)
    {
        printf("%c :", 'A' + i);

        bool hasEdge = false; 

        for (j = 0; j < grp->vertex_count; j++)
        {
            if (grp->arr[i][j] >= 1 && grp->arr[i][j] != 1000)
            {
                int cost = grp->arr[i][j];
                printf(" %c (%d) ", 'A' + j, cost);
                hasEdge = true;
            }
        }

        if (!hasEdge) {
            printf(" "); // If no edge, print a dash
        }
        printf("\n");
    }
}


void DFS(graph_t* grp, int start, bool visited[]) 
{
    printf("%c ", start + 'A');
    visited[start] = true;

    for (int i = 0; i < grp->vertex_count; ++i) {
        if (grp->arr[start][i] && !visited[i]) {
            DFS(grp, i, visited);
        }
    }
}

void BFS(graph_t* grp, int start) 
{
    bool visited[20] = {false};
    visited[start] = true;

    int queue[20];
    int front = -1, rear = -1;
    queue[++rear] = start;

    while (front != rear) 
    {
        int current = queue[++front];
        printf("%c ", current + 'A');

        for (int i = 0; i < grp->vertex_count; ++i) {
            if (grp->arr[current][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
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

void MST(graph_t *pgrp, int start_vertex)
{
    int u,v;
    int edgeCnt = 0;
    bool *TV = (bool *)malloc(sizeof(bool)*pgrp->vertex_count);
    
    for(int i=0; i<pgrp->vertex_count; i++)
    {
        TV[i] = false;
    }

    TV[start_vertex] = true;    //TV에 들어가면 포함된거임.
    

    while(edgeCnt != (pgrp->vertex_count) - 1)
    {
        int min_edge = 1000;
        v = -1;

        for(int i=0; i<pgrp->vertex_count; i++)
        {
            if(TV[i] == true)
            {
                for(int j=0; j<pgrp->vertex_count; j++)
                {
                
                    if(pgrp->arr[i][j] < min_edge && TV[j] == false)
                    {
                        min_edge = pgrp->arr[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(v != -1)
        {
            edgeCnt++;
            TV[v] = true;
            printf("%c %c (%d) \n", u + 'A', v + 'A', pgrp->arr[u][v]);

        }
    }
}   

/* checkcheckcheck */
void shortest_path(graph_t *pgrp, int start_vertex) 
{
    bool *TV = (bool *)malloc(sizeof(bool) * pgrp->vertex_count);
    if (TV == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }

    int *distance = (int *)malloc(sizeof(int) * pgrp->vertex_count);
    if (distance == NULL) 
    {
        printf("Memory allocation failed\n");
        free(TV);
        return;
    }

    for (int i = 0; i < pgrp->vertex_count; i++) 
    {
        TV[i] = false;
        distance[i] = pgrp->arr[start_vertex][i];
    }

    TV[start_vertex] = true;
    distance[start_vertex] = 0;


    for (int i = 0; i < pgrp->vertex_count; i++) 
    {
        printf("%c %c : %d\n", start_vertex + 'A','A' + i, distance[i]);
    }
    printf("\n");

    for (int count = 0; count < pgrp->vertex_count - 1; count++) 
    {
        int min_dist = 1000;
        int min_index;

        for (int v = 0; v < pgrp->vertex_count; v++) 
        {
            if (TV[v] == false && distance[v] <= min_dist) 
            {
                min_dist = distance[v];
                min_index = v;
            }
        }

        int u = min_index;
        TV[u] = true;

       
        for (int i = 0; i < pgrp->vertex_count; i++) 
        {
            if (distance[i] == 1000) 
            {
                printf("%c %c : 1000\n", start_vertex + 'A', 'A' + i);
            } 
            else 
            {
                printf("%c %c : %d\n", start_vertex + 'A', 'A' + i, distance[i]);
            }
        }
        printf("\n");

        for (int v = 0; v < pgrp->vertex_count; v++) 
        {
            if (!TV[v] && pgrp->arr[u][v] && distance[u] != 1000 &&
                distance[u] + pgrp->arr[u][v] < distance[v]) 
            {
                distance[v] = distance[u] + pgrp->arr[u][v];
            }
        }
    }

    for (int i = 0; i < pgrp->vertex_count; i++) 
    {
        if (distance[i] == 1000) 
        {
            printf("%c %c : 1000\n", start_vertex + 'A', 'A' + i);
        } 
        else 
        {
            printf("%c %c : %d\n", start_vertex + 'A', 'A' + i, distance[i]);
        }
    }

    free(TV);
    free(distance);
}