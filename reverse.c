#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* display();
struct node* reverse();
int main()
{
	int n;
	printf("Enter the number of node you want in linked list:");
	scanf("%d",&n);
	createNode(n);
	printf("The data in linked list are\n");
	display();
	printf("Linked list in reverse order\n");
	reverse();
	printf("The data in linked list after reverseing the linked list\n");
	display();
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
		printf("Enter the value for node 1:");
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
				printf("Enter the value for node %d:",i);
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
		printf("Linked list is empty\n");
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
struct node* reverse()
{
	struct node *pre,*cur;
	if(stnode!=NULL)
	{
		pre=stnode;
		cur=stnode->link;
		stnode=stnode->link;
		pre->link=NULL;
		while(stnode!=NULL)
		{
			stnode=stnode->link;
			cur->link=pre;
			pre=cur;
			cur=stnode;
		}
		stnode=pre;
		printf("SUCCESSFULLY REVERESED LINKED LIST\n");
	}
}
