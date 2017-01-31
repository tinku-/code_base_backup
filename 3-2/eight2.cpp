#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
};		
struct node* enqueue(struct node* rear,struct node* front,int x)
{
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;
	if(rear == NULL && front == NULL)
	{
		rear = temp;
		front = temp;
		return rear;
	}
	rear->next = temp;
	rear = temp;
	return rear;
}
struct node* dequeue(struct node* front)
{
	struct node* temp = front;
	front = front->next;
	free(temp);
	return front;
}
void printq(struct node* head)
{
	while(head != NULL)
	{
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}
int main()
{
	int x,n;
	struct node* front1 = NULL;
	struct node* rear1 = NULL;
	struct node* front2 = NULL;
	struct node* rear2 = NULL;
	while(1<2)
	{
		printf("press\n1:push\n2:pop\n3:print queues\n4:exit\n");
		scanf("%d",&n);
		if(n == 1)
		{
			//push
			scanf("%d",&x);
			if(rear1 == NULL && front1 == NULL)
			{
				rear1 = enqueue(rear1,front1,x);
				front1 = rear1;
			}
			else
			{
				rear1 = enqueue(rear1,front1,x);
			}
		}
		if(n == 2)
		{
			//pop
			if(front1 == NULL)
				printf("empty stack\n");
			else{
			while(front1 != rear1)
			{
				if(rear2 == NULL && front2 == NULL)
				{
					rear2 = enqueue(rear2,front2,front1->data);
					front2 = rear2;
				}
				else
				{
					rear2 = enqueue(rear2,front2,front1->data);
				}
				front1 = dequeue(front1);
			}
			printf("%d\n",front1->data);
			struct node* temp;
			temp = front1;front1 = front2;front2 = NULL;
			temp = rear2;rear1 = rear2;rear2 = NULL;}
		}
		if(n == 3)
		{
			printq(front1);
			printq(front2);
		}
		if(n == 4)
			break;
	}		
}