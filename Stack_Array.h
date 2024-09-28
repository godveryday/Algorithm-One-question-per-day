#include<stdio.h>
#include<stdlib.h>
typedef int element;

typedef struct
{
    element *ptr;
    int size;
    int top;

}stack_t;


stack_t* create_stack(int);
void push(stack_t *, int, int, int);
element pop(stack_t *, int); 
element top(stack_t *, int);
int Isfullstack(int top, int size);
int Isemptystack(int top);
void Destroystack(stack_t *);
int Countstackitem(stack_t *);
void Clearstack(stack_t *);


stack_t* create_stack(int size) //���⼭ size�� �׳� �Լ��ȿ� �־��ִ� ���̹Ƿ� ���ǵ��� �ʾƵ� �������!!
{
    stack_t *base_ptr = (stack_t *)malloc(sizeof(stack_t));
    if(base_ptr == NULL)
    {
        printf("Can't allocated memory");
        return NULL;
    }

    base_ptr->ptr = (element *)malloc(sizeof(element)*size);
    if(base_ptr->ptr == NULL)
    {
        printf("Can't allocated memory");
        free(base_ptr);
        return NULL;
    }

    base_ptr->top = -1;
    base_ptr->size = size;
    return base_ptr;
}

void push(stack_t *base_ptr, int top, int size, int item)       //���⼭ ��� top�� size�� �����ͷ� �����ϴ°� �������� �޸𸮰��� �������� ����.
{
    
    if(Isfullstack(top, size) == 1)
    {
        printf("Stack is full. return");
        exit(1);    //return; �����غ���
    }
    
    base_ptr->ptr[++base_ptr->top] = item;
    
}

element pop(stack_t *base_ptr, int top)
{
    if(Isemptystack(top) == 1)
    {
        printf("Stack is empty. return");
        exit(1);    //return �����غ���
    }
    
    element value = base_ptr->ptr[base_ptr->top--];
    return value;
}


element top(stack_t *base_ptr, int top)
{
    if(Isemptystack(top) == 1)
    {
        printf("Stack is empty. program terminates");
        exit(1);
    }
    
    element value = base_ptr->ptr[base_ptr->top];
    return value;
}


int Isfullstack(int top, int size)
{
    if(top == size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int Isemptystack(int top)
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Destroystack(stack_t *base_ptr)
{
    free(base_ptr->ptr);
    free(base_ptr);
}

int Countstackitem(stack_t *base_ptr)
{
    return (base_ptr->top)+1;
}

void Clearstack(stack_t *base_ptr)
{
    base_ptr->top = -1;
}