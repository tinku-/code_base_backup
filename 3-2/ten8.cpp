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
		struct node* temp = (node*)malloc(sizeof(node*));
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
void preorder(struct node* root)
{
	if(root == NULL) return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node* root)
{
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(struct node* root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
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
			preorder(root);
		if(n == 3)
			inorder(root);
		if(n == 4)
			postorder(root);
		if(n == 5)
			break;
	}
}