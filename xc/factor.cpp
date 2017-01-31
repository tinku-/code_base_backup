#include <bits/stdc++.h>
using namespace std;
void factor(int n) 
{          
	 int i;          
	for(i=2;i<=(int)sqrt(n);i++) 
	{            
		while(n % i == 0) 
		{              
			printf("%d ",i);              
			n /= i;            
		}          
	}          
	if (n > 1) printf("%d",n);          
	printf("\n");        
}
int main()
{
	int n;
	while(1)
	{
		cin>>n;
		if(n == -1)return 0;
		factor(n);
	}
	return 0;
}