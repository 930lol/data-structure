#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* deleteAtfirst();
struct node* display();
int main()
{
	int n;
	printf("Enter the number of node you want to enter in the linked list:");
	scanf("%d",&n);
	createNode(n);
	printf("The value of the node in the linked list:\n");
	display();
	printf("Deletion operation at the fist node of the linked list");
	deleteAtfirst();
	printf("Node after deletion at the first postion:\n");
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
				printf("memory can not be allocated");
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
struct node* deleteAtfirst()
{
	struct node *fdel;
	if(stnode==NULL)
	{
		printf("list is already empty");
	}
	else 
	{
		fdel=stnode;
		stnode=stnode->link;
		printf("\n Data delete =%d\n", fdel->data);
		free(fdel);
		printf("Successfully deleted first node from the linked list\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("List is already empty");
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
