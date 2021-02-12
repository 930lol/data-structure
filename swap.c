#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
}*stnode;
struct node* createNode(int n);
struct node* display();
int swap(struct node *list,int pos1,int pos2);
int count(struct node *list);
int main()
{
	int n,pos1,pos2;
	printf("ENTER THE NUMBER OF NODE YOU WANT TO LINKED LIST:");
	scanf("%d",&n);
	createNode(n);
	printf("THE DATA IN THE LINKED-LIST BEFORE THE SWAPPING:\n");
	display();
	printf("ENTER THE first node postion ti swap:");
	scanf("%d",&pos1);
	printf("Enter the second node position to swap:");
	scanf("%d",&pos2);
	if(swap(stnode,pos1,pos2)==1)
	{
		printf("DATA  SWAPPED SUCCESSFULLY\n");
		printf("DATA IN LIST AFTER SWAPPING %d node with %d:\n",pos1,pos2);
		display();
	}
	else
	{
		printf("INVALID POSITION ,PLEASE ENTER THE POSITION GREATER THAN 0 AND LESS THAN NODE SIN THE LINKED LIST\n");
	}
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
 int count(struct node *list)
 {
 	int n=0;
 	while(list!=NULL)
 	{
 		n++;
 		list=list->link;
 	}
 	return n;
 }
 int swap(struct node *list,int pos1,int pos2)
 {
 	struct node *node1,*node2,*prev1,*prev2,*temp;
 	int i;
 	const int maxpos=(pos1>pos2)? pos1:pos2;
 	const int totalNodes=count(list);
 	if((pos1<=0||pos1>totalNodes)||(pos2<=0||pos2>totalNodes))
 	{
 		return -1;
 	}
 	if(pos1==pos2)
 	{
 		return 1;
 	}
 	i=1;
 	temp=list;
 	prev1=NULL;
 	prev2=NULL;
 	while(temp!=NULL && (i<=maxpos))
 	{
 		if(i==pos1-1)
 		{
 			prev1=temp;
 		}
 		if(i==pos1)
 		{
 			node1=temp;
 		}
 		if(i==pos2-1)
 		{
 			prev2=temp;
 		}
 		if(i==pos2)
 		{
 			node2=temp;
 		}
 		temp=temp->link;
 		i++;
 	}
 	if(node1 !=NULL && node2 !=NULL)
 	{
 		if(prev1!=NULL)
 		{
 			prev1->link=node2;
 		}
 		if(prev2!=NULL)
 		{
 			prev2->link=node1;
 		}
 		temp=node1->link;
 		node1->link=node2->link;
 		node2->link=temp;
 	}
 	if(prev1==NULL)
 	{
 		stnode=node2;
 	}
 	else if(prev2==NULL)
 	{
 		stnode=node1;
 	}
 	return 1;
 }
