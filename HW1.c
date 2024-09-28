#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<string.h>

int main()
{
    struct
    {
        char fullname[50];  //전체 이름
        char *lastname;     //성을 가리키는 포인터
        char *firstname;    // 이름을 가리키는 포인터
        int age;
        char sex;
    }student;
    
    while(1)
    {
        int generation;
        //programming going on
        printf("Provide your personal information: \n");
        printf("Name : ");
        scanf(" %[^\n]s", student.fullname);           //공백까지 포함하여 문자열 입력받음..!!
        
        student.firstname = strtok(student.fullname," ");
        student.lastname = strtok(NULL, " ");
        
        if(strcmp(student.firstname,"stop") == 0 || strcmp(student.lastname, "stop") == 0)
        {
            break;
        }

        printf("Age : ");
        scanf(" %d", &student.age);

        generation = student.age/10;

        printf("Sex (M/F) : ");
        scanf(" %c", &student.sex);
        printf("\n");

        printf("Your name is %s %s, you are in %d0s, your sex is %c\n\n\n",student.lastname, student.firstname, generation ,student.sex);
    }

    return 0;
}

