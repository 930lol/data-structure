#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *link;
}*stnode;

struct node* createNode(int n);
struct node* display();  
int main()
{
	int n;
	printf("Enter the number of node you want to enter:");
	scanf("%d",&n);
	createNode(n);
	display();
	return 0;
}
struct node* createNode(int n)
{
	struct node *fnode,*tmp;
	int num,i;
	stnode=malloc(sizeof(struct node));
	if(stnode==NULL)
	{
		printf("memory can not be allocated");
	}
	else 
	{
		printf("input data for node 1:");
		scanf("%d",&num);
		stnode->data=num;
		stnode->link=NULL;
		tmp=stnode;
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
				printf("input data for node %d :",i);
				scanf(" %d",&num);
				fnode->data=num;
				fnode->link=NULL;
				tmp->link=fnode;
				tmp=tmp->link;		
			}
		}
	}
}
struct node* display()
{
	struct node *tmp;
	if(stnode==NULL)
	{
		printf("list is empty");
	}
	else
	{
		tmp=stnode;
		while(tmp!=NULL)
		{
			printf("Data= %d\n",tmp->data);
			tmp=tmp->link;
		}
	}
}
