// Author: Ibrahim Ghasia
// Enrolment No: 200420107045
// Date: 25-08-2021

// 3. Check the string for the PALINDROME provided middle character is always 'x' and 'x' is not used elsewhere in the
// string using Stack.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void push(char a, int *top, char stack_arr[]);
char pop(int *top, char stack_arr[]);
void check(char *str);

void main()
{
    printf("\n Ibrahim Ghasia-200420107045");

    int top = -1, count = 0;
    char str[50], mid_char, stack[MAX];
    int len, mid, i;

    printf("\n Enter a String (Note: Enter an Odd String !): ");
    gets(str);

    len = strlen(str);   // To calculate Length of the String
    mid = (len / 2);     // To store the middle index of the String
    mid_char = str[mid]; // To store middle character from the String

    check(str); // Calling Check Function to check the String.

    for (i = 0; i < len; i++)
    {
        push(str[i], &top, stack); // Calling push till the lenght of the string.
    }

    for (i = 0; i < len; i++)
    {
        if (pop(&top, stack) != str[i]) // Poping and checking if the string is Palindrome or not.
        {
            count++;
            break;
        }
    }

    if (count != 0)
    {
        printf("\n**************************");
        printf("\n String is Not Palindrome!");
        printf("\n**************************");
    }
    else
    {
        printf("\n**********************");
        printf("\n String is Palindrome!");
        printf("\n**********************");
    }
}

void push(char a, int *top, char stack_arr[]) // Push Function
{
    stack_arr[++*top] = a;
}

char pop(int *top, char stack_arr[]) // Pop Function
{
    return stack_arr[--*top + 1];
}

void check(char *str) // Check Function
{
    int len, mid, i;
    char mid_char;

    len = strlen(str);
    mid = (len / 2);
    mid_char = str[mid];

    if (len % 2 != 0) // To check if the String entered is Odd or Even
    {
        if (mid_char != 'X' && mid_char != 'x') // To check x is present at middle of the string or not.
        {
            printf("\n Invalid String (X is not present at middle of the string!)");
            exit(0);
        }
    }
    else
    {
        printf("\n Invalid String (The String is Even!)");
        exit(0);
    }

    for (i = mid + 1; i < len; i++) // To check x is not present at some other places in the string.
    {
        if (str[i] == 'X' || str[i] == 'x')
        {
            printf("\n Invalid String (X is at other places)");
            exit(0);
        }
    }
}
