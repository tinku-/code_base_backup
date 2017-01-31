#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int test;cin>>test;
	while(test--)
	{
		char c[100];
		scanf("%s",c);
		int size=0;
		while(c[size] != '\0')
			size++;
		for(int i=size-1;i>=0;i--)
			cout<<c[i];
		cout<<endl;
	}
}