#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* insertBegin(int num);
struct node* insertEnd(int num);
struct node* middle(int pos,int num);
struct node* display();
int main()
{
	int choice,n,num,pos;
	while(1)
	{
		printf("WELCOME TO THE LINKED-LIST\n");
		printf("ENTER 1 FOR CREATING A NODE\n");
		printf("ENTER 2 FOR INSERTING A NODE AT THE BEGINING\n");
		printf("ENTER 3 FOR INSERTING A NODE AT THE ENDING\n");
		printf("ENTER 4 FOR INSERTING A NPDE AT THE MIDDLE\n");
		printf("ENTER 5 FOR DISPLAY THE NODE OF THE LINKED-LIST\n");
		printf("Enter 6 for exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number of node you want:");
				scanf("%d",&n);
				createNode(n);
				break;
			case 2:
				printf("Enter data of node you want to insert at the begining:");
				scanf("%d",&num);
				insertBegin(num);
				break;
			case 3:
				printf("Enter data of node you want to insert at the ending:");
				scanf("%d",&num);
				insertEnd(num);
				break;
			case 4:
				printf("Enter data of node you want to insert at the middle:");
				printf("Enter the position of node:");
				scanf("%d",&pos);
				printf("Enter data of node you want to insert at the middle:");
				scanf("%d",&n);
				middle(pos,n);
				break;	
			case 5:
				display();
				break;
			case 6:
				printf("Thank-you");
				exit(1);
			default:
				printf("Invalid choice");
		}
	}	
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
struct node* insertBegin(int num)
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
		printf("Data inserted successfully\n");
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
struct node* insertEnd(int n)
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
		printf("List is empty\n");
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


