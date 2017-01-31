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
	temp->data = x;
	if(head == NULL)
	{
		temp->link = NULL;
		head = temp;
		
	}
	else
	{
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
struct node* mergesortedlist(struct node* left,struct node* right)
{	
	struct node* temp = (node*)malloc(sizeof(struct node));
	struct node* head = NULL;
	while(left != NULL && right !=NULL)
	{
		if(left->data < right->data)
		{
			if(head == NULL)
			{
				temp->data = left->data;
				temp->link = NULL;
				head = temp;
				left = left->link;
			}
			else
			{
				struct node* temp2 = (node*)malloc(sizeof(struct node));
				temp->link = temp2;
				temp2->data = left->data;
				temp2->link = NULL;
				left = left->link;
				temp = temp2;
			}
		}
		else
		{
			if(head == NULL)
			{
				temp->data = right->data;
				temp->link = NULL;
				head = temp;
				right = right->link;
			}
			else
			{
				struct node* temp2 = (node*)malloc(sizeof(struct node));
				temp->link = temp2;
				temp2->data = right->data;
				temp2->link = NULL;
				right = right->link;
				temp = temp2;
			}
		}
	}
	while(left != NULL)
	{
		if(head == NULL)
		{
			temp->data = left->data;
			temp->link = NULL;
			head = temp;
			left = left->link;
		}
		else
		{
			struct node* temp2 = (node*)malloc(sizeof(struct node));
			temp->link = temp2;
			temp2->data = left->data;
			temp2->link = NULL;
			left = left->link;
			temp = temp2;
		}
	}
	while(right != NULL)
	{
		if(head == NULL)
		{
			temp->data = right->data;
			temp->link = NULL;
			head = temp;
			right = right->link;
		}
		else
		{
			struct node* temp2 = (node*)malloc(sizeof(struct node));
			temp->link = temp2;
			temp2->data = right->data;
			temp2->link = NULL;
			right = right->link;
			temp = temp2;
		}
	}
	return head;
}
int main()
{
	struct node* left = NULL;
	struct node* right = NULL;
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		left = insertatbeg(left);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		right = insertatbeg(right);
	print(left);
	printf("\n");
	print(right);
	printf("\n");
	struct node* head = mergesortedlist(left,right);
	print(head);
	printf("\n");
	return 0;

}