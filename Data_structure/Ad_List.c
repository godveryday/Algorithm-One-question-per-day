#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"Ad_List.h"

int main()
{
    char file_name[100];
    printf("File name of a graph : ");
    scanf(" %s", file_name);

    FILE *fptr = fopen(file_name,"r");
    if(fptr == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int start_vertex = find_starting_vertex(fptr);
    rewind(fptr);

    graph_t *grp = create_graph(fptr);  
    
    bool *visit = (bool *)malloc(sizeof(bool)*(grp->vertexCnt));
    if(visit == NULL)
    {
        printf("visit_dfs memory allocate failed\n");
        return -1;
    }

    for(int i=0; i<grp->vertexCnt; i++)
    {
        visit[i] = false;
    }

    traverse(grp);

    printf("\n");
    printf("Depth First Traversal : ");
    DFS(grp, start_vertex, visit);

    printf("\n");
    printf("Breadth First Traversal : ");
    BFS(grp, start_vertex);


    return 0;
}