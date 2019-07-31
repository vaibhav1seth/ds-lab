#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
struct node *ptr=NULL,*start=NULL,*temp=NULL,*prev=NULL;
void insertbeg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		start->llink=temp;
		temp->rlink=start;
		start=temp;
	}
}
void insertend()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{	ptr=start;
		while(ptr->rlink!=NULL)
		{
			ptr=ptr->rlink;
		}
		ptr->rlink=temp;
		temp->llink=ptr;
	}
}

void insertany()
{
	int count=0,i,pos;
	ptr=start;
	while(ptr->rlink!=NULL)
	{
		count++;
		ptr=ptr->rlink;
	}
	printf("enter the position\n");
	scanf("%d",&pos);
	if(pos==1)
		insertbeg();
	else if(pos==count+1)
		insertend();
	else if(pos>1 && pos<=count)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the data\n");
		scanf("%d",&temp->data);
		temp->llink=NULL;
		temp->rlink=NULL;
		ptr=start;
		for(i=1;i<=pos-1;i++)
		{	
			prev=ptr;
			ptr=ptr->rlink;
		}
		prev->rlink=temp;
		temp->llink=prev;
		temp->rlink=ptr;
		ptr->llink=temp;
	}
}
void delbeg()
{
	ptr=start;
	start=ptr->rlink;
	free(ptr);
}
void delend()
{
	ptr=start;
	while(ptr->rlink!=NULL)
	{
		temp=ptr;
		ptr=ptr->rlink;
	}
	temp->rlink=NULL;
	free(ptr);
}

void delany()
{
	int count=0,pos,i;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->rlink;
	}
	printf("enter the pos\n");
	scanf("%d",&pos);
	if(pos==1)
	{
	delbeg();
	}
	else if(pos>1 && pos<=count)
	{
		ptr=start;
		for(i=1;i<=pos-1;i++)
		{	temp=ptr;
			ptr=ptr->rlink;
		}
		
		temp->rlink=ptr->rlink;
		ptr->rlink->llink=temp;
		free(ptr);
	}
	else if(pos=count+1)
	{
		delend();
	}
	else
	{
	printf("wrong choice");
	}
}
void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->rlink;
	}
	printf("\n");
}


void main()
{
int ch;
while(1)
{
	printf("1. insert in beg\n 2.display\n 3.insert in the end\n 4. insert anywhere\n 5.delete from the beg\n 6. delete from the end\n 7. delete from anywhere\n");
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
		case 5: delbeg();
		break;
		case 6: delend();
		break;
		case 7: delany();
		break;
		default: exit(0); 
		}
	}
}
		

	
