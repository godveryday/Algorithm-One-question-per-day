#include <stdio.h>
#include <string.h>
#include "Stack_Array2.h"

#define MAX 100

void infix_to_postfix(char *ptr1, char *ptr2);
int priority(char op);
int calculate(char *ptr3);

int main()
{
    char array1[MAX];
    char array2[MAX];

    printf("Arithmetic Expression: ");
    scanf("%[^\n]s", array1);
    while (getchar() != '\n');

    printf("Input: %s\n", array1);

    printf("Postfix: ");
    infix_to_postfix(array1, array2);
    printf("%s\n", array2);

    printf("Result: %d\n", calculate(array2));

    return 0;
}

void infix_to_postfix(char *ptr1, char *ptr2)
{
    stack_t *base_ptr = create_stack(MAX);
    char top_op, ch;
    int ptr2_index = -1;

    for (int i = 0; i < strlen(ptr1); i++)
    {
        ch = ptr1[i];
        if (ch == ' ')
        {
            continue;
        }
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (!Isemptystack(base_ptr->top) && priority(ch) <= priority(top(base_ptr)))
            {
                ptr2[++ptr2_index] = pop(base_ptr);
            }
            push(base_ptr, ch);
            break;

        case '(':
            push(base_ptr, ch);
            break;

        case ')':
            top_op = pop(base_ptr);
            while (top_op != '(')
            {
                ptr2[++ptr2_index] = top_op;
                top_op = pop(base_ptr);
            }
            break;

        default:
            // Handle multi-digit numbers
            while (i < strlen(ptr1) && ptr1[i] >= '0' && ptr1[i] <= '9')
            {
                ptr2[++ptr2_index] = ptr1[i++];
            }
            ptr2[++ptr2_index] = ' '; // Add a space to separate numbers
            i--; // Move the index back to account for the extra increment
            break;
        }
    }

    while (!Isemptystack(base_ptr->top))
    {
        ptr2[++ptr2_index] = pop(base_ptr);
    }
    ptr2[++ptr2_index] = '\0';
    Destroystack(base_ptr);
}

int priority(char op)
{
    if (op == '*' || op == '/' || op == '%')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else if (op == '(')
        return 1;
    else
        return -1;
}

int calculate(char *ptr3)
{
    stack_t *base_ptr = create_stack(MAX);
    int num1, num2;
    char ch;

    for (int i = 0; i < strlen(ptr3); i++)
    {
        ch = ptr3[i];
        if (ch == ' ')
        {
            continue;
        }
        if (ch >= '0' && ch <= '9')
        {
            // Handle multi-digit numbers
            int num = 0;
            while (ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0');
                i++;
                ch = ptr3[i];
            }
            i--; // Move the index back to account for the extra increment
            push(base_ptr, num);
        }
        else
        {
            num2 = pop(base_ptr);
            num1 = pop(base_ptr);

            switch (ch)
            {
            case '+':
                push(base_ptr, num1 + num2);
                break;

            case '-':
                push(base_ptr, num1 - num2);
                break;

            case '*':
                push(base_ptr, num1 * num2);
                break;

            case '/':
                push(base_ptr, num1 / num2);
                break;

            case '%':
                push(base_ptr, num1 % num2);
                break;
            }
        }
    }
    int result = pop(base_ptr);
    return result;
}
