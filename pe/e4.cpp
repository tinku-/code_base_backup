#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int check(long long int a)
{
	int f=0;
	long long int b=0,r=0,t=a;
	while(a!=0)
	{
		r=a%10;
		b=b*10 +r;
		a=a/10;
	}
	if(t==b){f=1;return f;}
	return f;
}
int main()
{	
	vector<int> v;
	long long int m,n,t1,t2,ans=0;
	cin>>m>>n;
	for(int i=m;i<=n;i++)
		{for(int j=m;j<=n;j++)
					{if(check(i*j)==1){t1=i*j;v.push_back(t1);}}}
	sort(v.begin(),v.end());				
	cout<<"\n"<<v[v.size()-1]<<"\n\n";
	return 0;
}
