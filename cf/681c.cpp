#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll long_MAX = 9223372036854775807;
const int intint_MAX = 2147483647;
int main(){
	int n;cin>>n;
	string str1 ("insert");
	string str2 ("getMin");
	string str3 ("removeMin");
	string str;
	long long int x=1,ans=0;
	int k = -1;
	pair < string, int > arr[100001];
	priority_queue<int, std::vector<int>, std::greater<int> > pq;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		if(str.compare(str1) == 0)
			{	
				cin>>x;
				pq.push(x);
				k++;
				arr[k].first = str;
				arr[k].second = x;
			}
		if(str.compare(str2) == 0)
		{
			cin>>x;
			if(pq.empty())
			{
				pq.push(x);
				k++;
				arr[k].first = str1;
				arr[k].second = x;

				k++;
				arr[k].first = str;
				arr[k].second = x;
			}
			else if(pq.top() == x)
			{
				k++;
				arr[k].first = str;
				arr[k].second = x;
			}
			else
			{
				k++;
				ans++;
				arr[k].first = str1;
				arr[k].second = x;
				pq.push(x);
				while(pq.top() != x)
				{
					pq.pop();
					k++;
					ans++;
					arr[k].first = str3;
					arr[k].second = -999999999;
				}
				k++;
				arr[k].first = str2;
				arr[k].second = x;
			}
		}
		if(str.compare(str3) == 0)
		{
			if(!pq.empty())
			{
				k++;
				arr[k].first = str3;
				arr[k].second = -999999999;
				pq.pop();
			}
			else
			{
				k++;
				ans++;
				arr[k].first = str1;
				arr[k].second = x;

				pq.push(x);
				pq.pop();
				
				k++;
				arr[k].first = str3;
				arr[k].second = -999999999;
			}
		}
	}
	cout<<k+1<<endl;
	for(int i=0;i<=k;i++)
	{
		cout<<arr[i].first<<" ";
		if(arr[i].second != -999999999)
			cout<<arr[i].second<<endl;
		else
			cout<<endl;

	}
}