// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 25-08-2021

// 2. Implement C program to reverse a string and print it using Stack.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void revString(char str[]);
void push(char a, int *top, int stack_arr[]);
char pop(int *top, int stack_arr[]);

void main()
{
    printf("\n Ibrahim Ghasia-200420107045");

    char str[50];

    printf("\n*******************************");
    printf("\nEnter a String : ");
    gets(str);
    printf("Reverserd String is : ");
    revString(str); // Calling revString function
    printf("*******************************\n");
}

void revString(char str[])
{
    int i, len, stack[MAX], top = -1;
    char a;
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        a = str[i];
        push(a, &top, stack); // Pushing the elements in the Stack
    }

    while (top != -1)
    {
        printf("%c", pop(&top, stack)); // Poping elements from the Stack
    }
    printf("\n");
}

void push(char a, int *top, int stack_arr[])
{
    if (*top == (MAX - 1))
    {
        printf("\n Stack is full!");
    }
    else
    {
        *top = *top + 1;
        stack_arr[*top] = a;
    }
}

char pop(int *top, int stack_arr[])
{
    char x;

    if (*top == -1)
    {
        printf("\n Stack is Empty!");
    }
    else
    {
        x = stack_arr[*top];
        *top = *top - 1;
    }
    return x;
}
