#include <iostream>
#include <stdio.h>
#include <stdlib.H>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
int length(struct node *head)
{
	struct node *current = head;
	int count = 0;
	while (current != NULL)
	{
		count++;
		current = current -> next;
	}
	return count;
}

