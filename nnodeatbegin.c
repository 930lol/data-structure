#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* Atbegin(int data);
struct node* display();
int main()
{
	int n,num;
	printf("enter the total number of nodes:");
	scanf("%d",&n);
	createNode(n);
	printf("\n Data in the list \n");
	display();
	printf("\n Enter data to insert at the begining of the list:");
	scanf("%d",&num);
	Atbegin(num);
	printf("Data in the list \n");
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
		printf("memory can not be allocated");
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
				printf("memory can not be allocated:");
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
struct node* Atbegin(int num)
{
	struct node *ptr;
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("memory can not be allocated");
	}
	else
	{
		ptr->data=num;
		ptr->link=stnode;
		stnode=ptr;
		printf("Data inserted successfully");
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
