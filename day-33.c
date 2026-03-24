/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], stack[100], postfix[100];
    int i = 0, j = 0, top = -1;

    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = stack[top];
                top--;
            }

            top++;
            stack[top] = infix[i];
        }

        i++;
    }

    while(top != -1)
    {
        postfix[j++] = stack[top];
        top--;
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}