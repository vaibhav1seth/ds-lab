#include<stdio.h>
#include<string.h>
int top=-1;
char stack[10],infix[10],post[10];
void push(char c)
{
	stack[++top]=c;
}
int pop()
{
	return(stack[top--]);
}
int isop(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		return 1;
	else
		return 0;
}
int precedence(char ch)
{
	switch(ch)
	{	
		case'^':return 3;break;
		case'*':
		case'/':return 2;break;
		case'+':
		case'-':return 1;break;
		default:return 0;break;
	}
}
void main()
{
	char ch,x;
	int i=0,j=0;
	printf("enter the infix expression\n");
	gets(infix);
	while(infix[i]!='\0')
	{
		ch=infix[i];
		if(ch=='(')
		{
			push(ch);
		}
		else if(isalpha(ch))
		{
			post[j]=ch;
			j++;
		}
		else if(isop(ch)==1)
		{
			if(ch!='^')
			{
				while(top!=-1 && precedence(stack[top])>=precedence(ch))
				{
					post[j]=pop();
					j++;
				}
			}
			push(ch);
		}
		else if(ch==')')
		{
			while(stack[top]!='(')
			{	
				post[j]=pop();
//				printf("%c",stack[top]);
				j++;
			}
			x=pop();
		}
		else
		{
			printf("invalid expression\n");
		}
		i++;
	}
	while(top!=-1)
	{
		post[j]=pop();
		j++;
	}
	printf("\npostfix expression is ");
	puts(post);
}


