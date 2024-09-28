#include<stdio.h>
#include "Stack_Array.h"

int main()
{
    stack_t *base_ptr = create_stack(20);

    while(1)
    {
        int num;
        printf("Enter a number: <Ctrl+d> to stop : ");
        if(scanf("%d", &num)!=1)
        {
            break;
        }

        while(getchar()!='\n');
        push(base_ptr, base_ptr->top, base_ptr->size,num);
    
    }

    printf("The List of numbers reversied: \n");
    
    while(Isemptystack(base_ptr->top)!=1)
    {
        printf("%d\n",pop(base_ptr,base_ptr->top));
    }

    Destroystack(base_ptr);                           //이거 까먹지 말기
    base_ptr = NULL;

    return 0;
}