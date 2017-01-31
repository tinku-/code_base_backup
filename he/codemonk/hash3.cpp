#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
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
	cout<<x<<"; "<<ret<<endl;
	return ret;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,index=0;
		cin>>n;
		long long int q=0;
		queue<long long int> table[500];
		for(int i=0;i<n;i++)
		{
			cin>>q;
			index = bin(q);
			table[index].push(q); 
		}
		for(int i=0;i<500;i++)
			while(!table[i].empty())
			{
				cout<<table[i].front()<<" ";
				table[i].pop();
			}

		cout<<endl;	
	}
}