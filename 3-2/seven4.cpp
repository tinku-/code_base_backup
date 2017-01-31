#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct node* newnodeptr(int x)
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
}
struct node* circularinsertatbeg(struct node* head)
{
	int x;
	scanf("%d",&x);
	struct node* newnode = newnodeptr(x);
	if(head == NULL)
	{
		head = newnode;
		head->prev = head;
		head->next = head;
		return head;
	}
	else
	{
		newnode->next = head;
		newnode->prev = head->prev;
		head->prev->next = newnode;
		head->prev = newnode;
		head = newnode;
		return head;
	}
}	
struct node* circularinsertatend(struct node* head)
{
	if(head == NULL)
	{
		head = circularinsertatbeg(head);
		return head;
	}
	else
	{
		int x;
		scanf("%d",&x);
		struct node* newnode = newnodeptr(x);	
		newnode->next = head;
		newnode->prev = head->prev;
		head->prev->next = newnode;
		head->prev = newnode;
	}
}
struct node* insert(struct node* head)
{
	int i,x,n;
	struct node* temp = head;
	printf("i :\n");
	scanf("%d",&n);
	if(head == NULL)
	{
		head = circularinsertatbeg(head);
		return head;
	}
	for(i=0;i<n-1;i++)
		temp = temp->next;
	if(temp == head)
	{
		head = circularinsertatbeg(head);
		return head;
	}
	scanf("%d",&x);
	struct node* newnode = newnodeptr(x);
	newnode->prev = temp;
	newnode->next = temp->next;
	temp->next->prev = newnode;
	temp->next = newnode;
	return head;

}
void print(struct node* head)
{
	struct node* temp = head;
	if(temp == NULL)
	{
		printf("empty\n");
		return;
	}
	printf("%d->",temp->data);
	temp = temp->next;
	while(temp != head) 
	{
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d again\n",temp->data);

}
int main()
{
	int n;
	struct node* head = NULL;
	while(1>0)
	{	
		printf("press :\n1:print\n2:insert at beg\n3:insert at end\n4:insert at i\n5:exit\n");
		scanf("%d",&n);
		if(n == 1)
			print(head);
		if(n == 2)
			head = circularinsertatbeg(head);
		if(n == 3)
			head = circularinsertatend(head);
		if(n == 4)
			head = insert(head);
		if(n == 5)
			break;
	}
}