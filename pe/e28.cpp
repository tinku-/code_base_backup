#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	clock_t t1,t2;
    t1=clock();
	long long int n=0,sum=1,temp=0;
	//cin>>n;
	n=1001;
	for(int i=3;i<=n;i++)
	{
		if(i%2==1)
		{
			sum=sum+i*i*4-(i-1)*6;
			cout<<sum<<"\n\n";
		}

	}
	t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff<<endl;
    //system ("pause");
    return 0;
} 