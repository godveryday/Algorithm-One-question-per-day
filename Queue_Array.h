/* array�� ������ queue */
#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct
{
    element *ptr;
    int front;
    int rear;
    int size;
}queue_t;


queue_t* create_queue(int size);
int enqueue(queue_t *base_ptr, element item);
element dequeue(queue_t *base_ptr);
int Isfull(queue_t *base_ptr);
int Isempty(queue_t *base_ptr);




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
        return NULL;
    }

    base_ptr->front = -1;
    base_ptr->rear = -1;
    base_ptr->size = size;
    return base_ptr;
}


int enqueue(queue_t *base_ptr, element item)
{
    if(Isfull(base_ptr) == -1)
    {
        return -1;                  //full�Ͻ� -1�� ������           �̰Ÿ� boolean���� �ϴ¹��� �ƴ°� �����Ű���. --> true 1, false 0(-1)�����ϱ� �̶� define���� �����ص� �Ǳ���.
    }
    else
    {
        base_ptr->rear = (++base_ptr->rear) % base_ptr->size;
        base_ptr->ptr[base_ptr->rear] = item;
    }
}


element dequeue(queue_t *base_ptr)
{
    element result;
    if(Isempty(base_ptr) == -1)
    {
        return -1;                                                //boolean ���� ������
    }
    else
    {
        base_ptr->front = (++base_ptr->front)%base_ptr->size;
        result = base_ptr->ptr[base_ptr->front];
    }
    
    return result;
}


int Isfull(queue_t *base_ptr)
{
    if(((base_ptr->rear+1)%base_ptr->size) == base_ptr->front)
    {
        printf("array is full");
        return -1;
    }
    else
    {
        return 1;
    }
}


int Isempty(queue_t *base_ptr)
{
    if(base_ptr->rear == base_ptr->front)
    {
        printf("array is empty");
        return -1;
    }

    else
    {
        return 1;
    }
}


