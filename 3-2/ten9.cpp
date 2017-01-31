#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node* root,int x)
{
	if(root == NULL)
	{
		struct node* temp = (node*)malloc(sizeof(struct node));
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		root = temp;
		return root;
	}
	else if(x <= root->data)
		root->left = insert(root->left,x);
	else
		root->right = insert(root->right,x);
	return root;
}
void postorder_iterative(struct node* root)
{

	struct node* stack1[100];
	struct node* stack2[100];
	int top1=0,top2=-1;
	stack1[top1] = root;
	while(top1 != -1)
	{
		top2++;
		stack2[top2] = stack1[top1];
		top1--;
		struct node* curr = stack2[top2];
		if(curr->left != NULL)
		{
			top1++;
			stack1[top1] = curr->left;
		}
		if(curr->right != NULL)
		{
			top1++;
			stack1[top1] = curr->right;
		}
	}
	while(top2 != -1)
	{
		struct node* curr = stack2[top2];
		printf("%d ",curr->data);
		top2--;
	}
	printf("\n");
}
int main()
{
	struct node* root = NULL;
	int n,x;
	while(1)
	{
		scanf("%d",&n);
		if(n == 1)
		{
			scanf("%d",&x);
			root = insert(root,x);
		}
		if(n == 2)
			postorder_iterative(root);
		if(n == 3)
			break;
	}
}
