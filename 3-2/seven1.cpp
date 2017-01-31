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
//this algoridam uses similar partition function as quick sort;
void partition(struct node* head)
{
	int inttemp;
	struct node* temp = head;
	while(head != NULL)
	{
		if(head->data%2 == 0)
		{
			inttemp = temp->data;
			temp->data = head->data;
			head->data = inttemp;
			temp = temp->link;
		}
		head = head->link;
	}
}
int main()
{
	int n;
	struct node* head = NULL;
	while(1>0)
	{
		printf("press:\n1:to print list\n2:to insert at beg\n3:to for partition\n4:to exit\n");
		scanf("%d",&n);
		if(n == 2)
			head = insertatbeg(head);
		if(n == 1)
			print(head);
		if(n == 3)
			{partition(head);print(head);}
		if(n == 4)
			break;
	}
}

/*
quesion 1:
Write a program to modify a singly linked list such that all even numbers appear
before all the odd numbers in the modified linked list
For example: if the linked list is 1->2->3->4->5->6->NULL, then the resultant list
should be 2->4->6->1->3->5->NULL
*/