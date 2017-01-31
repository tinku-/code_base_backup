#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* push(struct node* top,int x)
{
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = top;
	top = temp;
	return top;
}
struct node* pop(struct node* top)
{
	struct node* temp = top;
	top = top->next;
	free(temp);
	return top;
}
void print(struct node* top)
{
	while(top != NULL)
	{
		printf("%d->",top->data);
		top = top->next;
	}
	printf("NULL\n");
}
int main()
{
	int n,x;
	struct node* top1 = NULL;
	struct node* top2 = NULL;
	while(1<2)
	{
		printf("press\n1:enqueue\n2:dequeue\n3:print stacks\n4:exit\n");
		scanf("%d",&n);
		if(n == 1)
		{
			//enqueue
			scanf("%d",&x);
			top1 = push(top1,x);
		}
		if(n == 2)
		{
			//dequeue
			if(top1 == NULL)
				printf("empty queue\n");
			else
			{
				while(top1 != NULL)
				{
					top2 = push(top2,top1->data);
					top1 = top1->next;
				}
				printf("%d\n",top2->data);
				top2 = pop(top2);
				while(top2 != NULL)
				{
					top1 = push(top1,top2->data);
					top2 = top2->next;
				}
			}
		}
		if(n == 3)
		{
			print(top1);
			print(top2);
		}
		if(n == 4)
			break;
	}
}
