#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 12,flag;
	string arr[] = {"at","","","","ball","","car","","","dad","",""};
	string s = "ball";
	//string s = "caball";
	for(int i=0;i<n;i++)
	{
		if(s.size() == arr[i].size())
		{
			flag = 0;
			for(int j=0;j<s.size();j++)
			{
				if(s[j] != arr[i][j])
					flag = 1;
			}
			if(flag == 0)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}