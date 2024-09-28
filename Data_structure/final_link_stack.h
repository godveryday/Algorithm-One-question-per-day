#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define element int

typedef struct stack
{
	element data;
	struct stack* next;
	
}stack_t;

typedef struct head_stack
{
	int count;
	stack_t* top;

}head_stack_t;


head_stack_t* create_stack_head();
void push(head_stack_t* base_stack, element item);
element pop(head_stack_t* base_stack);
bool Is_stack_empty(head_stack_t* base_stack);
void travel_stack(head_stack_t* base_stack);

head_stack_t* create_stack_head()
{
	head_stack_t* base_stack = (head_stack_t*)malloc(sizeof(head_stack_t));
	if (base_stack == NULL)
	{
		printf("memory allocate failed");
		return NULL;

	}

	base_stack->count = 0;
	base_stack->top = NULL;
	
	return base_stack;
}


void push(head_stack_t* base_stack, element item)
{
	stack_t* new_stack = (stack_t*)malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		printf("memory allocate failed");
		return;
	}

	new_stack->data = item;
	new_stack->next = base_stack->top;
	base_stack->top = new_stack;
	base_stack->count += 1;
}


element pop(head_stack_t* base_stack)
{
	element result;

	if(Is_stack_empty(base_stack) == true)
	{
		printf("stack is empty");
		exit(1);
	}

	stack_t* temp = base_stack->top;
	result = temp->data;
	base_stack->top = base_stack->top->next;
	free(temp);
	base_stack->count -= 1;

	return result;
}


bool Is_stack_empty(head_stack_t *base_stack)
{
	if (base_stack->count == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}


void travel_stack(head_stack_t* base_stack)
{
	if (Is_stack_empty(base_stack) == true)
	{
		printf("stack is empty");
		return;
	}
	stack_t* temp = base_stack->top;

	for (int i = 0; i < base_stack->count; i++)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}

}