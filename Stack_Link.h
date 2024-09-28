#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct stack
{
    int data;
    struct stack *next;
} stack_t; 

typedef struct head
{
    stack_t *top;
    int count;
} head_t;

head_t *Create_head();
void Create_node(head_t *base_ptr);
void Push(head_t *base_ptr, element item);
element Pop(head_t *base_ptr);
element Top(head_t *base_ptr);

int IsEmptyStack(head_t *base_ptr);
void DestroyStack(stack_t *stack);
int CountStackItem(stack_t *stack); 
void ClearStack(head_t *base_ptr);

head_t *Create_head()
{
    head_t *base_ptr = (head_t *)malloc(sizeof(head_t));
    if (base_ptr == NULL)
    {
        printf("메모리 할당 실패\n");
        return NULL; // 오류 처리를 위해 NULL 반환
    }

    base_ptr->count = 0;
    base_ptr->top = NULL;
    return base_ptr;
}

void Create_node(head_t *base_ptr)
{
    stack_t *new_ptr = (stack_t *)malloc(sizeof(stack_t));
    if (new_ptr == NULL)
    {
        printf("메모리 할당 실패\n");
        return;
    }

    new_ptr->next = base_ptr->top;
    base_ptr->top = new_ptr;
    base_ptr->count++;
}

void Push(head_t *base_ptr, element item)
{
    stack_t *new_ptr = (stack_t *)malloc(sizeof(stack_t));
    if (new_ptr == NULL)
    {
        printf("메모리 할당 실패\n");
        return;
    }

    new_ptr->data = item;
    new_ptr->next = base_ptr->top;
    base_ptr->top = new_ptr;
}

element Pop(head_t *base_ptr)
{
    if (IsEmptyStack(base_ptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1; // 오류 처리를 위해 음수 값 반환
    }

    int value = base_ptr->top->data;
    stack_t *temp = base_ptr->top;
    base_ptr->top = base_ptr->top->next;
    free(temp);
    base_ptr->count--;

    return value;
}

element Top(head_t *base_ptr)
{
    if (IsEmptyStack(base_ptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1; // 오류 처리를 위해 음수 값 반환
    }

    return base_ptr->top->data;
}

int IsEmptyStack(head_t *base_ptr)
{
    return base_ptr->count == 0;
}

void DestroyStack(stack_t *stack)
{
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int CountStackItem(stack_t *stack)
{
    int count = 0;
    while (stack != NULL)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

void ClearStack(head_t *base_ptr)
{
    DestroyStack(base_ptr->top);
    base_ptr->top = NULL;
    base_ptr->count = 0;
}
