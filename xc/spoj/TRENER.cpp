#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	string x;
	cin>>n;
	vector <int> counter(26,0);
	for(int i=0;i<n;i++)
	{
		cin>>x;
		counter[x[0]-'a']++;
	}
	vector <char> A;
	for(int i=0;i<26;i++)
		if(counter[i]>=5)
			A.push_back((char)('a'+i));
	if(A.empty())
		cout<<"PREDAJA";
	else
	{
		sort(A.begin(), A.end());
		for(int i=0;i<A.size();i++)
			cout<<A[i];
	}
	return 0;
}