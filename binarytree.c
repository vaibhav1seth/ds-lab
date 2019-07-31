#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node*  root=NULL;
int is_lchild(struct node *tree)
{
	int ch;
	printf("\ndo you want to enter the left child of %d? 1.yes 2.no\n",tree->data);
	scanf("%d",&ch);
	if(ch==1)
		return 1;
	else
		return 0;
}

int is_rchild(struct node *tree)
{
	int ch;
	printf("\ndo you want to enter the right child of %d? 1.yes 2.no\n",tree->data);
	scanf("%d",&ch);
	if(ch==1)
		return 1;
	else
		return 0;
}	
void create(struct node *tree)
{
	struct node *temp;
	if(is_lchild(tree)==1)
	{
		tree->lchild=(struct node*)malloc(sizeof(struct node*));
		temp=tree->lchild;
		printf("enter the data\n");
		scanf("%d",&temp->data);
		create(temp);
	}
	else
	{
		tree->lchild=NULL;
	}

	if(is_rchild(tree)==1)
	{
		tree->rchild=(struct node*)malloc(sizeof(struct node*));
		temp=tree->rchild;
		printf("enter the data\n");
		scanf("%d",&temp->data);
		create(temp);
	}
	else
	{
		tree->rchild=NULL;
	}
}

void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->lchild);
		printf("%d\t",tree->data);
		inorder(tree->rchild);
	}
}

void main()
{
	printf("\ncreate the root node\n");
	root=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&root->data);
	create(root);
	printf("inorder traversal is \n");
	inorder(root);
}

