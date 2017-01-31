#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string in;
		int arr[27];
		for(int i=0;i<=26;i++)
			arr[i]=0;
		string reserve;
		cin>>in>>reserve;
		for(int i=0;i<reserve.size();i++)
			arr[reserve[i]-'a']++;
		//for(int i=0;i<reserve.size();i++)
		//	cout<<arr[i]<<" ";
		for(int i=0;i<in.size();i++)
		{
			for(int j=0;j<=26;j++)
			{

				if(in[i] - 97 > j && arr[j] > 0)
				{
					//cout<<in[i] - 97<<endl;
					arr[j]--;
					in[i] = j + 'a';
					break;
				}					
			}
		}
		cout<<in<<endl;
	}
}