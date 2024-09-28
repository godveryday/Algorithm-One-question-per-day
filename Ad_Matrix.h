#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct graph
{
    int vertex_count;
    int **arr;
}graph_t;

int find_vertexCnt(FILE *fptr);
graph_t* create_graph(FILE *fptr);
void directed_edge(graph_t *grp, int src, int dst);
void traverse(graph_t* grp);
void DFS(graph_t* grp, int start, bool visited[]);
void BFS(graph_t* grp, int start);
int find_starting_vertex(FILE *fptr);

int find_vertexCnt(FILE *fptr) 
{
    char vertex;
    bool visited[20] = {false}; 

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
    int size;
    char src, dst;
    
    // FILE *fptr = fopen("graph.txt", "r+");
    // if(fptr == NULL)
    // {
    //     printf("Error opening file\n");
    //     return NULL;
    // }
    
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

    while (fscanf(fptr, " %c", &src) == 1 && fscanf(fptr, " %c", &dst) == 1) {
        if (isalpha(src) && isalpha(dst)) 
        {
            directed_edge(grp, src - 'A', dst - 'A');
        } 
        else 
        {
            printf("Invalid data in the file.\n");
            break;
        }
    }

    fclose(fptr);
    return grp;
}


void directed_edge(graph_t *grp, int src, int dst)
{  
    grp->arr[src][dst] = 1;
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
            if (grp->arr[i][j] == 1)
            {
                printf(" %c", 'A' + j);
                hasEdge = true;
            }
        }

        if (!hasEdge) 
        {
            printf(" "); 
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
