#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* display();
struct node* search(int key);
int main()
{
	int n,key;
	printf("ENTER THE NUMBER OF NODE YOU WANT TO LINKED LIST:");
	scanf("%d",&n);
	createNode(n);
	printf("THE DATA IN THE LINKED-LIST:\n");
	display();
	printf("ENTER THE DATA YOY WANT TO SEARCH IN THE LINKED-LIST:");
	scanf("%d",&key);
	search(key);
	return 0;
}
struct node* createNode(int n)
{
	int num,i;
	struct node *fnode,*ptr;
	stnode=malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("Memory can not be allocated\n");
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
				printf("Memory can not be allocated\n");
				break;
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
		printf("DATA ENTERED SUCCESSFULLY\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("linked-List is empty\n");
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
struct node* search(int key)
{
	int i=0;
	struct node * ptr;
	if(stnode==NULL)
	{
		printf("Linked-list is empty\n");
	}
	else
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			if(key==ptr->data)
			{
				i++;
				printf("found at position=%d",i);
				break;
			}
			ptr=ptr->link;
			i++;
		}
	}
	if(ptr->link==NULL)
	{
		printf("value not found");
	}
}
