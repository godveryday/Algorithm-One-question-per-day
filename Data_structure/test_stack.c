/* 어찌 됐건 거의 비슷했음 */
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
    /*내가 안한거, 이거 malloc 할당 못받을 시 나오는거 */
    if(stack_t_ptr == NULL)
    {
        printf("할당받지 못했습니다.");
    }

    printf("you need to input size : ");
    /* 여기 함수로 구현 시 size를 그냥 매개변수로 받으면 코드 길이 줄어듬 */
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
        다른건 됐고 이부분 생각
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

