/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, i, x, count = 0;
    struct node *head = NULL, *temp, *newnode;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        count++;
        temp = temp->next;
    }

    return 0;
}