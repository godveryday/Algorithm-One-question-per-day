/* ���� �ư� ���� ������� */
#include<stdio.h>
#include<stdlib.h>

#define element int
int main()
{
    typedef struct struct_stack
    {
        element *ptr;
        int size;
        int top;

    }stack_t;

    int item = 3;
    // int size;
    // printf("you need to input size : ");
    // scanf("%d",size);

    /* Create stack */
    stack_t *stack_t_ptr = (stack_t *)malloc(sizeof(stack_t));
    /*���� ���Ѱ�, �̰� malloc �Ҵ� ������ �� �����°� */
    if(stack_t_ptr == NULL)
    {
        printf("�Ҵ���� ���߽��ϴ�.");
    }

    printf("you need to input size : ");
    /* ���� �Լ��� ���� �� size�� �׳� �Ű������� ������ �ڵ� ���� �پ�� */
    scanf("%d",stack_t_ptr->size);
    //stack_t_ptr->size = size;

    stack_t_ptr->top = -1;
    stack_t_ptr->ptr = (element *)malloc(sizeof(element)*stack_t_ptr->size);
    return stack_t_ptr;

    /* end of Create stack*/



    /* Is full function */
    if(stack_t_ptr->top == stack_t_ptr->size-1)
    {
        printf("IsFUll, program terminates");
        exit(1);
    }

    /* Push */
    /* void Push(stack_t *stack_t_ptr, Element item)
    {
        �ٸ��� �ư� �̺κ� ����
        stack_t_ptr->stack[++stack_t_ptr->top]=item;
    }*/

    *((stack_t_ptr->ptr)+(++stack_t_ptr->top)) = item;

    /* End of Push */




    /* Pop */
    if(stack_t_ptr->top == -1)
    {
        printf("Isempty, program terminates\n");
        exit(1);
    }
    int temp = *((stack_t_ptr->ptr)+(++stack_t_ptr->top));
    printf("%d\n", temp);
    stack_t_ptr->top-=1;
    

    printf("%d\n", *stack_t_ptr->ptr);
    printf("%d\n", stack_t_ptr->top);

    return 0;
}

