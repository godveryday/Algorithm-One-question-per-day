#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node
{
 int data;
 struct node *next;
 
}node_t;

typedef struct link_head
{
 int count;
 node_t *top;

}link_head_t;

link_head_t* create_head();
void insert_node(link_head_t* base_link_ptr, int num);
void delete_node(link_head_t* base_link_ptr, int num);
bool search_node(link_head_t* base_link_ptr, int num);
void traverse(link_head_t* base_link_ptr);


link_head_t* create_head()
{
    link_head_t *base_link_ptr = (link_head_t*)malloc(sizeof(link_head_t));
    
    if(base_link_ptr == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }

    base_link_ptr->count =0;
    base_link_ptr->top = NULL;
    return base_link_ptr;
}


void insert_node(link_head_t* base_link_ptr, int num)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    
    if(new_node == NULL)
    {
        printf("memory allocate failed\n");
        return;
    }
    
    new_node->data = num;
    if(base_link_ptr->top == NULL)
    {
        new_node->next = base_link_ptr->top;
        base_link_ptr->top = new_node;
        base_link_ptr->count+=1;
    }

    else if(base_link_ptr->top->data >= new_node->data)
    {
        new_node->next = base_link_ptr->top;
        base_link_ptr->top = new_node;
        base_link_ptr->count+=1;
    }
    
    else
    {
        node_t *temp = base_link_ptr->top;
        node_t *pre_temp = NULL;
        while (temp != NULL && new_node->data >= temp->data)
        {
            pre_temp = temp;
            temp = temp->next;
        }
        if (pre_temp == NULL)
        {
            new_node->next =base_link_ptr->top;
            base_link_ptr->top = new_node;
        }
        else
        {
            pre_temp->next = new_node;
            new_node->next = temp;
        }

        base_link_ptr->count += 1;
        }

    return;
}
 
 
void delete_node(link_head_t* base_link_ptr, int num)
{
    if(base_link_ptr->top == NULL)
    {
        printf("list is empty");
        return;
    }
    
    if(search_node(base_link_ptr, num) == false)
    {
        printf("%d is not in list\n", num);
        return;
    }


    if(base_link_ptr->top->data == num)
    {
        node_t *temp = base_link_ptr->top;
        base_link_ptr->top = base_link_ptr->top->next;
        free(temp);
        base_link_ptr->count-=1;
    }

    else
    {
        node_t *temp = base_link_ptr->top;
        node_t *pre_temp = NULL;
        while(temp->data != num)
        {
            pre_temp = temp;
            temp = temp->next; 
        }

        pre_temp->next = temp->next;
        free(temp);
        base_link_ptr->count-=1;
    }
}


bool search_node(link_head_t *base_link_ptr , int num)
{
    node_t *temp = base_link_ptr->top;
    for(int i=0; i<base_link_ptr->count; i++)
    {
        if(temp->data == num)
        {
            return true;
        }

        temp = temp->next;
    }
    
    return false;
}


void traverse(link_head_t* base_link_ptr) 
{
    node_t *temp =base_link_ptr->top;
    for(int i=0; i<base_link_ptr->count; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}