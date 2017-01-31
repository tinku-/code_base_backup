#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
	int data;
	string name;
};
bool sort_by_name(node lhs,node rhs)
{
	return lhs.name < rhs.name;
}
bool sort_by_data(node lhs,node rhs)
{
	return lhs.data > rhs.data;
}
int main()
{
	int n;
	cin>>n;
	struct node arr[n];
	for(int i=0;i<n;i++)
	{	
		cin>>arr[i].name>>arr[i].data;
	}
	stable_sort(arr,arr+n,sort_by_name);
	stable_sort(arr,arr+n,sort_by_data);
	//cout<<endl<<endl;

	for(int j=0;j<n;j++)
	{
		cout<<arr[j].name<<" "<<arr[j].data<<endl;
	}
	return 0;
}	