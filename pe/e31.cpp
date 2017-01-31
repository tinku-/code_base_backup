#include <iostream>
using namespace std;
int main()
{
	long long int ans=0,temp=0,n=0;cin>>n;
	{for(int i=0;i<=(n/1);i++)
		{for(int j=0;j<=(n/2);j++)
			{for(int k=0;k<=(n/5);k++)
				{for(int l=0;l<=(n/10);l++)
					{for(int m;m<=(n/20);m++)
						{for(int o;o<=(n/50);o++)
							{for(int p;p<=(n/100);p++)
								{if((i+j*2+k*5+l*10+m*20+o*50+p*100)==n){ans++;cout<<" "<<ans<<"\n\n";}}}}}}}}}
	return 0;
} 