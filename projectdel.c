#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* DelBegin();
struct node* DelEnd();
struct node* Delmiddle(int pos);
struct node* DelAll();
struct node* display();
int main()
{
	int choice,num,n,pos;
	while(1)
	{
		printf("WELCOME TO THE LINKED-LIST\n");
		printf("ENTER 1 FOR CREATING A NODE\n");
		printf("ENTER 2 FOR DELETING A NODE AT THE BEGINING\n");
		printf("ENTER 3 FOR DELETING A NODE AT THE ENDING\n");
		printf("ENTER 4 FOR DELETING A NODE AT THE MIDDLE\n");
		printf("ENTER 5 FOR DELETING ALL THE ELEEMENTS OF THE LINKED-LIST\n");
		printf("ENTER 6 FOR DISPLAY THE NODE OF THE LINKED-LIST\n");
		printf("Enter 7 for exit\n");
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
				DelBegin();
				break;
			case 3:
				DelEnd(num);
				break;
			case 4:
				printf("Enter the postion you want to delete the node:");
				scanf("%d",&pos);
				Delmiddle(pos);
				break;	
			case 5:
				DelAll();
				break;
			case 6:
				printf("The node present in the linked-list:\n");
				display();
				break;
			case 7:
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
struct node* DelBegin()
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
		printf("List is already empty\n");
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
struct node* Delmiddle(int pos)
{
	int i;
	struct node *todel,*prev;
	if(stnode==NULL)
	{
		printf("list is empty.");
	}
	else
	{
		todel=stnode;
		prev=stnode;
		for(i=2;i<=pos;i++)
		{
			prev=todel;
			todel=todel->link;
			if(todel==NULL)
			{
				break;
			}
		}
		if(todel!=NULL)
		{
			if(todel==stnode)
			{
				stnode=stnode->link;
			}
			prev->link=todel->link;
			todel->link=NULL;
			free(todel);
			printf("successfully deleted node from the givem=n specified node\n");
		}
		else
		{
			printf("invalid positon unable to delete");
		}
	}
}
struct node* DelEnd()
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
struct node* DelAll()
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
