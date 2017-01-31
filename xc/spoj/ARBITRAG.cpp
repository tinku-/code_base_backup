#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int n,num_relations,pos1,pos2,case_no=0;
	string curr1,curr2,x;
	double relation;
	map <string,int> currency;
	bool flag;
	cin>>n;
	while(n!=0)
	{
		case_no++;
		currency.clear();
		for(int i=0;i<n;i++)
		{
			cin>>x;
			currency[x]=i;
		}
		cin>>num_relations;
		vector <double> temp(n,0.0);
		vector < vector<double> > A(n,temp);
		for(int i=0;i<num_relations;i++)
		{
			cin>>curr1>>relation>>curr2;
			pos1=currency.find(curr1)->second;
			pos2=currency.find(curr2)->second;
			A[pos1][pos2]=relation;
		}
		for(int through=0;through<n;through++)
		{
			for(int s=0;s<n;s++)
			{
				for(int t=0;t<n;t++)
				{
					if(A[s][t]<A[s][through]*A[through][t])
						A[s][t]=A[s][through]*A[through][t];
				}
			}
		}
		flag=false;
		for(int i=0;i<n;i++)
			if(A[i][i]>1.0)
			{
				flag=true;
				break;
			}
		if(flag)
			cout<<"Case "<<case_no<<": Yes\n";
		else
			cout<<"Case "<<case_no<<": No\n";
		cin>>n;
	}
	return 0;
}