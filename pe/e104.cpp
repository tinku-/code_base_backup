#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,ans=2;cin>>n;bool f=false;
	long long int temp=0,j=1,carry=0;
	int a[9]={1,2,3,4,5,6,7,8,9};
	int b[9]={0,0,0,0,0,0,0,0,0};
	vector<int> v;v.push_back(1);
	vector<int> w;w.push_back(1);
	vector<int> x;
	while(f==false)
	{
		for(int i=0;i<v.size();i++)
		{temp=v[v.size()-1-i]+w[w.size()-1-i]+carry;x.insert(x.begin(),1,temp%10);carry=temp/10;}
	    for(int i=v.size();i<w.size();i++)
	    {temp=w[w.size()-1-i]+carry;x.insert(x.begin(),1,temp%10);carry=temp/10;}
        if(carry!=0){x.insert(x.begin(),1,carry%10);j++;}
        for(int i=0;i<9;i++){for(int j=0;j<9;i++){if(x[i]==a[j])b[j]++;if(x[x.size()-1-i]==a[j])b[j]++;}}
        for(int i=0;i<9;i++)if(b[i]!=2)break;f=true;
        w.swap(v);x.swap(w);x.clear();ans++;carry=0;
        cout<<"\n"<<ans;
	}
	cout<<"\n\n"<<ans<"\n\n";
	return 0;
}
