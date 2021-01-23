#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
int main()
{
	struct node * head= malloc(sizeof(struct node));
	head->data=98;
	head->link=NULL;
	struct node *ptr=head;
	ptr=add_at_end(head,98);
	ptr=add_at_end(head,78);
	ptr=head;
	int data=67,position=3;
	add_at_pos(head,data,position);
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	return 0;
}
struct node *add_at_end(struct node *ptr,int data)
{
	struct node* temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	ptr->link=temp;
	return temp;
}
void add_at_pos(struct node* head,int data,int pos)
{
	struct node *ptr=head;
	struct node *ptr2=malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->link=NULL;
	pos--;
	while(pos!=1)
	{
		ptr=ptr->link;
		pos--;
	}
	ptr2->link=ptr->link;
	ptr->link=ptr2;
}
