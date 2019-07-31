#include<stdio.h>
#include<stdlib.h>
struct node
{ 
	int data;
	struct node *llink;
	struct node *rlink;
};
struct node *ptr,*start=NULL,*temp;
void create()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n enter the data \n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		if(temp->data < start->data)
		{
			temp->rlink=start;
			start->llink=temp;
			start=temp;
		}
		else
		{
			while(ptr->rlink!=NULL && ptr->data < temp->data)
				ptr=ptr->rlink;
			if(ptr->rlink==NULL && ptr->data<temp->data)
			{
				ptr->rlink=temp;
				temp->llink=ptr;
			}
			else
			{
				temp->llink=ptr->llink;
				temp->rlink=ptr;
				ptr->llink->rlink=temp;
				ptr->llink=temp;
			}
		}
	}
}
void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->rlink;
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n enter the choice 1.insert 2. display\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();break;
			case 2: display();break;
			case 3: exit(0);
		}
	}
}
