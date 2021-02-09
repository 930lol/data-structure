#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* count();
struct node* display();
int main()
{
	int n;
	printf("Enter the number of the node you want in the linked list:");
	scanf("%d",&n);
	createNode(n);
	printf("The Data present in the linked list:\n");
	display();
	printf("The total node linked-list:\n");
	count();
	return 0;
}
struct node* createNode(int n)
{
	struct node *fnode,*ptr;
	int i,num;
	stnode=malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("Memory can not be allocated\n");
	}
	else
	{
		printf("Enter the data for node 1:");
		scanf("%d",&num);
		stnode->data=num;
		stnode->link=NULL;
		ptr=stnode;
		for(i=2;i<=n;i++)
		{
			fnode=malloc(sizeof(struct node));
			if(fnode==NULL)
			{
				printf("Memory can not be allocated\n");
				break;
			}
			else
			{
				printf("Enter the data for node %d:",i);
				scanf("%d",&num);
				fnode->data=num;
				fnode->link=NULL;
				ptr->link=fnode;
				ptr=ptr->link;
			}
		}
		printf("DATA ENTERED SUCCESSFULLY\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("LINKED LIST IS EMPTY\n");
	}
	else
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			printf("DATA = %d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}
struct node* count()
{
	struct node *ptr;
	int c=0;
	if(stnode==NULL)
	{
		printf("THEIR IS NO ELEMENTS IN THE LINKED LIST\n");
	}
	else
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			c++;
			ptr=ptr->link;
		}
	}
	printf("THE TOTAL NUMBER NODE IN THE LINKED LIST %d",c);
}
