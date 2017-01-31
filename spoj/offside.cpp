#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,d;
	while(1)
	{
		cin>>a>>d;
		if(a == 0 && d == 0) return 0;
		int attaker=999999,def1=9999999,def2=999999,temp;
		for(int i=0;i<a;i++)
		{
			cin>>temp;
			if(temp < attaker)
				attaker = temp;
		}
		for(int i=0;i<d;i++)
		{
			cin>>temp;
			if(temp < def1)
			{
				def2 = def1;
				def1 = temp;
			}
			else if(temp < def2)
				def2 = temp;
		}
		//cout<<attaker<<" "<<def1<<" "<<def2<<endl;
		if(def2 > attaker	)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
}