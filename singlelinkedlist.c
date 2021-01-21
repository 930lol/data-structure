#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
int main()
{
	struct node *head=malloc(sizeof(struct node));
	head->data=98;
	head->link=NULL;
	struct node *current=malloc(sizeof(struct node));
	current->data=38;
	current->link=NULL;
	head->link=current;
	current=malloc(sizeof(struct node));
	current->data=97;
	current->link=NULL;
	head->link->link=current;
	count_no_node(head);
	return 0;
}
int  count_no_node(struct node *head)
{
	int c=0;
	if(head==NULL)
	{
		printf("Linked list is empty");
	}
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		c++;
		ptr=ptr->link;
	}
	//return c;
	printf("%d",c);
}
