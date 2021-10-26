// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 20-09-2021

/* 1. Write a menu driven program to implement following operations on the singly linked list. Design a function create to create a link list (which is required to be called only for one time for a link list)

(a) create [ node * create() ]
(b) display [ void display(node *start) ]
(c) length [ int length (node *start) ]
(d) maximum [int maximum (node *start)]
(e) merge (to merge two link list in to the third one) [node * merge(node *start1, node *start2)
(f) sort [void sort(node *start) ]
(g) reverse [ node * reverse (node *start)]
(h) Insert a node at the front of the linked list. [ node * insert_front(node *start, int no) ]
(i) Insert a node at the end of the linked list. [ node * insert_end(node *start, int no) ]
(j) Insert a node such that linked list is in ascending order.(according to info. Field) [ node * insert_sort(node *start, int no) ]
(k) Delete a first node of the linked list. [ node * delete_first(node *start) ]
(l) Delete a node before specified position. [ node * delete_before(node *start, int pos) ]
(m) Delete a node after specified position. [ node * delete_after(node *, int pos) ]
(n) Number search [ int search (node*, int x) ] */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Main Functions
struct node *create();
void display(struct node *e);
int length(struct node *n);
int maximum(struct node *n);
struct node *merge(struct node *start1, struct node *start2);
void sort(struct node *start);
struct node *reverse(struct node *head);
struct node *insert_front(struct node *start, int no);
struct node *insert_end(struct node *start, int no);
struct node *insert_sort(struct node *start, int no);
struct node *delete_first(struct node *start);
struct node *delete_before(struct node *start, int pos);
struct node *delete_after(struct node *, int pos);
int search(struct node *start, int x);

// Supporting Functions
void push1(int *stack, int *top, int val);
int pop1(int *stack, int *top);

void main()
{
    int choice, len, max, no, pos1, pos2, x, ans, y, s_no;
    struct node *head, *head2, *head3;

    do
    {
        printf("\n********************************************");
        printf("\n 1. Create");
        printf("\n 2. Display");
        printf("\n 3. Length");
        printf("\n 4. Maximum");
        printf("\n 5. Merge");
        printf("\n 6. Sort");
        printf("\n 7. Reverse");
        printf("\n 8. Insert a node at the front of Linked list");
        printf("\n 9. Insert a node at the end of Linked list");
        printf("\n 10. Insert a node in the middle of the sorted linkedList");
        printf("\n 11. Delete the first node of the Linked list");
        printf("\n 12. Delete a node before specified position");
        printf("\n 13. Delete a node after specified position");
        printf("\n 14. Search");
        printf("\n 0. Exit\n");
        printf("*********************************************\n");

        printf("\n Enter the Choice! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;

        case 2:
            printf("\n The Linked List Contains : ");
            printf("\n********************");
            display(head);
            printf("\n********************\n");

            break;

        case 3:
            len = length(head);
            if (len == 0)
            {
                printf("\n Linked list is Empty!");
            }
            else
            {
                printf("\n Length of the Linked list is : %d", len);
            }
            break;

        case 4:
            max = maximum(head);
            if (max == -9999)
            {
                printf("\n Linked List is Empty");
            }
            else
            {
                printf("\n Maximum is : %d", max);
            }
            break;

        case 5:
            head2 = create();
            printf("\n Enter the number of elements you want to insert after the first one in the 2nd Linked List : ");
            scanf("%d", &y);

            for (int i = 0; i < y; i++)
            {
                printf("\n Enter the %d element : ", i + 2);
                scanf("%d", &s_no);

                insert_end(head2, s_no);
            }

            head3 = merge(head, head2);
            display(head3);
            break;

        case 6:
            sort(head);
            printf("\n Your Shorted Linked List!");
            display(head);
            break;

        case 7:
            head = reverse(head);
            break;

        case 8:
            printf("\n Enter the value of node to be inserted at first position : ");
            scanf("%d", &no);

            head = insert_front(head, no);
            printf("\n %d Inserted at the front of the Linked List!", no);
            break;

        case 9:
            printf("\n Enter the value of node to be inserted at last position : ");
            scanf("%d", &no);

            head = insert_end(head, no);
            printf("\n %d Inserted at the end of the Linked List!", no);
            break;

        case 10:
            printf("\n Enter the value of node to be inserted : ");
            scanf("%d", &no);

            head = insert_sort(head, no);
            break;

        case 11:
            head = delete_first(head);
            break;

        case 12:
            printf("\n Enter the position you want to delete a node before specified position : ");
            scanf("%d", &pos1);

            head = delete_before(head, pos1);
            break;

        case 13:
            printf("\n Enter the position you want to delete a node after specified position : ");
            scanf("%d", &pos2);

            head = delete_after(head, pos2);
            break;

        case 14:
            printf("\n Enter the Number you want to search in the Linked List : ");
            scanf("%d", &x);

            ans = search(head, x);

            if (ans == -1)
            {
                printf("\n Linked List is Empty! Insert the element first!");
            }

            if (ans == 1)
            {
                printf("\n %d Found in the Linked List!", x);
            }

            if (ans == 0)
            {
                printf("\n %d Does not found in the Linked List!", x);
            }

            break;

        case 0:
            printf("\n Exiting the code!");
            exit(0);

        default:
            if (choice > 14 || choice < 0)
            {
                printf("\n Enter correct choice!");
                exit(0);
            }
            break;
        }
    } while (choice != 0);
}

// A
struct node *create()
{
    int val;
    struct node *fll;

    fll = (struct node *)malloc(sizeof(struct node));

    if (fll == NULL)
    {
        printf("\n New Node Cannot be allocated");
        return NULL;
    }

    printf("\n Enter the first element in the Linked List : ");
    scanf("%d", &val);

    fll->info = val;
    fll->link = NULL;

    return fll;
}

//B
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        return;
    }

    while (start != NULL)
    {
        printf("\n %d", start->info);
        start = start->link;
    }
}

//C
int length(struct node *start)
{
    int len = 0;

    if (start == NULL)
        return 0;
    else
    {
        while (start != NULL)
        {
            len++;
            start = start->link;
        }
    }

    return len;
}

//D
int maximum(struct node *start)
{
    int max;

    if (start == NULL)
        return -9999;
    else
    {
        max = start->info;
        start = start->link;

        while (start != NULL)
        {
            if (start->info > max)
            {
                max = start->info;
            }
            start = start->link;
        }
    }
    return max;
}

//E
struct node *merge(struct node *start1, struct node *start2)
{
    struct node *temp1, *temp2, *temp3;

    temp1 = start1;
    temp2 = start2;

    while (temp1->link != NULL)
    {
        temp1 = temp1->link;
    }

    temp1->link = temp2;

    // temp1 = start1;

    return temp1;
}

//F
void sort(struct node *start)
{
    struct node *temp1, *temp2;
    int temp;

    for (temp1 = start; temp1 != NULL; temp1 = temp1->link)
    {
        for (temp2 = temp1->link; temp2 != NULL; temp2 = temp2->link)
        {
            if (temp1->info > temp2->info)
            {
                temp = temp1->info;
                temp1->info = temp2->info;
                temp2->info = temp;
            }
        }
    }
}

//G
struct node *reverse(struct node *head)
{
    // struct node *rev = NULL, *headrev = NULL;
    // int *stack = NULL, i, top = -1;
    // stack = (int *)calloc(length(head), sizeof(int));

    // while (head != NULL)
    // {
    //     push(&stack[i++], head->info);
    //     head = head->link;
    //     top++;
    // }

    // while (top > -1)
    // {
    //     rev = insert_end(rev, pop(stack, &top));

    //     if (headrev == NULL)
    //         headrev = rev;
    // }

    // return headrev;

    int len, top = -1, *stack, i = 0;
    len = length(head);

    if (len == 0)
    {
        printf("\n Linked List is Empty!");
        return NULL;
    }

    stack = (int *)malloc(sizeof(int));

    struct node *temp, *first_rev, *temp1;

    temp = head;

    while (temp != NULL)
    {
        push1(stack, &top, temp->info);
        temp = temp->link;
    }

    first_rev = (struct node *)malloc(sizeof(struct node));

    temp1 = first_rev;

    while (i < len)
    {
        temp1->info = pop1(stack, &top);
        if (top >= 0)
        {
            temp1->link = (struct node *)malloc(sizeof(struct node));
            temp1 = temp1->link;
        }

        else
        {
            temp1->link = NULL;
            break;
        }
    }

    return first_rev;
}

//H
struct node *insert_front(struct node *start, int no)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL)
    {
        printf("\n Memory not allocated!");
    }
    else
    {
        temp->info = no;
        temp->link = start;

        if (start == NULL)
            return temp;

        return temp;
    }
}

//I
struct node *insert_end(struct node *start, int no)
{

    struct node *temp;
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\n Memory Not allocated!");
    }
    else
    {
        new_node->info = no;
        new_node->link = NULL;

        if (start == NULL)
        {
            return new_node;
        }

        temp = start;

        while (temp != NULL && temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = new_node;
    }

    return start;
}

//J
struct node *insert_sort(struct node *start, int no)
{
    sort(start);
    int len = length(start);
    int max = maximum(start);

    struct node *new_node, *temp, *temp1;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->info = no;
    new_node->link = NULL;

    temp = start;

    for (int i = 1; i < len; i++)
    {
        temp1 = temp;
        temp = temp->link;

        if (no < temp->info)
        {
            new_node->link = temp1->link;
            temp1->link = new_node;

            // printf("\n%d", temp1->info);
            break;
        }
    }

    if (no > max)
    {
        printf("\n Invalid Choice. Number gretter than maximum number in the linkedlist cannot be inserted for this choice");
    }

    return start;
}

//K
struct node *delete_first(struct node *start)
{
    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        return NULL;
    }

    struct node *temp;
    temp = start->link;
    free(start);

    printf("\n First Node Succesfully Deleted!");

    return temp;
}

//L
struct node *delete_before(struct node *start, int pos)
{
    int i, len = length(start);
    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        return NULL;
    }

    if (pos == 1)
    {
        printf("\n Invalid Position! There is no node before first node!!");
        exit(0);
    }

    if (pos > len)
    {
        printf("\n Invalid Position! The Likedlist contains only %d elements", len);
        exit(0);
    }

    struct node *temp, *temp1;

    temp = start;
    for (i = 1; i < pos - 1; i++)
    {
        temp1 = temp;
        temp = temp->link;
    }

    temp1->link = temp->link;

    free(temp);

    return start;
}

//M
struct node *delete_after(struct node *start, int pos)
{
    int i;
    int len = length(start);
    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        return NULL;
    }

    if (pos == len)
    {
        printf("\n Invalid Position! There is no node after %d position!", pos);
        exit(0);
    }

    if (pos > len)
    {
        printf("\n Invalid Position! The Likedlist contains only %d elements", len);
        exit(0);
    }

    struct node *temp, *temp1;

    temp = start;
    for (i = 1; i < pos + 1; i++)
    {
        temp1 = temp;
        temp = temp->link;
    }

    temp1->link = temp->link;

    free(temp);

    return start;
}

//N
int search(struct node *start, int x)
{
    if (start == NULL)
    {
        return -1;
    }

    struct node *temp;

    temp = start;

    while (temp->link != NULL)
    {
        if (temp->info == x)
        {
            return 1;
        }

        temp = temp->link;
    }

    return 0;
}

// Supporting Functions.

void push1(int *stack, int *top, int val)
{
    (*top)++;
    stack[*top] = val;
}

int pop1(int *stack, int *top)
{
    int a;
    a = stack[*top];
    (*top)--;

    return a;
}
