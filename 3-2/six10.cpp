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
	temp->link = head;
	temp->data = x;
	head = temp;
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
struct node* revesre(struct node* head,struct node* p)
{
	if(p->link == NULL)
	{
		head = p;
		return head;
	}
	head = revesre(head,p->link);
	p->link->link = p;
	p->link = NULL;
	return head;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	struct node* head = NULL;
	for(i=0;i<n;i++)
	{
		head = insertatbeg(head);
	}
	print(head);
	printf("\n");
	head = revesre(head,head);
	print(head);
	printf("\n");
	return 0;
}
