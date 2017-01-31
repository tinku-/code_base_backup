#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;cin>>n>>k;
	int arr[n];
	int correct=0,best=0,worst=0,temp=k,poss=0;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		arr[i] = s.size();
		//cout<<arr[i]<<endl;
	}
	cin>>s;
	correct = s.size();

	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{

		if(arr[i] < correct)
		{
			best++;
			temp--;
			if(temp == 0)
			{
				best += 5;
				temp = k;
			}
		}
		if(arr[i] == correct && temp > 0)
		{
			//cout<<best<<"b";
			best++;
			cout<<best<<" ";
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i] > correct || i == n-1) 
		{
			if(temp == k)
				{cout<<"l"<<(worst-5);break;}
			else
				cout<<worst;
			break;
		}
		if(arr[i] <= correct)
		{
			worst++;
			temp--;
			if(temp == 0)
			{
				worst += 5;
				temp = k;
			}
		}
	}
	return 0;
}