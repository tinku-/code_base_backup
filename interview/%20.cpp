#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int cnt=0,j=0,n=0,i=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == ' ')
			cnt++;
	}
	//cout<<cnt;
	n = s.size() + 2*cnt;
	char arr[n];

	for(int i=0;i<s.size();i++)
	{
		if(s[i] == ' ')
		{
			arr[j] = '2';j++;
			arr[j] = '0';j++;
			arr[j] = '%';j++;
		}
		else
		{
			arr[j] = s[i];j++;
		}
	}
	for(int i=0;i<n;i++)
		cout<<arr[i];
	cout<<endl;
}