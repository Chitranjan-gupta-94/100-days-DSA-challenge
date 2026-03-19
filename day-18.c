/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>

int main()
{
    int n, k, i;
    int a[100], b[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    k = k % n;

    for(i = 0; i < n; i++)
        b[(i + k) % n] = a[i];

    for(i = 0; i < n; i++)
        printf("%d ", b[i]);

    return 0;
}