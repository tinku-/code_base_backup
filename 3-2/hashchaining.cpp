#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* hash[10] = {NULL};
struct node* insertatbeg(struct node* head,int x)
{
	struct node* temp = (node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = head;
	head = temp;
	return head;
}
void print(struct node* head,int i)
{
	cout<<i<<" ";
	while(head != NULL)
	{
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL"<<endl;
}
void search(struct node* head,int x)
{
	while(head != NULL)
	{
		if(head->data == x)
			{cout<<"found"<<endl;return ;}
		head = head->next;
	}
	cout<<"notfound"<<endl;
}
struct node* del(struct node* head,int x)
{
	struct node* temp = head;
	if(head->data == x)
	{
		head = head->next;
		free(temp);
		return head;
	}
	while(temp->next->data != x)
		temp = temp->next;
	if(temp->next->data == x)
	{
		struct node* temp2 = temp->next;
		temp->next = temp->next->next;
		free(temp2);
	}
	return head;
}
int main()
{
	while(1)
	{
		int n,x;
		cin>>n;
		if(n == 1) // insert
		{
			cin>>x;
			hash[x%10] = insertatbeg(hash[x%10],x);
		}
		if(n == 2) // print
		{
			for(int i=0;i<10;i++)
			{
				if(hash[i] == NULL)
					cout<<i<<" "<<"NULL"<<endl;
				else
					print(hash[i],i);
			}
		}
		if(n == 3) // search
		{
			cin>>x;
			search(hash[x%10],x);
		}
		if(n == 4)// delete 	
		{
			cin>>x;
			hash[x%10] = del(hash[x%10],x);
		}
		if(n == 5)
			break;
	}
	return 0;
}