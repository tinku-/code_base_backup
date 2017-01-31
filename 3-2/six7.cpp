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
void print(struct node* head)
{
	while(head != NULL)
	{
		printf("%d ",head->data);
		head = head->link;
	}
}
struct node* deletebeg(struct node* head)
{
	if(head == NULL)
	{
		printf("UNDERFLOW\n");
		return head;
	}
	struct node* temp = head;
	head = head->link;
	free(temp);
	return head;
}
struct node* deleteatend(struct node* head)
{
	if(head == NULL)
	{
		printf("UNDERFLOW\n");
		return head;
	}
	if(head->link == NULL)
	{
		free(head);
		return NULL;
	}
	struct node* temp = head;
	while(temp->link->link != NULL)
		temp = temp->link;
	free(temp->link); 
	temp->link = NULL;
	return head;
}
int main()
{
	struct node* head = NULL;
	while(1>0)
	{
		int n;
		printf("\npress \n1:to print the list \n2:to insert at beg \n3:to deleteatbeg \n4:to deleteatend \n5:exit\n");
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
			head = deletebeg(head);
		}
		if(n == 4)
		{
			head = deleteatend(head);
		}
		if(n == 5)
		{
			break;
		}
	}
	return 0;
}
