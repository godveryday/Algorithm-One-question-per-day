#define _CRT_SECURE_NO_WARNINGS    // strtok ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<string.h>

int main()
{
    struct
    {
        char fullname[50];  //��ü �̸�
        char *lastname;     //���� ����Ű�� ������
        char *firstname;    // �̸��� ����Ű�� ������
        int age;
        char sex;
    }student;
    
    while(1)
    {
        int generation;
        //programming going on
        printf("Provide your personal information: \n");
        printf("Name : ");
        scanf(" %[^\n]s", student.fullname);           //������� �����Ͽ� ���ڿ� �Է¹���..!!
        
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

