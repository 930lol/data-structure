#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode ;
struct node* createNode(int n);
struct node* display();
struct node* middle(int num,int pos);
int main()
{
	int n,num,pos;
	printf("Enter the number of node you want:");
	scanf("%d",&n);
	createNode(n);
	display();
	printf("Enter the position where you want to insert the node:");
	scanf("%d",&pos);
	printf("Enter the data you want to store at the specify position:");
	scanf("%d",&num);
	middle(pos,num);
	display();
	return 0;
}
struct node* createNode(int n)
{
	int i,num;
	struct node *fnode,*ptr;
	stnode=malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("Memory can not be allocated");
	}
	else
	{
		printf("Enter the data of node 1:");
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
				break;
			}
			else 
			{
				printf("Enter the data of node %d:",i);
				scanf("%d",&num);
				fnode->data=num;
				fnode->link=NULL;
				ptr->link=fnode;
				ptr=ptr->link;
			}
		}
		printf("Singly linked list created succesfully\n");
	}
}
struct node* middle(int pos,int num)
{
	int i;
	struct node *newpos,*temp;
	newpos=malloc(sizeof(struct node));
	if(newpos==NULL)
	{
		printf("Memory can not be allocate");
	}
	else
	{
		newpos->data=num;
		newpos->link=NULL;
		temp=stnode;
		for(i=2;i<=pos-1;i++)
		{
			temp=temp->link;
			if(temp==NULL)
			{
				break;
			}
		}
		if(temp!=NULL)
		{
			newpos->link=temp->link;
			temp->link=newpos;
			printf("Date inserted successfully\n");
		}
		else
		{
			printf("Unable to insert data at the given position\n");
		}
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("List is empty");
	}
	else 
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			printf("Data = %d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}

