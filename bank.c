#include<stdio.h>
#include<stdlib.h>
#include "Queue_Link2.h"

int main()
{
    int select;
    head_t *base_ptr = create_head();

    while(1)
    {
        printf("In (0), out (1), exit(2) : ");
        scanf(" %d", &select);
        char name[20];

        switch(select)
        {
            case 0:                                                                          //0이면 enqueue                                                           
                printf("Customer: ");
                scanf(" %[^\n]s", name);
                enqueue(base_ptr,name);
                printf("The Current status of Queue : (");
                
                queue_t *temp = base_ptr->front;
                printf("%s", temp->data);
                temp = temp->next;
                while(temp != NULL)
                {
                    printf(", ");
                    printf("%s", temp->data);
                    temp = temp->next;
                }
                
                printf(")");
                printf("\n\n\n");
                break;

            case 1:                                                 //1이면 dequeue   
                printf("Customer dequeued : %s\n", dequeue(base_ptr));                                  
                printf("The Current status of Queue : (");
                
                queue_t *temp2 = base_ptr->front;

                if(temp2 != NULL)
                {
                    printf("%s", temp2->data);
                    temp2 = temp2->next;
                }

                while(temp2 != NULL)
                {
                    printf(", ");
                    printf("%s", temp2->data);
                    temp2 = temp2->next;
                }
                
                printf(")");
                printf("\n\n\n");
                break;



            case 2:
                printf("program terminate");
                printf("\n\n\n");
                exit(1);
                break;
         
        }
    }

    return 0;
}