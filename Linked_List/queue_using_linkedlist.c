// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 26-10-2021

// 3. Write a program to implement queue using linked list.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node *f;
struct node *r;

struct node
{
    int info;
    struct node *link;
};

void enqueue(int value);
int dequeue();
void display();

void main()
{
    int choice, val_ins, val_del;

    do
    {
        printf("\n****************");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Diplay");
        printf("\n 0. Exit");
        printf("\n****************\n");

        printf("\n Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n Enter the value you want to insert : ");
            scanf("%d", &val_ins);

            enqueue(val_ins);
            break;

        case 2:
            val_del = dequeue();
            printf("\n %d Deleted from the queue!", val_del);
            break;

        case 3:
            if (f == NULL)
            {
                printf("\n Linked List is Empty!");
                exit(0);
            }
            printf("\n The Linked List Containes!");
            printf("\n*****");
            display(f);
            printf("\n*****\n");
            break;

        case 0:
            printf("\n Exiting the code!");
            exit(0);
            break;

        default:
            if (choice > 2 || choice < 0)
            {
                printf("\n Invalid Choice!");
                exit(0);
            }
            break;
        }
    } while (choice != 0);
}

void enqueue(int value)
{
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->info = value;
    new_node->link = NULL;

    if (f == NULL)
    {
        f = r = new_node;
    }
    else
    {
        r->link = new_node;
        r = new_node;
    }
}

int dequeue()
{
    int value = -1;

    if (f == NULL)
    {
        printf("\n Linked List is Empty!");
        exit(0);
    }

    struct node *ptr;
    ptr = f;

    f = f->link;
    value = ptr->info;

    free(ptr);

    return value;
}

void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("\n %d", temp->info);
        temp = temp->link;
    }
}
