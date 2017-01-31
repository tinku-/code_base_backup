#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int n;
	cin>>n;
	string s;cin>>s;
	vector<int> v;
	int count=0,count1=0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'B')
			count++;
		if(s[i] == 'W' && count > 0)
		{
			v.push_back(count);
			count=0;
		}

	}
	if(s[n-1] == 'B')
		v.push_back(count);
	cout<<v.size()<<endl;
	if(v.size() > 0)
	{
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<" ";
	}
	return 0;
}