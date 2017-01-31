#include <iostream>
#include <vector>
using namespace std;
int main(){
	int t=0;cin>>t;
	for(int x=0;x<t;x++)
	{
		long long int a,b,temp=0;cin>>a>>b;a=a%10;vector<int> v;v.push_back(a);
		if(b==0)cout<<1<<"\n";
		else if(a==0)cout<<0<<"\n";
		else if(a==1)cout<<1<<"\n";
		else if(a==5 || a==6)cout<<v[0]<<"\n";
		else{
			while(temp!=a)
			{
				temp=v[v.size()-1]*a;
				temp=temp%10;
				if(temp!=a)
					v.push_back(temp);
			}
			for(int i=0;i<v.size();i++)
				cout<<v[i]<<" ";cout<<"\n";
		    if(b%v.size()!=0)
		    	cout<<v[b%v.size()-1]<<"\n";
			else 
				cout<<v[v.size()-1]<<"\n";
			}
    }return 0;
}

/*
another solution

#include <bits/stdc++.h>
using namespace std;
int mod_exp(long long int a,long long int b)
{
	int x;
	if(b == 0)
		return 1;
	else if(b%2 == 0)
	{
		int x = mod_exp(a,b/2);
		return ((x%10)*(x%10))%10;
	}
	else
		return ((mod_exp(a,b-1)%10)*(a%10))%10;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int a,b;cin>>a>>b;
		cout<<mod_exp(a,b)<<endl;
	}
}
*/
