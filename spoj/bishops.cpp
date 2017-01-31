#include <bits/stdc++.h>
using namespace std;
void bis(vector <int> v)
{
	if(v.size() == 1 && (v[0] == 0 || v[0] == 1))
	{
		cout<<v[0]<<endl;
		return ;
	}
	int carry=0,temp=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		temp = v[i]*2 + carry;
		carry = temp/10;
		v[i] = temp%10; 
	}
	while(carry != 0)
	{
		v.insert(v.begin(),carry%10);
		carry /= 10;
	}

	carry = 2;
	for(int i=v.size()-1;i>=0;i--)
	{
		if(v[i] >= carry)
		{
			v[i] -= carry;
			break;
		}
		else
		{
			v[i] = 10+v[i]-carry;
			carry = 1;
		}
	}
	for(int i=0;i<v.size();i++)
	{
		if(i==0 && v[0] == 0)
			continue;
		else
			cout<<v[i];
	}
	cout<<endl;
	return;
}
int main()
{
	string s;
	while(cin>>s)
	{
		vector <int> v;
		for(int i=0;i<s.size();i++)
			v.push_back(s[i]-'0');
		bis(v);

	}
}