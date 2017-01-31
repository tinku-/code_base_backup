#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class EllysReversals
{
public:
string process(string A)
{
	vector<string> B;
	string t;
	for(int k=0;k<A.size();k+=2)
	{
		t="";
		if(k<A.size()-1)
		{
			t+=min(A[k],A[k+1]);
			t+=max(A[k],A[k+1]);
		}
		else
			t+=A[k];
		B.push_back(t);
	}
	if(A.size()%2==0)
	sort(B.begin(),B.end());
	else
	sort(B.begin(),B.end()-1);
	string ans="";
	for(int i=0;i<B.size();i++)
	ans+=B[i];
	return ans;
}
int getMin(vector <string> words)
{
	vector<string> processed;
	int mark[50]={0,0};
	for(int i=0;i<words.size();i++)
	{
		processed.push_back(process(words[i]));
		//cout<<processed[i]<<"\n";
	}
	sort(processed.begin(),processed.end());
	for(int i=1;i<processed.size();i++)
	{
		if(processed[i]==processed[i-1])
		{
			mark[i]=1;
			mark[i-1]=1;
			i++;
		}
	};
	int x=0;
	for(int i=0;i<processed.size();i++)
	if(mark[i]==0)
	x++;
	return x;
}
};
