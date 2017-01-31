#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* insertatbeg(struct node* head)
{
	int x;
	scanf("%d",&x);
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->next = head;
	temp->data = x;
	head = temp;
	return head;
}
void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int palin(struct node* head)
{
	struct node* temp = head;
	struct node* stack = NULL;
	while(temp != NULL)
	{
		struct node* temp2 = (node*)malloc(sizeof(struct node));
		temp2->next = stack;
		temp2->data = temp->data;
		stack = temp2;
		temp = temp->next;
	}
	print(head);
	print(stack);
	while(head != NULL)
	{
		if(head->data != stack->data)
			return 0;
		head = head->next;
		stack = stack->next;
	}
	return 1;
}
int main()
{
	struct node* head = NULL;
	int n;
	while(1>0)
	{
		printf("press:\n1:to print list\n2:to insert at beg\n3:to check(palindrom)\n4:to exit\n");
		scanf("%d",&n);
		if(n == 1)
			print(head);
		if(n == 2)
			head = insertatbeg(head);
		if(n == 3)
		{
			if(palin(head) == 1)
				printf("palindrom\n");
			else
				printf("not palindrom\n");
			return 0;
		}
		if(n == 4)
			break;
	}
	return 0;
}
