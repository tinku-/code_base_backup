#include <iostream>
#define MAX 1000000
using namespace std;
int function(int row[],int column[],int n)
{
	int	ans = MAX;
	int mi1 = MAX,mi2 = MAX,rowindex,columnindex;
	for(int i=0;i<n;i++)
	{
		if(row[i] < mi1)
			{mi1 = row[i];rowindex = i;}
		if(column[i] < mi2)
			{mi2 = column[i];columnindex = i;}
	}
	if(mi1 > mi2)
	{
		ans = mi2;
		column[columnindex] += n;
		for(int i=0;i<n;i++)
			row[i]++;
	}
	else
	{
		ans = mi1;
		row[rowindex] += n;
		for(int i=0;i<n;i++)
			column[i]++;
	}
	return ans;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		int arr[n][n];
		int row[n];
		int column[n];
		int ans = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		for(int i=0;i<n;i++)
		{
			row[i] = 0;
			column[i] = 0;
			for(int j=0;j<n;j++)
				{	
					row[i] += arr[i][j];
					column[i] += arr[j][i];
				}
		}
		for(int i=0;i<k;i++)
			ans += function(row,column,n);
		cout<<ans<<endl;
	}
	return 0;
}