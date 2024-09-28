/* linked list 로 구현한 queue */
#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct queue
{
    int data;
    struct queue *next;

}queue_t;

typedef struct head
{
    queue_t *front;
    queue_t *rear;
    int count;

}head_t;

head_t* create_head();
void enqueue(head_t *base_ptr, element item);
element dequeue(head_t *base_ptr);
    

head_t* create_head()
{
    head_t *base_ptr = (head_t *)malloc(sizeof(head_t));
    if(base_ptr == NULL)
    {
        printf("memory allocate failed");
        exit(1);
    }

    base_ptr->front = NULL;
    base_ptr->rear = NULL;
    base_ptr->count = 0;

    return base_ptr;
}

void enqueue(head_t *base_ptr, element item)
{
    queue_t *new_ptr = (queue_t *)malloc(sizeof(queue_t));
    if(new_ptr == NULL)
    {
        printf("memory allocate failed");
        exit(1);
    }
    
    new_ptr->data = item;
    new_ptr->next = NULL;

    if(base_ptr->count !=0)
    {
        base_ptr->rear->next = new_ptr;
    }

    base_ptr->rear = new_ptr;
    if(base_ptr->count == 0)
    {
        base_ptr->front = base_ptr->rear;
    }

    base_ptr->count +=1;
}

element dequeue(head_t *base_ptr)
{
    element item;
    if(base_ptr->count <= 0)
    {
        printf("queue is empty");
        exit(1);
    }

    queue_t *temp = base_ptr->front;
    base_ptr->front = base_ptr->front->next;
    item = temp->data;
    free(temp);
    base_ptr->count -=1;

    return item;
}
