// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 18-10-2021

// 2. Write a program to implement stack using linked list.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top;

void push(int data);
struct node *pop();
int peep();
void display();

void main()
{
    int choice, value;

    do
    {
        printf("\n********************************************");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peep");
        printf("\n 4. Display");
        printf("\n 0. Exit\n");
        printf("*********************************************\n");

        printf("\n Enter your choice! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the value you want to push in the stack : ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:

            if (top == NULL)
            {
                printf("\n Stack is Empty!");
                exit(0);
            }

            printf("\n The top Element is %d", peep());
            break;

        case 4:

            if (top == NULL)
            {
                printf("\n Stack is Empty!");
                exit(0);
            }

            printf("\n The Stack Contains");
            printf("\n*************");
            display();
            printf("\n*************\n");
            break;

        case 0:
            printf("\n Exiting the code!");
            exit(0);
            break;

        default:
            if (choice > 3 || choice < 0)
            {
                printf("\n Enter Correct Choice!");
                exit(0);
            }
            break;
        }
    } while (choice != 0);
}

void push(int data)
{
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    if (top == NULL)
    {
        temp->info = data;
        temp->link = NULL;
        top = temp;
    }
    else
    {
        temp->info = data;
        temp->link = top;

        top = temp;
    }

    printf("\n %d Pushed in the Stack!", data);
}

struct node *pop()
{
    if (top == NULL)
    {
        printf("\n Stack is Empty!");
        exit(0);
    }
    else
    {
        struct node *temp;

        temp = top->link;

        printf("\n %d Poped from the Stack", top->info);
        free(top);
        top = temp;

        return top;
    }
}

int peep()
{
    struct node *temp;
    temp = top;

    return temp->info;
}

void display()
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("\n %d", temp->info);
        temp = temp->link;
    }
}
