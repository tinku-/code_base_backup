#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link;
};
void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d->",head->data);
		head = head->link;
	}
	printf("NULL\n");
}
struct node* insertatbeg(struct node* head)
{
	int x;scanf("%d",&x);
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->link = head;
	temp->data = x;
	head = temp;
	return head;
}
struct node* insertatend(struct node* head)
{
	if(head == NULL)
	{
		head = insertatbeg(head);
		return head;
	}
	int x;scanf("%d",&x);
	struct node* temp2 = head;
	struct node* temp = (node*)malloc(sizeof(struct node));
	while(temp2->link != NULL)
		temp2 = temp2->link;
	temp2->link = temp;
	temp->link = NULL;
	temp->data = x;
	return head;
}
void reversesub(struct node* head)
{
	int m,l;
	printf("L :\n");
	scanf("%d",&l);
	printf("M :\n");
	scanf("%d",&m);
	if(head == NULL)
	{
		print(head);
		return;
	}
}
int main()
{
	int n;
	struct node* head = NULL;
	while(1>0)
	{

		printf("press:\n1:to print list\n2:to insert at beg\n3:to insert at end\n4:for sub swap\n5:to exit\n");
		scanf("%d",&n);
		if(n == 2)
			head = insertatbeg(head);
		if(n == 1)
			print(head);
		if(n == 3)
			head = insertatend(head);
		if(n == 4)
			{reversesub(head);print(head);}
		if(n == 5)
			break;
	}
}