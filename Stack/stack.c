// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 6-09-2021

/* 3. Implement a program for stack that performs following operations using array. 
(a) PUSH (b) POP (c) PEEP (d) CHANGE(Replace top of stack value) (e) DISPLAY */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int isFull();
int isEmpty();
void push(int item);
int pop();
int peep();
void display();
void change(int value);
    
#define size 10

int stack[size], top = -1;

void main()
{
    printf("\n Ibrahim Ghasia-200420107045");
    int n, choice, push_value, change_value, peep_value;

    do
    {
        system("cls");
        printf("\n******************************************");
        printf("\n Enter 1 to push value into stack : ");
        printf("\n Enter 2 to pop value from stack : ");
        printf("\n Enter 3 to peep value from stack : ");
        printf("\n Enter 4 to change any value from stack : ");
        printf("\n Enter 5 to Display Stack : ");
        printf("\n Enter 6 to Quit : ");
        printf("\n******************************************\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\n Enter the value you want to push : ");
            scanf("%d", &push_value);

            push(push_value); // Calling Push Function.

            break;

        case 2:
            pop(); // Calling Pop Function.
            break;

        case 3:
            peep_value = peep(); // Calling Peep Function and storing its value in peep_value.
            printf("\n %d", peep_value);
            break;

        case 4:
            if (isEmpty() == 1)
            {
                printf("\n The Stack is Empty! Please insert Element into the Stack first.");
                exit(0);
            }

            printf("\n Enter the value you want to change from the stack : ");
            scanf("%d", &change_value);

            change(change_value); // Calling Change Function.
            break;

        case 5:
            display(); // Caling Display Function.
            break;

        case 6:
            printf("\n Exiting the code !!");
            exit(0); // Exiting Function
            break;

        default:
            printf("\n Please enter choice between 1 to 6 !");
            break;
        }
        printf("\n");
        system("pause");
    } while (choice != 6);
}

// To check the stack is full or not.
int isFull()
{
    if (top >= size - 1)
        return 1;
    else
        return 0;
}

// To check the stack is Empty or not.
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Push Function
void push(int item)
{
    if (isFull() == 1)
    {
        printf("\n The Stack is Full !!");
        exit(0);
    }
    else
    {
        top++; // Incrimenting the value of top first.
        stack[top] = item;
        printf("\n %d pushed in the Stack", item);
    }
}

// Pop Function
int pop()
{
    int item;

    if (isEmpty() == 1)
    {
        printf("\n The Stack is Empty! Please insert Element into the Stack first.");
        exit(0);
    }
    else
    {
        item = stack[top];
        top--;
        printf("\n %d is poped from the stack", item);
    }

    return item;
}

// Peep Function
int peep()
{
    int item;

    if (isEmpty() == 1)
    {
        printf("\n The Stack is Empty! Please insert element is Stack first.");
        exit(0);
    }
    else
    {
        item = stack[top];
    }

    return item;
}

// Display Function
void display()
{
    int i;

    if (isEmpty() == 1)
    {
        printf("\n The Stack is Empty! Please insert Element into the Stack first.");
        exit(0);
    }
    else
    {
        printf("\n The Stack contains : \n");

        for (i = top; i >= 0; i--)
        {
            printf("\n %d", stack[i]);
        }
    }
}

// Chnage Function
void change(int value)
{
    int i, a, count = 0;

    printf("\n Enter the new value : ");
    scanf("%d", &a);

    for (i = top; i >= 0; i--)
    {
        if (stack[i] == value)
        {
            stack[i] = a;
            count++;
            break;
        }
    }

    if (count == 0)
    {
        printf("\n The value not found in Stack!");
        exit(0);
    }

    display(); // Calling Display Function within another function.
}
