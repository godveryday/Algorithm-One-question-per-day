#include<stdio.h>
#include<stdlib.h>
typedef int element;
element* create_stack(int);
void push(element *ptr, int top);

int main()
{
    int size;
    element *ptr;
    int top = -1;
    int item;
    
    printf("Input size : ");
    scanf("%d", &size);

    /* create_stack */
    ptr = create_stack(size);
    
    /* push */
    push(ptr,top);

    printf("%d\n", ptr[0]);
    printf("%d", ptr[1]);
    
    /* pop */


    return 0;
}

element* create_stack(int size)
{
    element *ptr = (element *)malloc(sizeof(element)*size);
    return ptr;
}

void push(element *ptr, int top)
{
    for(int i=0; i<10; i++)
    {
        int item;
        printf("input item :");
        scanf("%d",&item);

        ptr[++top] = item;
    }
}