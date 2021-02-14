#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define CAPACITY 1000
struct node
{
	int data;
	struct node *link;
} *stnode;
int size=0;
int main()
{
	int choice,data;
	while(1)
	{
		printf("------------------------------------------\n");
		printf("     STACK IMPLEMENTATION OF PROGRAM      \n");
		printf("------------------------------------------\n");
		printf("     1.PUSH\n");
		printf("     2.pop\n");
		printf("     3.size\n");
		printf("     4.display\n");
		printf("     5.Exit\n");
		printf("------------------------------------------\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the data to push into the stack:");
				scanf("%d",&data);
				push(data);
				break;
			case 2:
				data=pop();
				if(data!=INT_MIN)
				{
					printf("DATA = %d\n",data);
				}
				break;
			case 3:
				printf("Stack size :%d\n",size);
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exiting from the stack\n");
				exit(0);
				break;
			default:
				printf("INVALID CHOICE,PLEASE TRY AGAIN.\n");
				
		}
		printf("\n\n");
	}
}
void push(int element)
{
	if(size>=CAPACITY)
	{
		printf("Stack is overflow, can't add more elements to stack.\n");
		return;
	}
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=element;
	newNode->link=stnode;
	stnode=newNode;
	size++;
	printf("Data pushed to stack.\n");
}
int pop()
{
	int data=0;
	struct node * topnode;
	if(size <=0 || !stnode)
	{
		printf("stack is empty\n");
		return INT_MIN;
	}
	topnode=stnode;
	data=stnode->data;
	stnode=stnode->link;
	free(topnode);
	size--;
	return data;
}
void display()
{
	struct node *ptr;
	if(stnode==NULL)
	{
		printf("stack is empty\n");
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
