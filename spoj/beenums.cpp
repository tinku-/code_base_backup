#include <bits/stdc++.h>
using namespace std; 
int main()
{
	long long int n;
	while(1)
	{
		long long int flag=1;
		cin>>n;
		if(n == -1)return 0;
		n--;
		if(n == 0)
			flag = 0;
		else if(n%3 == 0)
		{
			for(int i=2;3*i*(i-1) <= n;i++)
			{
				if(3*i*(i-1) == n)
					flag = 0;
			}

		}
		if(flag == 0)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
}