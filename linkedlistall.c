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
struct node* insertMiddle(int pos,int num);
struct node* display();
struct node* DelBegin();
struct node* DelEnd();
struct node* DelMiddle(int pos);
struct node* DelAll();
int main()
{
	int choice,pos,n,num;
	while(1)
	{
		printf("WELCOME TO THE LINKED-LIST\n");
		printf("ENTER 1 FOR CREATING A NODE\n");
		printf("ENTER 2 FOR INSERTING A NODE AT THE BEGINING\n");
		printf("ENTER 3 FOR INSERTING A NODE AT THE ENDING\n");
		printf("ENTER 4 FOR INSERTING A NODE AT THE MIDDLE\n");
		printf("ENTER 5 FOR DISPLAY THE NODE OF THE LINKED-LIST\n");
		printf("ENTER 6 FOR DELETING A NODE AT THE BEGINING\n");
		printf("ENTER 7 FOR DELETING A NODE AT THE ENDING\n");
		printf("ENTER 8 FOR DELETING A NODE AT THE MIDDLE\n");
		printf("ENTER 9 FOR DELETING ALL THE ELEEMENTS OF THE LINKED-LIST\n");
		printf("Enter 10 for exit\n");
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
				insertMiddle(pos,n);
				break;
			case 5:
				printf("The node present in the linked-list:\n");
				display();
				break;	
			case 6:
				DelBegin();
				break;
			case 7:
				DelEnd(num);
				break;
			case 8:
				printf("Enter the postion you want to delete the node:");
				scanf("%d",&pos);
				DelMiddle(pos);
				break;	
			case 9:
				DelAll();
				break;
			case 10:
				printf("Thank-you");
				exit(1);
			default:
				printf("Invalid choice");	
		}
	}
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
		printf("Enter the value of Node 1:");
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
				printf("Enter the value of Node %d:",i);
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
struct node* insertBegin(int num)
{
	struct node *ptr;
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Memory can not be allocated\n");
	}
	else
	{
		stnode->data=num;
		stnode->link=NULL;
		stnode=ptr;
		printf("Data Entered Successfully\n");
	}
}
struct node* insertEnd(int num)
{
	struct node *ptr,*ptr1;
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Memory can not be allocated\n");
	}
	else 
	{
		ptr->data=num;
		ptr->link=NULL;
		ptr1=stnode;
		while(ptr1!=NULL && ptr1->link!=NULL)
		{
			ptr1=ptr1->link;
		}
		ptr1->link=ptr;
		printf("Data enter Successfully\n");
	}
}
struct node* insertMiddle(int pos,int n)
{
	struct node *newpos,*temp;
	int i;
	newpos=malloc(sizeof(struct node));
	if(newpos==NULL)
	{
		printf("Memory can not be allocated\n");
	}
	else
	{
		newpos->data=n;
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
			printf("Data Entered successfully\n");
		}
		else
		{
			printf("unable to insert the at the given postion\n");
		}
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("Linked-List is Empty.\n");
	}
	else
	{
		ptr=stnode;
		while(ptr!= NULL)
		{
			printf("Data : %d\n",ptr->data);
			ptr=ptr->link;
		}
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
struct node* DelMiddle(int pos)
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
