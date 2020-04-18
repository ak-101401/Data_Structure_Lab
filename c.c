//Infix to Postfix Conversion
//BY ADITYA KALRA, IT, 11912038

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stack[1000];
int top=-1;
int precedence(char e)
{
    if (e=='+'||e=='-')
    return 1;
    else if (e=='*'||e=='/')
    return 2;
    else if (e=='^')
    return 3;
    else if (e=='('||e=='{'||e=='[')
    return 0;
    else return -1;
}
char pop()
{
    if (top==-1)
    {
        printf("Underflow\n");
        exit(0);
    }
    char temp=stack[top];
    top--;
    return temp;
}
push(char e)
{
    if (top==999)
    {
        printf("Overflow\n");
        exit(0); 
    }
    top++;
    stack[top]=e;
}
int main()
{
    char exp[1000];
    scanf("%s",exp);
    int len=strlen(exp),e,temp;
    for (int i=0;i<len;i++)
    {
        e=exp[i];
        int pr=precedence(e);
        if (e=='(' || e=='{' || e=='[')push(e);
        else if (e==')' || e=='}' || e==']')
        {
            while(1){
                temp=pop();
                if (temp=='(' || temp=='{' || temp=='[')
                break;
                printf ("%c",temp);
            }
        }
        else if (pr!=-1)
        {
            while(top!=-1 && pr<=precedence(stack[top]))
            {
                printf("%c",pop());
            }
            push(e);
        }
        else
        printf ("%c",e);
    }
    while(top!=-1)
    printf("%c",stack[top--]);
}










//The program is created by ADITYA KALRA
