#include<stdio.h>
#include<stdlib.h>
#include<Stdbool.h>
#include<string.h>
#include "List_Array.h"

int main()
{
    array_head_t *base_array_ptr = create_head(20);
    while(1)
    {
        int select;
        int num;
        printf("In (0), Search (1), Out (2), Exit (3) : ");
        scanf("%d", &select);
        while(getchar()!='\n');

        switch(select)
        {
            case 0:
                printf("In : ");
                scanf(" %d", &num);
                while(getchar()!='\n');
                printf("\n");

                insert(base_array_ptr, num);
                printf("The current status of List : ");
                traverse(base_array_ptr);
                printf("\n");
                break;


            case 1:
                printf("Search : ");
                scanf(" %d", &num);
                while(getchar()!='\n');

                if(search_array(base_array_ptr, num) ==  true)
                {
                    printf("My List has %d\n", num);
                    printf("The current status of List : ");
                    traverse(base_array_ptr);
                }
                
                else
                {
                    printf("My List dose not have %d\n", num);
                    printf("The current status of List : ");
                    traverse(base_array_ptr);
                }

                printf("\n");
                break;



            case 2:
                printf("Out :");
                scanf(" %d", &num);
                while(getchar()!='\n');

                if(search_array(base_array_ptr, num) == true)
                {
                    delete(base_array_ptr, num);


                    printf("%d was removed.\n", num);
                    printf("The current status of List : ");
                    traverse(base_array_ptr);
                    printf("\n");
                }

                else
                {
                    printf("%d is not in list\n", num);
                    printf("The current status of List : ");
                    traverse(base_array_ptr);
                    printf("\n");
                }

                break;

            case 3:
                printf("program terminates");
                exit(1);
                break;
        }
    }

    return 0;
}