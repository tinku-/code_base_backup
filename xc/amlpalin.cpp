#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		vector <char> v;
		string strin;
		string s0 ("aa");
		string s1 ("ab");
		string s2 ("ba");
		string s3 ("bb");
		int s[4] = {0};
		long long int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>strin;
			if(s0.compare(strin) == 0)
				s[0]++;
			if(s1.compare(strin) == 0)
				s[1]++;
			if(s2.compare(strin) == 0)
				s[2]++;
			if(s3.compare(strin) == 0)
				s[3]++;
		}
		if(s[0]%2 == 0)
		{
			for(int i=0;i<s[0]/2;i++)
			{
				v.push_back('a');
				v.push_back('a');
			}	
			int temp = min(s[1],s[2]);
			for(int i=0;i<temp;i++)
			{
				v.push_back('a');
				v.push_back('b');
			}
			for(int i=0;i<s[3]/2;i++)
			{
				v.push_back('b');
				v.push_back('b');
			}
			if(s[3]%2 == 1)
				v.push_back('b');
		}
		else 
		{
			for(int i=0;i<s[0]/2;i++)
			{
				v.push_back('a');
				v.push_back('a');
			}	
			int temp = min(s[1],s[2]);
			for(int i=0;i<temp;i++)
			{
				v.push_back('a');
				v.push_back('b');
			}
			for(int i=0;i<s[3]/2;i++)
			{
				v.push_back('b');
				v.push_back('b');
			}
			v.push_back('a');
		}
		for(int i=0;i<v.size();i++)
			cout<<v[i];
		for(int i=0;i<v.size();i++)
			cout<<v[v.size()-1-i];
		cout<<endl;
	}
}