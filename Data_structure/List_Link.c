#include<stdio.h>
#include<stdlib.h>
#include<Stdbool.h>
#include<string.h>
#include "List_Link.h"

int main()
{
    link_head_t *base_link_ptr = create_head();

    while(1)
    {
        int select, num;
        printf("In (0), Search (1), Out (2), Exit (3) : ");
        scanf("%d", &select);
        while(getchar()!='\n');
       
        switch (select) 
        {
            case 0: 
                printf("In : ");
                scanf(" %d", &num);
                while(getchar()!='\n');
                printf("\n");

                insert_node(base_link_ptr, num);
                printf("The current status of List : ");
                traverse(base_link_ptr);
                printf("\n");
        



                break;
            
            case 1:
                printf("Search : ");
                scanf(" %d", &num);
                while(getchar()!='\n');

                if(search_node(base_link_ptr, num) ==  true)
                {
                    printf("My List has %d\n", num);
                    printf("The current status of List : ");
                    traverse(base_link_ptr);
                }
                
                else
                {
                    printf("My List dose not have %d\n", num);
                    printf("The current status of List : ");
                    traverse(base_link_ptr);
                }


                printf("\n");
                break;
            

            case 2:
                printf("Out :");
                scanf(" %d", &num);
                while(getchar()!='\n');

                if(search_node(base_link_ptr, num) == true)
                {
                    delete_node(base_link_ptr, num);

                    printf("%d was removed.\n", num);
                    printf("The current status of List : ");
                    traverse(base_link_ptr);
                    printf("\n");
                }

                else
                {
                    printf("%d is not in list\n", num);
                    printf("The current status of List : ");
                    traverse(base_link_ptr);
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