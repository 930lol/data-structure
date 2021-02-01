#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* delAtend();
struct node* display();
int main()
{
	int n;
	printf("Enter the number of node you want to enter in linked-list:");
	scanf("%d",&n);
	createNode(n);
	printf("The linked-list after creation of the singly linkedd-list:\n");
	display();
	delAtend();
	printf("The linked-list after removing the elements at the end of the linked-list:\n");
	display();
	return 0;
}
struct node* createNode(int n)
{
	int i,num;
	struct node *fnode,*ptr;
	stnode=malloc(sizeof(struct node));
	if(stnode== NULL)
	{
		printf("memory can not be allocated");
	}
	else
	{
		printf("Enter value of the data in node 1:");
		scanf("%d",&num);
		stnode->data=num;
		stnode->link=NULL;
		ptr=stnode;
		for(i=2;i<=n;i++)
		{
			fnode=malloc(sizeof(struct node));
			if(fnode==NULL)
			{
				printf("memoy can not be allocated");
			}
			else 
			{
				printf("Enter value of the data in node %d:",i);
				scanf("%d",&num);
				fnode->data=num;
				fnode->link=NULL;
				ptr->link=fnode;
				ptr=ptr->link;
				
			}
		}
		printf("Singly linked list created successfully\n");
	}
}
struct node* delAtend()
{
	struct node *todel,*sec;
	if(stnode==NULL)
	{
		printf("List is empty");
	}
	else
	{
		todel=stnode;
		sec=stnode;
		while(todel->link!=NULL)
		{
			sec=todel;
			todel=todel->link;
		}
		if(todel==stnode)
		{
			stnode==NULL;
		}
		else 
		{
			sec->link=NULL;
		}
		free(todel);
		printf("Successfully deleted last node of the list\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("linked-list is empty");
	}
	else
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			printf("Data = %d\n", ptr->data);
			ptr=ptr->link;
		}
	}
	
}
