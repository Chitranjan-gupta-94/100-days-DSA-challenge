/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* push(struct node *top, int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    return newnode;
}

struct node* pop(struct node *top, int *val)
{
    struct node *temp;
    if(top == NULL)
        return NULL;

    *val = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return top;
}

int main()
{
    struct node *top = NULL;
    int a, b, res, num;
    char token;

    while(scanf(" %c", &token) != EOF)
    {
        if(token >= '0' && token <= '9')
        {
            num = token - '0';
            top = push(top, num);
        }
        else
        {
            top = pop(top, &b);
            top = pop(top, &a);

            if(token == '+') res = a + b;
            if(token == '-') res = a - b;
            if(token == '*') res = a * b;
            if(token == '/') res = a / b;

            top = push(top, res);
        }
    }

    printf("%d", top->data);

    return 0;
}