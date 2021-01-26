#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}* stnode;
struct node* createNode(int n);
struct node* Atend(int num);
struct node* display();
int main()
{
	int n,num;
	printf("Enter the number of node you want in the linked list:");
	scanf("%d",&n);
	createNode(n);
	printf("Data in the list \n");
	display();
	printf("\n Enter data to insert at the ending of the list:");
	scanf("%d",&num);
	Atend(num);
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
		printf("Enter the value of the node 1:");
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
				printf("Enter the value of node %d:",i);
				scanf("%d",&num);
				fnode->data=num;
				fnode->link=NULL;
				ptr->link=fnode;
				ptr=ptr->link;
			}
		}
		printf("Successfully created singlly linked list:");
	}	
}
struct node* Atend(int n)
{
	struct node *ptr,*ptr1;
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("memory can not be allocated");
	}
	else
	{
		ptr->data=n;
		ptr->link=NULL;
		ptr1=stnode;
		while(ptr1!=NULL && ptr1->link!=NULL)
		{
			ptr1=ptr1->link;
		}
		ptr1->link=ptr;
		printf("Data inserted successfully\n");
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
