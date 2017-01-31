#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,ans=2;cin>>n;
	long long int temp=0,j=1,carry=0;
	vector<int> v;v.push_back(1);
	vector<int> w;w.push_back(1);
	vector<int> x;
	while(j<n)
	{
		for(int i=0;i<v.size();i++)
		{temp=v[v.size()-1-i]+w[w.size()-1-i]+carry;x.insert(x.begin(),1,temp%10);carry=temp/10;}
	    for(int i=v.size();i<w.size();i++)
	    {temp=w[w.size()-1-i]+carry;x.insert(x.begin(),1,temp%10);carry=temp/10;}
        if(carry!=0){x.insert(x.begin(),1,carry%10);j++;}
        for(int i=0;i<x.size();i++)cout<<x[i];cout<<"\n";
        w.swap(v);x.swap(w);x.clear();ans++;carry=0;
	}
	cout<<"\n\n"<<ans<"\n\n";

	return 0;
}



//done