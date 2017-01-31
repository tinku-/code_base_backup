#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

#define B1 33
#define M1 10000009
#define B2 97
#define M2 10000007

string str,str1,str2;
long long int arr1[100502];
long long int arr2[100502];
long long int p1[100502];
long long int p2[100502];


void pre()
{
	p1[0] = 1;
	p2[0] = 1;
	for(int i=1;i<str.size();i++)
	{
		p1[i] = (p1[i-1]*B1)%M1;
		p2[i] = (p2[i-2]*B2)%M2;
	}
	for(int i=1;i<str.size();i++)
	{
		arr1[i] = (arr1[i-1]*B1 + str[i-1]-'a'+1)%M1;
		arr2[i] = (arr2[i-1]*B2 + str[i-1]-'a'+1)%M2;
	}
}
long long int gethash1(int l,int r)
{
	int len = r-l+1;
	long long int ret = (arr1[r] - (arr1[l-1]*p1[len])%M1 + M1)%M1;
	return ret;
}
long long int gethash2(int l,int r)
{
	int len = r-l+1;
	long long int ret = (arr2[r] - (arr2[l-1]*p2[len])%M2 + M2)%M2;
	return ret;
}
int main()
{
	int l1,r1,l2,r2,n;
	long long int h1,H1,h2,H2;
	cin>>str>>n;
	pre(); 
	while(n--)
	{
		cin>>l1>>r1>>l2>>r2;
		if(r2-l2 == r1-l1)
		{
			h1 = gethash1(l1,r1);
			H1 = gethash1(l2,r2);

			//h2 = gethash2(l1,r1);
			//+H2 = gethash2(l2,r2);

			//cout<<h1<<" and "<<H1<<" | "<<h2<<" and "<<H2<<endl;
			if(h1==H1 )
				cout<<"Yes";
			else
				cout<<"No";
		}
		else
			cout<<"No";
		cout<<endl;
		
	}
	return 0;
}