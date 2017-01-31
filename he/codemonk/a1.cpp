 #include <iostream>
using namespace std;
int main()
{
	int t=0;cin>>t;
	while(t--)
	{
		long long int n,x,flag = 0;
		cin>>n>>x;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		long long int sum=arr[0],end=0,start=0;
		long long int i=0;
		//cout<<endl<<endl;
		if(sum == x)
		{
			flag = 1;
			cout<<"YES"<<endl;
		}
		while(start != n-1 && flag == 0)
		{
			if(sum == x)
			{
				flag = 1;
				cout<<"YES"<<"\n";
				break;
			}
			if(sum < x && end != n-1)
			{
				end++;
				sum = sum + arr[end];
				if(sum == x)
				{
					flag = 1;
					cout<<"YES"<<"\n";
					break;
				}
				//cout<<sum<<endl;
			}
			if(sum < x && end == n-1)
				break;
			if(sum > x && start != n-1) 
			{
				sum = sum - arr[start];
				if(sum == x)
				{
					flag = 1;
					cout<<"YES"<<"\n";
					break;
				}
				//cout<<sum<<endl;
				start++;
			}
		}
		if(flag == 0)
			cout<<"NO"<<"\n";
	}
	return 0;
}