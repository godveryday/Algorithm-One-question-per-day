/* 8진수, 16진수 구현해보기 */
/* checkcheckcheckcheckchcekc*/
#include<stdio.h>
#include<stdlib.h>
#include "Stack_Array.h"

int main()
{
    int num;
    printf("Enter a positiver int number : ");
    scanf("%d", &num);
    while(getchar()!='\n');
    printf("\nThe binary number of %d :" ,num);


    stack_t *base_ptr = create_stack(20);
    while(1)
    {
        push(base_ptr, base_ptr->top, base_ptr->size,num%2);
        num = num/2;
        if(num < 2)
        {
            push(base_ptr, base_ptr->top, base_ptr->size,num);
            break;
        }
    }
    
    while(base_ptr->top != -1)
    {
        printf("%d",pop(base_ptr, base_ptr->top));
    }

    Destroystack(base_ptr);
    base_ptr = NULL;

    return 0;
}