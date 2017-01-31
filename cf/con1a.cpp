#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	int min = 999,max = -999,x,y;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i] < min)
		{
			x = i;
			min = arr[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i] > max)
		{
			y = i;
			max = arr[i];
		}
	}
	if(x > y)
		swap(x,y);
	int ans = abs(x-y);
	int ans1 = abs(y-0);
	int ans2 = abs(n-1-x);

	if(ans1 > ans)
		ans = ans1;
	if(ans2 > ans)
		ans = ans2;
	cout<<ans;
	return 0;
}