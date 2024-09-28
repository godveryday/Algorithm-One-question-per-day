#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "Queue_Link2.h"

int main()
{
    int select;
    head_t *base_ptr = create_head();

    while (1)
    {
        printf("In (0), out (1), exit(2) : ");
        scanf(" %d", &select);
        char name[25];

        switch (select)
        {
        case 0: // 0이면 enqueue
            printf("Customer: ");
            scanf(" %[^\n]s", name);
            enqueue(base_ptr, name);
            printf("The Current status of Queue : (");

            queue_t *temp = base_ptr->front;

            while (temp != NULL)
            {
                printf("%s", temp->data);
                temp = temp->next;
                if (temp != NULL)
                    printf(", ");
            }

            printf(")");
            printf("\n\n\n");
            break;

        case 1: // 1이면 dequeue
            if (base_ptr->front != NULL)
            {
                printf("Customer dequeued : %s\n", dequeue(base_ptr));
                printf("The Current status of Queue : (");

                queue_t *temp2 = base_ptr->front;

                while (temp2 != NULL)
                {
                    printf("%s", temp2->data);
                    temp2 = temp2->next;
                    if (temp2 != NULL)
                        printf(", ");
                }
                printf(")");
            }
            else
            {
                printf("Queue is empty.\n");
                printf("The Current status of Queue : ()");
            }

            printf("\n\n\n");
            break;

        case 2:
            printf("program terminate\n\n\n");
            exit(0); 
            break;
        }
    }

    return 0;
}
