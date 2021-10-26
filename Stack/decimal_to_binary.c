// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 25-08-2021

// 1. Implement C program to convert decimal number into binary using stack.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 50

void DecToBin(int num);
void push(int rem, int *top, int stack_arr[]);
int pop(int *top, int stack_arr[]);

void main()
{
    printf("\n Ibrahim Ghasia-200420107045");

    int n;

    printf("\n*******************************");
    printf("\nEnter any Decimal Number : ");
    scanf("%d", &n);

    printf("Binary Equivalent is : ");
    DecToBin(n); // Calling DecToBin Function!
    printf("*******************************\n");
    printf("\n");
}

void DecToBin(int num)
{
    int rem, stack[MAX], top = -1;

    while (num != 0)
    {
        rem = num % 2;
        push(rem, &top, stack); // Pushing Remainder Value
        num /= 2;
    }
    while (top != -1)
    {
        printf("%d", pop(&top, stack)); // Poping Remainder Value
    }
    printf("\n");
}

void push(int rem, int *top, int stack_arr[])
{
    if (*top == (MAX - 1)) // To check the Stack is Full or not
    {
        printf("\n The Stack is full");
    }
    else
    {
        *top = *top + 1;
        stack_arr[*top] = rem;
    }
}

int pop(int *top, int stack_arr[])
{
    int x;
    if (*top == -1)
    {
        printf("\n Stack is Empty"); // To check the Stack is Empty or not
    }
    else
    {
        x = stack_arr[*top];
        *top = *top - 1;
    }
    return x;
}
