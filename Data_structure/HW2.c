#include<stdio.h>

void ascending_func(int *);
void descending_func(int *);

int main()
{
    while(1)
    {
        int outswitch=0;
        int array[2][10];           
        int *ptr1=&array[0][0];        //2차원 배열에서 포인터 사용시 이렇게 선언 chechk하기!
        
        printf("Input : \n");

        /* Input 10 check */
        //여기서 입력받을 때 이렇게 전부 써서 받지말고
        /* 이렇게 해보기
        res = scanf("%d,",array[0][0]); 
        while(res==1)
        {   
            for문
            res = scanf("%d,",array[0][i])
        }
        */
        if(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
        &array[0][0],&array[0][1],&array[0][2],&array[0][3],&array[0][4],&array[0][5],&array[0][6],&array[0][7],&array[0][8],&array[0][9])!=10)  //scanf를 if문안에서 사용, scanf는 반환값으로 입력된 데이터의 수를 반환함.
        {
            printf("\nOutput : \n\n");
            printf("You should input 2 sets of 10 numbers.");
            break;
        }
        //while(getchar()!='\n');
        
        /* Input ascending check */
        for(int i=0; i<9; i++)
        {
            if(*(ptr1+i)>*(ptr1+i+1))       
            {
                printf("\nOutput : \n\n");
                printf("The input numbers are not in ascending order.");
                outswitch+=1;
                break;
            }
        }
        /* If input not ascending break */
        if(outswitch==1)
        {
            break;
        }

        /* Input 10 check */
        if(scanf(" %d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
        &array[1][0],&array[1][1],&array[1][2],&array[1][3],&array[1][4],&array[1][5],&array[1][6],&array[1][7],&array[1][8],&array[1][9])!=10)
        {
            printf("\nOutput : \n\n");
            printf("You should input 2 sets of 10 numbers.");
            break;
        }

        /* Input ascending check */
        for(int i=10; i<19; i++)
        {
            if(*(ptr1+i)>*(ptr1+i+1))
            {
                printf("\nOutput : \n\n");
                printf("The input numbers are not in ascending order.");
                outswitch+=1;
                break;
            }
        }

        /* If input not ascending break */
        if(outswitch==1)
        {
            break;
        }

        printf("\n");
        printf("Output : \n");
        
        /* Make array ascending */
        ascending_func(ptr1);       

        /* Print descending num */
        descending_func(ptr1);      
    }


    return 0;
}


void ascending_func(int *ptr2)
{
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19-i; j++)
        {
            if(*(ptr2+j)>*(ptr2+j+1))
            {
                int temp;
                temp = *(ptr2+j+1);
                *(ptr2+j+1) = *(ptr2+j);
                *(ptr2+j) = temp;
            }
        }
    }
}


void descending_func(int *ptr3)
{
    for(int i=19; i>-1; i--)
    {
        if(i!=0 && *(ptr3+i)==*(ptr3+i-1))
        {
            continue;
        }

        printf(" %d", *(ptr3+i));
    }
    printf("\n\n\n");
}

