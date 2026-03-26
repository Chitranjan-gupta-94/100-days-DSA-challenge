/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *front = NULL, *rear = NULL, *temp;
    int n, x;
    char op[20];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);

            struct node *newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->next = NULL;

            if(front == NULL)
            {
                front = rear = newnode;
            }
            else
            {
                rear->next = newnode;
                rear = newnode;
            }
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            if(front == NULL)
            {
                printf("-1\n");
            }
            else
            {
                temp = front;
                printf("%d\n", front->data);
                front = front->next;

                if(front == NULL)
                    rear = NULL;

                free(temp);
            }
        }
    }

    return 0;
}