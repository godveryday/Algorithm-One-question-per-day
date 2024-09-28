#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define element int

typedef struct array_head
{
    int count;
    int top;
    int size;
    int *list_ptr;

}array_head_t;

array_head_t* create_head(int size);
void insert(array_head_t *base_array_ptr, element item);
bool search_array(array_head_t *base_array_ptr, element item);
void move_in(array_head_t *base_array_ptr, int loc);
void move_out(array_head_t *base_array_ptr, int loc);
void traverse(array_head_t *base_array_ptr);
void delete(array_head_t *base_array_ptr, element item);


array_head_t* create_head(int size)
{
    array_head_t *base_array_ptr = (array_head_t*)malloc(sizeof(array_head_t));
    if(base_array_ptr == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }
    base_array_ptr->count = 0;
    base_array_ptr->top = -1;
    base_array_ptr->size = size;
    

    base_array_ptr->list_ptr = (int *)malloc(sizeof(int)*size);
    if(base_array_ptr->list_ptr == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }

    return base_array_ptr;
}

void insert(array_head_t *base_array_ptr, element item)
{
    if(base_array_ptr->top == base_array_ptr->size-1)
    {
        printf("array is full");
        return;
    }

    int loc = 0;
    if(base_array_ptr->top == -1)
    {
        base_array_ptr->list_ptr[++base_array_ptr->top] = item;
        base_array_ptr->count+=1;
        return;
    }

    for(int i=0; i<base_array_ptr->count; i++)
    {
        if(item <= base_array_ptr->list_ptr[i])
        {
            loc = i;
            move_in(base_array_ptr, loc);
            base_array_ptr->list_ptr[loc] = item;
            base_array_ptr->top +=1;
            base_array_ptr->count+=1;
            return;
        } 
    } 
    
        
    base_array_ptr->list_ptr[++base_array_ptr->top] = item;
    base_array_ptr->count+=1;
    return;
    
}


void move_in(array_head_t *base_array_ptr, int loc)
{
    int temp = base_array_ptr->count;
    for(temp; temp>loc; temp--)
    {
        base_array_ptr->list_ptr[temp] = base_array_ptr->list_ptr[temp-1];
    }
}

void move_out(array_head_t *base_array_ptr, int loc)
{
    int temp = base_array_ptr->count-1;
    for(loc; loc<temp; loc++)
    {
        base_array_ptr->list_ptr[loc] = base_array_ptr->list_ptr[loc+1];
    }
}


bool search_array(array_head_t *base_array_ptr, element item)
{
    for(int i=0; i<base_array_ptr->count; i++)
    {
        if(item == base_array_ptr->list_ptr[i])
        {
            return true;
        }
    }

    return false;
}
         
void traverse(array_head_t *base_array_ptr)
{
    if(base_array_ptr->top == -1)
    {
        printf("array is empty");
        return;   
    }

    for(int i=0; i<base_array_ptr->count; i++)
    {
        printf("%d ", base_array_ptr->list_ptr[i]);
    }   
}


void delete(array_head_t *base_array_ptr, element item)
{
    if(base_array_ptr->top == -1)
    {
        printf("array is empty\n");
        return;
    }

    for(int i=0; i<base_array_ptr->count; i++)
    {
        if(item == base_array_ptr->list_ptr[i])
        {
            int loc = i;
            move_out(base_array_ptr, loc);
            base_array_ptr->count -= 1;
            base_array_ptr->top -= 1;
        }
    }
    return;

}