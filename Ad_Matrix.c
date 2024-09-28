#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include"Ad_Matrix.h"

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

    graph_t* grp = create_graph(fptr);
    traverse(grp);

    printf("Depth First Traversal : ");
    bool visitedDFS[20] = {false};
    DFS(grp, start_vertex, visitedDFS);

    printf("\nBreadth First Traversal : ");
    BFS(grp, start_vertex); 

    printf("\n");

    fclose(fptr);
    return 0;
}

