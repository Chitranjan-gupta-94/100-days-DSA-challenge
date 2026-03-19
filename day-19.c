/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    int a[100];
    int minSum, sum;
    int x, y;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    minSum = abs(a[0] + a[1]);
    x = a[0];
    y = a[1];

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            sum = abs(a[i] + a[j]);

            if(sum < minSum)
            {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}