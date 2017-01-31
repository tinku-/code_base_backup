#include <bits/stdc++.h>
using namespace std;
int tests,n,m,a[1<<20],b[1<<20];
int w[1<<20];
int get(int x)
{
	if (w[x]==x)
		return x;
	return w[x]=get(w[x]);
}
void merge(int a,int b)
{
	if (rand()%2)
		swap(a,b);
	w[a]=b;
}
int main(){
ios_base::sync_with_stdio(0);
//cin.tie(0);
cin>>tests;
for (;tests;--tests)
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i];
	}
	for (int i=1;i<=n;i++)
		w[i]=i;
	for (int i=1;i<n;i++)
	{
		int id;
		cin>>id;
		int q,w;
		q=a[id];
		w=b[id];
		q=get(q);
		w=get(w);
		merge(q,w);
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (w[i]==i)
			++cnt;
	if (cnt==1)
	{
		cout<<"YES"<<endl;
	}
		else
	cout<<"NO"<<endl;
}
return 0;}