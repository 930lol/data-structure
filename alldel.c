#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* display();
struct node* Alldel();
int main()
{
	int n;
	printf("Enter the number of node you want to linked-list:");
	scanf("%d",&n);
	createNode(n);
	printf("Linked-List node contains are:\n");
	display();
	printf("ALL the elements of the linked-list is deleted\n");
	Alldel();
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
		printf("Linked-List created suucessfully\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("Linked-List is empty.");
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
struct node* Alldel()
{
	struct node *ptr;
	while(stnode!=NULL)
	{
		ptr=stnode;
		stnode=stnode->link;
		free(ptr);
	}
	printf("Successfully deleted all the node of the linked-List\n");
}

