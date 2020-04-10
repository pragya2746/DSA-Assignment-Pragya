#include<stdio.h>
char stack[50];
int top = -1;
void push(char val)
{
    stack[++top] = val;
}
 
char pop()
{
    if(top == -1)
        return -1;
      
    else
        return stack[top--];
}
 
int preference(char val)
{
    if(val == '(')
        return 0;
    if(val == '+' || val == '-')
        return 1;
    if(val == '*' || val == '/')
        return 2;
}
 
int main()
{
    char exp[20];
    char *e, val;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((val = pop()) != '(')
                printf("%c", val);
        }
        else
        {
            while(preference(stack[top]) >= preference(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
return 0;
}
