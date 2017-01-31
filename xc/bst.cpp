#include <bits/stdc++.h>
using namespace std;
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
	else if(x > root->data)
		root->right = insert(root->right,x);
	else
		root->left = insert(root->left,x);
	return root;
}
void inorder(struct node* root)
{
	if(root == NULL)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
	struct node* root = NULL;
	while(1)
	{
		int x;
		cin>>x;
		if(x == 1)
		{
			cin>>x;
			root = insert(root,x);
		}
		if(x == 2)
		{
			inorder(root);
		}
	}
}