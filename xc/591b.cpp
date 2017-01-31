#include <iostream>
using namespace std;
int main(){
	long long int n,m;
	cin>>n>>m;
	char c[n];
	for(int i=0;i<n;i++)
		cin>>c[i];
	while(m--)
	{
		char x,y;
		cin>>x>>y;
		for(int i=0;i<n;i++)
		{
			if(c[i] == x)
				c[i] = y;
			else if(c[i] == y)
				c[i] = x;
		}
		for(int i=0;i<n;i++)
			cout<<c[i];
	}return 0;
}