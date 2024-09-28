#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define element int

typedef struct stack
{
    element *ptr; 
    int size;
    int top;

}stack_t;


stack_t *create_stack(int size);
void push(stack_t *base_ptr, element item);
element pop(stack_t *base_ptr);
int Is_stack_full(stack_t *base_ptr);
int Is_stack_empty(stack_t *base_ptr);



stack_t *create_stack(int size)
{
    stack_t *base_ptr = (stack_t *)malloc(sizeof(stack_t));
    if(base_ptr == NULL)
    {
        printf("memory allocate failed");
        NULL;                                   
    }

    base_ptr->ptr = (element *)malloc(sizeof(element)*size);
    if(base_ptr->ptr == NULL)
    {
        printf("memory allocate failed");
        free(base_ptr);
        return NULL;
    }

    base_ptr->top = -1;
    base_ptr->size = size;

    return base_ptr;
}

void push(stack_t *base_ptr, element item)
{
    if(Is_stack_full(base_ptr) == 0)
    {
        base_ptr->ptr[++base_ptr->top] = item;
    }
    else
    {
        printf("stack is full");
        exit(1);
    }
}


element pop(stack_t *base_ptr)
{
    element item;
    if(Is_stack_empty(base_ptr) == 0)
    {
        item = base_ptr->ptr[base_ptr->top--];
    }

    else
    {
        printf("stack is empty");
        exit(1);
    }

    return item;
}

int Is_stack_full(stack_t *base_ptr)
{
    if(base_ptr->top == base_ptr->size-1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int Is_stack_empty(stack_t *base_ptr)
{
    if(base_ptr->top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}