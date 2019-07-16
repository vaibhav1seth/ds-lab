#include<stdio.h>
#include<math.h>
#include<strings.h>
int top=-1;
char po[10];int stack[10];
void push(int n)
{
	stack[++top]=n;
}
int pop()
{
	return(stack[top--]);
}
void main()
{
	int i=0,temp,op1,op2,res;
	char ch;
	printf("enter the postfix expression\n");
	gets(po);
	while(po[i]!='\0')
	{	
		ch=po[i];
		if(isalpha(ch))
		{
			printf("enter the value of %c",ch);
			scanf("%d",&temp);
			push(temp);
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case'+':res=op1+op2;break;
				case'-':res=op1-op2;break;
				case'*':res=op1*op2;break;
				case'/':res=op1/op2;break;
				case'^':res=pow(op1,op2);break;
			}
			push(res);
		}
		i++;
	}
	printf("\nresult is : %d",pop());
} 
	
		
