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
		temp->left = temp->right = NULL;
		root = temp;
		return root;
	}
	else if(x <= root->data)
		root->left = insert(root->left,x);
	else
		root->right = insert(root->right,x);
	return root;
}
void inorder(struct node* root,int x)
{
	if(root == NULL) return;
	inorder(root->left,x);
	if(root->data <= x)
	printf("%d ",root->data);
	inorder(root->right,x);
}
int main()
{
	int x,n;
	struct node* root = NULL;
	while(1)
	{
		printf("1 insert,2 grater than k,3 end\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: 
				scanf("%d",&x);
				root = insert(root,x);
				break;
			case 2:
				printf("enter k: \n");
				scanf("%d",&x);
				inorder(root,x);
				break;
			case 3:
				return 0;
		}
	}
}