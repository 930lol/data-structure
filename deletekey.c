#include<Stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* delkey(int num);
struct node* display();
int main()
{
	int n,key;
	printf("Enter the number of node you want:\n");
	scanf("%d",&n);
	createNode(n);
	printf("The number of elements in the linked list:\n");
	display();
	printf("Enter the value you want to detete from the linked list:\n");
	scanf("%d",&key);
	delkey(key);
	printf("Lisnked after the deletion:\n");
	display();
	return 0;
}
struct node* createNode(int n)
{
	struct node *fnode,*ptr;
	int num,i;
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
		printf("Data entered in the sigly likned list successfully\n");
	}
}
struct node* display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("Linked-list is empty\n");
	}
	else
	{
		ptr=stnode;
		while(ptr!=NULL)
		{
			printf("Data : %d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}
struct node* delkey(int num)
{
	struct node *prev,*cur;
	while(stnode!=NULL &&stnode->data==num)
	{
		prev=stnode;
		stnode=stnode->link;
		free(prev);
		return;
	}
	prev=NULL;
	cur=stnode;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			if(prev!=NULL)
			{
				prev->link=cur->link;
			}
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
}
