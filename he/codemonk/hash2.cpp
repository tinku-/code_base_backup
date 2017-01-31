#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int bin(long long int x)
{
	int ret=0;
	while(x)
	{
		if(x%2 == 1)
			ret++;
		x /= 2;
	}
	//cout<<x<<"; "<<ret<<endl;
	return ret;
}
struct node
{
	struct node* next;
	long long int data;
	//int index;	
};
struct node* insert_end(struct node* head,long long int y)
{
	struct node* temp = (node*)malloc(sizeof(struct node));
	struct node* temp2 = head;
	temp->next = NULL;
	temp->data = y;
	if(temp2 == NULL)
	{
		head = temp;
		return head;
	}
	while(temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;

	return head;

}
void print(struct node* head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,index=0;
		cin>>n;
		long long int q=0;
		struct node* table[500];
		for(int i=0;i<500;i++)
			table[i] = NULL;
		for(int i=0;i<n;i++)
		{
			cin>>q;
			index = bin(q);
			table[index] = insert_end(table[index],q);
		}
		for(int i=0;i<500;i++)
		{
			print(table[i]);
		}
		cout<<endl;	
	}
}