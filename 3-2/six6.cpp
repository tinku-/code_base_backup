#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node* link;
};
struct node* insertatbeg(struct node* head)
{
	int x;
	printf("enter no: ");
	scanf("%d",&x);
	struct node* temp = (node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		temp->data = x;
		temp->link = NULL;
		head = temp;
	}
	else
	{
		temp->data = x;
		temp->link = head;
		head = temp;
	}
	return head;
}
struct node* insertatend(struct node* head)
{
	int x;
	printf("enter no: ");
	scanf("%d",&x);
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	if(head == NULL)
	{
		temp->data = x;
		temp->link = NULL;
		head = temp;
	}
	else
	{
		struct node* temp2 = head;
		while(temp2->link != NULL)
			temp2 = temp2->link;
		temp->data = x;
		temp->link = NULL;
		temp2->link = temp;

	}
	return head;
}
struct node* insert(struct node* head)
{
	struct node* re = head;
	int x,y;
	printf("enter no: ");
	scanf("%d",&x);
	printf("which should be before: ");
	scanf("%d",&y);
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->data = x;
	if(head->data == y)
	{
		temp->link = head;
		head = temp;
		return head;
	}
	while(head->link->data != y)
		head = head->link;
	temp->link = head->link;
	head->link = temp;
	return re;
}
void print(struct node* head)
{
	struct node* temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->link;
	}

}
int main()
{
	int n;
	struct node* head;
	head = NULL;
	while(1>0)
	{
		printf("\npress \n1:to print the list \n2:to insert at beg \n3:to insert at end \n4:to insert before \n5:exit\n");
		scanf("%d",&n);
		if(n == 1)
		{
			print(head);
		}
		if(n == 2)
		{
			head = insertatbeg(head);
		}
		if(n == 3)
		{
			head = insertatend(head);
		}
		if(n == 4)
		{
			head = insert(head);
		}
		if(n == 5)
		{
			break;
		}

	}
	return 0;
	

}