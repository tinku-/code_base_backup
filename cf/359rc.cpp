#include <bits/stdc++.h>
using namespace std;
int arr[500] = {0};
int base7(int x)
{
	int i=0;
	while(x)
	{
		arr[500-1-i] = x%7;
		x = x/7;
		i++;
	}
	return i-1;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i = base7(n); i < 500; i++)
	{
		cout<<arr[i];
	}

}