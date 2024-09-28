#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int stu_num=0;
    int select;
    int sort;
    char filename[50];
    FILE *ptr;

    typedef struct
    {
        char familyname[20];
        int age;
        int math,english,history;

    }student_t;

    student_t *stu_ptr = NULL;
    

    while(1)
    {
        printf("===========================\n");
        printf("1) Insert\n");
        printf("2) Sort\n");
        printf("3) Quit\n");
        printf("Select a menu : ");
        scanf("%d", &select);
        while(getchar()!='\n');
        

        switch(select)
        {
            case 1:

                if (stu_ptr != NULL) 
                {
                    free(stu_ptr);
                    stu_ptr = NULL;
                    stu_num = 0;
                }

                /*make name of file*/
                printf("File name : ");
                scanf("%[^\n]s",filename);


                /* file open*/
                ptr = fopen(filename,"r");
                if(ptr == NULL)
                {
                    printf("file cannot open !\n");
                    printf("----------------------------");
                    exit(1);
                }

                /* Input check */
                while(feof(ptr)==0)
                {
                    stu_ptr = (student_t *)realloc(stu_ptr,sizeof(student_t)*(stu_num+1));

                    fscanf(ptr,"%s %d %d %d %d", (stu_ptr+stu_num)->familyname, &(stu_ptr+stu_num)->age, &(stu_ptr+stu_num)->math, &(stu_ptr+stu_num)->english, &(stu_ptr+stu_num)->history);
                    if((stu_ptr+stu_num)->age <=0)
                    {
                        printf("The age cannot be a negative number. Program terminates.\n");
                        printf("----------------------------");
                        exit(1);
                    }

                    else if((stu_ptr+stu_num)->math <0 || (stu_ptr+stu_num)->math >100 || (stu_ptr+stu_num)->english <0 || (stu_ptr+stu_num)->english >100 || (stu_ptr+stu_num)->history<0 || (stu_ptr+stu_num) -> history >100)
                    {
                        printf("Score must be between 0 and 100. Program terminates\n");
                        printf("----------------------------");
                        exit(1);
                    }

                    stu_num+=1;
                }
                
                printf("Result : \n");
                printf("No Name Age Math English History\n");
                for (int i = 0; i < stu_num; i++)
                {
                    printf("%d %s %3d %4d %5d %6d\n",i+1,(stu_ptr+i)->familyname, (stu_ptr+i)->age, (stu_ptr+i)->math, (stu_ptr+i)->english, (stu_ptr+i)->history);
                }
                
                fclose(ptr);
                break;


            case 2:
                if(stu_ptr == NULL)
                {
                    printf("Result : There is no data to be sorted. Program terminates\n");
                    printf("----------------------------");
                    exit(1);
                }

                printf("1) Name\n");
                printf("2) Age\n");
                printf("3) Math\n");
                printf("4) English\n");
                printf("5) History\n");
                printf("Choose the field to sory by : ");
                scanf("%d", &sort);
                
                /* sort_func */

                switch(sort)
                {
                    case 1:
                    {
                        student_t *sorted_stu_ptr = malloc(sizeof(student_t) * stu_num);
                        if (sorted_stu_ptr == NULL)
                        {
                            printf("Memory allocation error. Program terminates.\n");
                            printf("----------------------------");
                            exit(1);
                        }

                        memcpy(sorted_stu_ptr, stu_ptr, sizeof(student_t) * stu_num);

                        
                        for (int i = 0; i < stu_num - 1; i++)
                        {
                            for (int j = 0; j < stu_num - i - 1; j++)
                            {
                                if (strcmp(sorted_stu_ptr[j].familyname, sorted_stu_ptr[j + 1].familyname) > 0)
                                {
                                    student_t temp = sorted_stu_ptr[j];
                                    sorted_stu_ptr[j] = sorted_stu_ptr[j + 1];
                                    sorted_stu_ptr[j + 1] = temp;
                                }
                            }
                        }

                        printf("No Name Age Math English History\n");
                        for (int i = 0; i < stu_num; i++)
                        {
                            printf("%d %s %3d %4d %7d %7d\n", i + 1, sorted_stu_ptr[i].familyname, sorted_stu_ptr[i].age, sorted_stu_ptr[i].math, sorted_stu_ptr[i].english, sorted_stu_ptr[i].history);
                        }

                        // 정렬된 데이터의 메모리를 해제합니다.
                        free(sorted_stu_ptr);
                        break;
                    }

                    case 2:
                    {
                        student_t *sorted_stu_ptr = malloc(sizeof(student_t) * stu_num);
                        if (sorted_stu_ptr == NULL)
                        {
                            printf("Memory allocation error. Program terminates.\n");
                            printf("----------------------------");
                            exit(1);
                        }

                        memcpy(sorted_stu_ptr, stu_ptr, sizeof(student_t) * stu_num);

                        
                        for (int i = 0; i < stu_num - 1; i++)
                        {
                            for (int j = 0; j < stu_num - i - 1; j++)
                            {
                                if (sorted_stu_ptr[j].age > sorted_stu_ptr[j + 1].age)
                                {
                                    student_t temp = sorted_stu_ptr[j];
                                    sorted_stu_ptr[j] = sorted_stu_ptr[j + 1];
                                    sorted_stu_ptr[j + 1] = temp;
                                }
                            }
                        }

                        printf("No Age Name Math English History\n");
                        for (int i = 0; i < stu_num; i++)
                        {
                            printf("%d %3d %s %4d %7d %7d\n", i + 1, sorted_stu_ptr[i].age, sorted_stu_ptr[i].familyname, sorted_stu_ptr[i].math, sorted_stu_ptr[i].english, sorted_stu_ptr[i].history);
                        }

                        // 정렬된 데이터의 메모리를 해제합니다.
                        free(sorted_stu_ptr);
                        break;
                    }

                    case 3:
                    {
                        student_t *sorted_stu_ptr = malloc(sizeof(student_t) * stu_num);
                        if (sorted_stu_ptr == NULL)
                        {
                            printf("Memory allocation error. Program terminates.\n");
                            printf("----------------------------");
                            exit(1);
                        }

                        memcpy(sorted_stu_ptr, stu_ptr, sizeof(student_t) * stu_num);

                        
                        for (int i = 0; i < stu_num - 1; i++)
                        {
                            for (int j = 0; j < stu_num - i - 1; j++)
                            {
                                if (sorted_stu_ptr[j].math > sorted_stu_ptr[j + 1].math)
                                {
                                    student_t temp = sorted_stu_ptr[j];
                                    sorted_stu_ptr[j] = sorted_stu_ptr[j + 1];
                                    sorted_stu_ptr[j + 1] = temp;
                                }
                            }
                        }

                        printf("No Math Name Age English History\n");
                        for (int i = 0; i < stu_num; i++)
                        {
                            printf("%d %4d %s %3d %7d %7d\n", i + 1, sorted_stu_ptr[i].math, sorted_stu_ptr[i].familyname, sorted_stu_ptr[i].age, sorted_stu_ptr[i].english, sorted_stu_ptr[i].history);
                        }

                        // 정렬된 데이터의 메모리를 해제합니다.
                        free(sorted_stu_ptr);
                        break;
                    }


                    case 4:
                    {
                        student_t *sorted_stu_ptr = malloc(sizeof(student_t) * stu_num);
                        if (sorted_stu_ptr == NULL)
                        {
                            printf("Memory allocation error. Program terminates.\n");
                            printf("----------------------------");
                            exit(1);
                        }

                        memcpy(sorted_stu_ptr, stu_ptr, sizeof(student_t) * stu_num);

                        
                        for (int i = 0; i < stu_num - 1; i++)
                        {
                            for (int j = 0; j < stu_num - i - 1; j++)
                            {
                                if (sorted_stu_ptr[j].english > sorted_stu_ptr[j + 1].english)
                                {
                                    student_t temp = sorted_stu_ptr[j];
                                    sorted_stu_ptr[j] = sorted_stu_ptr[j + 1];
                                    sorted_stu_ptr[j + 1] = temp;
                                }
                            }
                        }

                        printf("No English Name Age Math History\n");
                        for (int i = 0; i < stu_num; i++)
                        {
                            printf("%d %7d %s %3d %4d %7d\n", i + 1, sorted_stu_ptr[i].english, sorted_stu_ptr[i].familyname, sorted_stu_ptr[i].age, sorted_stu_ptr[i].math, sorted_stu_ptr[i].history);
                        }

                        // 정렬된 데이터의 메모리를 해제합니다.
                        free(sorted_stu_ptr);
                        break;
                    }
                       

                    case 5:
                    {
                        student_t *sorted_stu_ptr = malloc(sizeof(student_t) * stu_num);
                        if (sorted_stu_ptr == NULL)
                        {
                            printf("Memory allocation error. Program terminates.\n");
                            printf("----------------------------");
                            exit(1);
                        }

                        memcpy(sorted_stu_ptr, stu_ptr, sizeof(student_t) * stu_num);

                        
                        for (int i = 0; i < stu_num - 1; i++)
                        {
                            for (int j = 0; j < stu_num - i - 1; j++)
                            {
                                if (sorted_stu_ptr[j].history > sorted_stu_ptr[j + 1].history)
                                {
                                    student_t temp = sorted_stu_ptr[j];
                                    sorted_stu_ptr[j] = sorted_stu_ptr[j + 1];
                                    sorted_stu_ptr[j + 1] = temp;
                                }
                            }
                        }

                        printf("No History Name Age Math English\n");
                        for (int i = 0; i < stu_num; i++)
                        {
                            printf("%d %7d %s %3d %4d %7d\n", i + 1, sorted_stu_ptr[i].history, sorted_stu_ptr[i].familyname, sorted_stu_ptr[i].age, sorted_stu_ptr[i].math, sorted_stu_ptr[i].english);
                        }

                        // 정렬된 데이터의 메모리를 해제합니다.
                        free(sorted_stu_ptr);
                        break;
                    }
                        
                } // 내부 switch문 종료

                break;

            
            case 3:
                exit(1);
            
        } //switch문 종료
    } //while문 종료

    return 0;
}



