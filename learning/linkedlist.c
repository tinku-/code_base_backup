#include <stdio.h>
#include <stdlib.h>

struct node{
	void *data;
	struct node *node;
};
void push 