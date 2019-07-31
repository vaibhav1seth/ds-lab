#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *temp=NULL,*ptr=NULL,*last = NULL;
void insertbeg()
{
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	if(last==NULL)
	{	temp->next=temp;
		last=temp;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		
	}
}
void insertend()
{
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	if(last==NULL)
	{	temp->next=temp;
		last=temp;
	}
	else
	{
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
}

void insertany()
{
	
	if(last==NULL)
	{	temp->next=temp;
		last=temp;
	}
	else
	{
		int count=0,pos,i;
		ptr=last->next;
		while(ptr!=last)
		{
			count++;
			ptr=ptr->next;
		}
		
		printf("enter the position\n");
		scanf("%d",&pos);
		if(pos==1)
		{
			insertbeg();
		}
		else if(pos>1 && pos<=count)
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("enter the data\n");
			scanf("%d",&temp->data);
			ptr=last->next;
			for(i=1;i<=pos-1;i++)
			{
				ptr=ptr->next;
			}
			temp->next=ptr->next;
			ptr->next=temp;
		}
		else if(pos==count+1)
			insertend();
		else
			printf("invalid position entered\n");
	}
	
}

void deletebeg()
{
	ptr=last->next;
	last->next=ptr->next;
	free(ptr);
}

void deleteend()
{
	while(ptr->next!=last)
	{
		ptr=ptr->next;
	}
	ptr->next=last->next;
	last=ptr;
}

void deleteany()
{
	int count=0,pos,i;
	ptr=last->next;
	while(ptr!=last)
	{
		count++;
		ptr=ptr->next;
	}
	printf("enter the pos\n");
	scanf("%d",&pos);
	if(pos==1)
	{
	deletebeg();
	}
	else if(pos>1 && pos<=count)
	{
		ptr=last->next;
		for(i=1;i<=pos-1;i++)
		{	temp=ptr;
			ptr=ptr->next;
		}
		
		temp->next=ptr->next;
		free(ptr);
	}
	else if(pos=count+1)
	{
		deleteend();
	}
	else
	{
	printf("wrong choice");
	}
}

void display()
{	printf("\n");
	ptr=last->next;
	while(ptr!=last)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("%d \n",ptr->data);
}
void main()
{
int ch;
while(ch!=8)
{
	printf("1. insert in beg\n 2.display\n 3.insert in the end\n 4. insert anywhere\n 5.delete from the beg\n 6. delete from the end\n 7. delete from anywhere\n 8.exit\n");
	printf("enter the choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insertbeg();
		break;
		case 2: display();
		break;
		case 3: insertend();
		break;
		case 4: insertany();
		break;
		case 5: deletebeg();
		break;
		case 6: deleteend();
		break;
		case 7: deleteany();
		break;
		case 8: exit(0);
	}
}
}	
		

