#include <stdio.h>
#include <stdlib.h>
int count1 = 0;
int count2 = 0;
struct node
{
	int data;
	struct node* next;
};
struct node* push(struct node* top,int x)
{
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->next = top;
	temp->data = x;
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
int value(struct node* top)
{
	while(top != NULL)
	{
		printf("%d->",top->data);
		if(top->data == 1)
			count1++;
		else
			count2++;
		top = top->next;
	}
	printf("NULL\n");
	return (count1/2 + count1%2 + count2/2 + count2%2);
}
int main()
{
	int i=0;
	struct node* top = NULL;
	char str[1000];
	fgets(str,100,stdin);
	while(str[i] != '\0' && str[i] != '\n')
	{
		if(str[i] == ')')
		{
			if(top == NULL)
				top = push(top,0);
			else 
			{
				if(top->data == 1)
					top = pop(top);
				else
					top = push(top,0);
			}
		}
		else
			top = push(top,1);
		i++;
	}

	int n=0;
	printf("ans = %d\n",value(top));
}