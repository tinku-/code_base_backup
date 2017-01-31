#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//a binary tree node has data ,pointer to left child
//and pointer to right child 

struct node{
	int data;
	struct node* left;
	struct node* right;
};

//helper function that allocates new data and 
//null left and right pointers

struct node* newNode(int data){
	struct node* node=(struct node*)
	malloc (sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	rerurn (node);
}

int main(){
	
	
}