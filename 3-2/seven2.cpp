#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* insertatbeg(struct node* head)
{	
	int x;scanf("%d",&x);
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->link = head;
	temp->data = x;
	head = temp;
	return head;
}
void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d->",head->data);
		head = head->link;
	}
	printf("NULL\n");
}
void swapairs(struct node* head)
{
	int temp = 0;
	while(head->link != NULL)
	{
		temp = head->data;
		head->data = head->link->data;
		head->link->data = temp;
		head = head->link->link;
	}
}
int main()
{
	int n;
	struct node* head = NULL;
	while(1>0)
	{

		printf("press:\n1:to print list\n2:to insert at beg\n3:to for swapping pairs\n4:to exit\n");
		scanf("%d",&n);
		if(n == 2)
			head = insertatbeg(head);
		if(n == 1)
			print(head);
		if(n == 3)
			{swapairs(head);print(head);}
		if(n == 4)
			break;
	}
}