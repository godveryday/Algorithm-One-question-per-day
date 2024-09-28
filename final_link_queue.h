#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define element int

typedef struct queue
{
	int data;
	struct queue* next;

}queue_t;

typedef struct head_queue
{
	int count;
	queue_t *rear, *front;


}head_queue_t;

head_queue_t* create_queue_head();
void enqueue(head_queue_t* base_queue, element item);
element dequeue(head_queue_t* base_queue);
bool Is_queue_empty(head_queue_t* base_queue);
void travel_queue(head_queue_t* base_queue);

head_queue_t* create_queue_head()
{
	head_queue_t* base_queue = (head_queue_t*)malloc(sizeof(head_queue_t));
	if (base_queue == NULL)
	{
		printf("memory allocate failed");
		return NULL;
	}
	base_queue->count = 0;
	base_queue->front = base_queue->rear = NULL;
	return base_queue;
}


void enqueue(head_queue_t* base_queue, element item)
{
	queue_t* new_queue = (queue_t*)malloc(sizeof(queue_t));
	if (new_queue == NULL)
	{
		printf("memory allocate failed");
		return;
	}
	new_queue->data = item;
	new_queue->next = NULL;


	if(base_queue->count <= 0)             
	{
		base_queue->rear = base_queue->front = new_queue;
	}

	else
	{
		base_queue->rear->next = new_queue;
		base_queue->rear = new_queue;
	}
	base_queue->count += 1;
}


element dequeue(head_queue_t* base_queue)
{
	element result;

	if (Is_queue_empty(base_queue)==true)
	{
		printf("queue is empty");
		exit(1);
	}

	queue_t* temp = base_queue->front;
	result = temp->data;
	if (base_queue->count == 1)
	{
		base_queue->front = base_queue->rear = NULL;
	}

	else
	{
		base_queue->front = base_queue->front->next;
	}

	free(temp);
	base_queue->count -= 1;
	
	return result;
}


bool Is_queue_empty(head_queue_t* base_queue)
{
	if (base_queue->count == 0)
	{
		return true;
	}
	
	else
	{
		return false;
	}

}

void travel_queue(head_queue_t* base_queue)
{
	if (Is_queue_empty(base_queue) == true)
	{
		printf("queue is empty");
	}

	else
	{
		queue_t* temp = base_queue->front;
		for(int i = 0; i < base_queue->count; i++)
		{
			printf("%d", temp->data);
			temp = temp->next;
		}
	}
}