/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int x, i;

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

    return head;
}

int length(struct node *head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

int main()
{
    int n, m, d;
    struct node *list1, *list2, *p1, *p2;

    scanf("%d", &n);
    list1 = createList(n);

    scanf("%d", &m);
    list2 = createList(m);

    int l1 = length(list1);
    int l2 = length(list2);

    p1 = list1;
    p2 = list2;

    if(l1 > l2)
    {
        d = l1 - l2;
        while(d--) p1 = p1->next;
    }
    else
    {
        d = l2 - l1;
        while(d--) p2 = p2->next;
    }

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data == p2->data)
        {
            printf("%d", p1->data);
            return 0;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");

    return 0;
}