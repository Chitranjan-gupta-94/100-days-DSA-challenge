/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <string.h>

int main()
{
    int pq[100], size = 0;
    int n, i, x, j, minIndex;
    char op[10];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            pq[size++] = x;
        }
        else if(strcmp(op, "delete") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                minIndex = 0;

                for(j = 1; j < size; j++)
                    if(pq[j] < pq[minIndex])
                        minIndex = j;

                printf("%d\n", pq[minIndex]);

                for(j = minIndex; j < size - 1; j++)
                    pq[j] = pq[j + 1];

                size--;
            }
        }
        else if(strcmp(op, "peek") == 0)
        {
            if(size == 0)
                printf("-1\n");
            else
            {
                minIndex = 0;

                for(j = 1; j < size; j++)
                    if(pq[j] < pq[minIndex])
                        minIndex = j;

                printf("%d\n", pq[minIndex]);
            }
        }
    }

    return 0;
}