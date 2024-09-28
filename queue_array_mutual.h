#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define element int

typedef struct queue
{
    element *ptr;
    int size, count;
    int front, rear;

}queue_t;


queue_t* create_queue(int size);
void enqueue(queue_t *base_ptr, element item);
element dequeue(queue_t *base_ptr);
int Is_queue_full(queue_t *base_ptr);
int Is_queue_empty(queue_t *base_ptr);
void travel_queue(queue_t *base_ptr);


queue_t* create_queue(int size)
{
    queue_t *base_ptr = (queue_t *)malloc(sizeof(queue_t));
    if(base_ptr == NULL)
    {
        printf("memory allocate failed");
        return NULL;
    }

    base_ptr->ptr = (element *)malloc(sizeof(element)*size);
    if(base_ptr->ptr == NULL)
    {
        printf("memory allocate failed");
        free(base_ptr);
        return NULL;
    }

    base_ptr->size = size;
    base_ptr->front = -1;
    base_ptr->rear = -1;
    base_ptr->count = 0;

    return base_ptr;
}

void enqueue(queue_t *base_ptr, element item)
{
    if(Is_queue_full(base_ptr) == 0)
    {
        base_ptr->rear = (base_ptr->rear+1) % base_ptr->size;
        base_ptr->ptr[base_ptr->rear] = item;
        base_ptr->count+=1;
    }

    else
    {
        printf("queue is full");
        exit(1);
    }
}


element dequeue(queue_t *base_ptr)
{
    element item;
    if(Is_queue_empty(base_ptr) == 0)
    {
        base_ptr->front = (base_ptr->front+1) % base_ptr->size;
        item = base_ptr->ptr[base_ptr->front];
        base_ptr->count-=1;
        return item;
    }

    else    
    {
        printf("queue is empty");
        exit(1);
    }
}

// 여기서 매우 주의!! dequeue를 한번도 안하면 front가 -1이므로 이조건에서 full이 절대 안나옴, 그냥 count로 하는게 낫다
int Is_queue_full(queue_t *base_ptr)
{
    if(base_ptr->count == base_ptr->size)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int Is_queue_empty(queue_t *base_ptr)
{
    if(base_ptr->front == base_ptr->rear)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}


void travel_queue(queue_t *base_ptr)
{
    element item;
    int temp = base_ptr->front;
    while(temp != base_ptr->rear)
    {
        temp = (temp+1) % base_ptr->size; 
        item = base_ptr->ptr[temp];
        printf("%d ", item);
    }
}