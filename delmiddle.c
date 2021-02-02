#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* delmiddle(int pos);
struct node* display();
int main()
{
	int n,pos;
	printf("Enter the number of node you want to in the linkedd-list:");
	scanf("%d",&n);
	createNode(n);
	printf("The node in the linked-list:\n");
	display();
	printf("Enter the postion where you want to remove the node:");
	scanf("%d",&pos);
	delmiddle(pos);
	printf("The node after removing the node at the given position:\n");
	display();
	return 0;
}
struct node* createNode(int n)
{
	int num,i;
	struct node *fnode,*ptr;
	stnode=malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("Memory can not be allocated");
	}
	else
	{
		printf("Enter the value of node 1:");
		scanf("%d",&num);
		stnode->data=num;
		stnode->link=NULL;
		ptr=stnode;
		for(i=2;i<=n;i++)
		{
			fnode=malloc(sizeof(struct node));
			if(fnode==NULL)
			{
				printf("Memory can not be allocated");
			}
			else
			{
				printf("Enter the value of node %d:",i);
				scanf("%d",&num);
				fnode->data=num;
				fnode->link=NULL;
				ptr->link=fnode;
				ptr=ptr->link;
			}
		}
		printf("linked-list created successfully\n");
	}
}
struct node* delmiddle(int pos)
{
	int i;
	struct node *todel,*prev;
	if(stnode==NULL)
	{
		printf("list is empty.");
	}
	else
	{
		todel=stnode;
		prev=stnode;
		for(i=2;i<=pos;i++)
		{
			prev=todel;
			todel=todel->link;
			if(todel==NULL)
			{
				break;
			}
		}
		if(todel!=NULL)
		{
			if(todel==stnode)
			{
				stnode=stnode->link;
			}
			prev->link=todel->link;
			todel->link=NULL;
			free(todel);
			printf("successfully deleted node from the givem=n specified node\n");
		}
		else
		{
			printf("invalid positon unable to delete");
		}
	}
	
}
struct node* display()
{
	struct node *ptr;
	ptr=stnode;
	if(stnode==NULL)
	{
		printf("linked list is empty.\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("Data =%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}
