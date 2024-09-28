#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack_array_mutual.h"
#include "queue_array_mutual.h"
#define variable 20

int main()
{
    stack_t *base_stack = create_stack(variable);
    queue_t *base_queue = create_queue(variable);
    int select;
    int value;
    int check1, check2;       //checking miss input(menu)
    int temp,temp2;           //using for loop condition
    int first = 1;              

    printf("This is menu\n");
    printf("1. Ice cream\n");
    printf("2. Bibimbab\n");
    printf("3. Bulgogi\n");
    printf("4. Coffee\n");
    printf("5. Noodle\n");

    while(1)
    {
        printf("Order (0), Serve (1), Exit(2) : ");
        scanf(" %d", &select);
        while(getchar()!='\n');

        switch(select)
        {

            case(0):
                printf("Order: ");
                scanf(" %d", &value);
                check1 = value;
                while(check1 != 0)
                {
                    check2 = check1 %10;
                    if(check2 == 0 || check2 == 6 || check2 == 7 || check2 == 8 || check2 == 9)
                    {
                        printf("%d is not in menu", check2);
                        exit(1);
                    }
                    check1 =check1/10;
                }

                enqueue(base_queue, value);
                printf("Stat: ");
                travel_queue(base_queue);
                printf("(%d)\n", base_queue->count);
                break;


            case(1):
                push(base_stack, dequeue(base_queue));
                temp = pop(base_stack);
                printf("Serve: ");

                while(temp != 0)
                {
                    temp2 = temp%10;
                    temp = temp/10;
                    
                    if(first == 0)
                    {
                        printf(", ");
                    }

                    switch(temp2)
                    {
                        case(1):
                            printf("Ice cream");
                            break;

                        case(2):
                            printf("Bibimbab");
                            break;

                        case(3):
                            printf("Bulgogi");
                            break;

                        case(4):
                            printf("Coffee");
                            break;

                        case(5):
                            printf("Noodle");
                            break;
                    }
                    first = 0;
                }
                printf("\n");
                printf("Stat: ");
                travel_queue(base_queue);
                printf("(%d)\n", base_queue->count);
                first = 1;
                break;

            case(2):
                exit(1);
                break;
            
            default:
                printf("miss input\n");
                break;
        }

    }

    return 0;
}