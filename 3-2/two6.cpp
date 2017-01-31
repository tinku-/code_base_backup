#include <stdio.h>
#include <math.h>
//#include <time.h>
//#include <iostream>
using namespace std;
int arr[100000] = {0};
void sieve(int n)
{	
	int i=0;
	for(i=2;i*i<=n;i++)
	{
		if(arr[i]==0)
		{
			long long int j=i*i;
		    while(j<n)
		    {
		       	arr[j]=1;
		    	j=j+i;
		    }
		}
	}
	//for(i=2;i<n;i++)
	//	if(arr[i] == 0)
	//		printf("%d ",i);
	//printf("\n");
}
int prime(long long int x)
{
	int i=0;
	if(arr[i] != 0)
		return 0;
	else
	{
		int k = pow(x,.5);
		sieve(k);
		for(i = 2;i<=k;i++)
		{
			if(arr[i] == 0)
			{
				if(x%i == 0)
					return 0;
			}
		}
	}
	return 1;
}
int power(long long int x)
{
	int i=0,sum=0,temp=0;
	for(i = 2;i<= x;i++)
	{
		if(prime(i) == 1)
		{
			int count = 0,temp = x;
			while(x%i == 0)
			{
				count++;
				x = x/i;
			}
			sum += count;
		}
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	//if(prime(n) == 0)
	//	printf("no\n");
	//else
	//	printf("yes\n");
	printf("%d",power(n));
	printf("\n%d",power(99997877));
	return 0;
}

//to check excution time 
//library bhi uncomment kar dena time aur iostream wali
/*
int main()
{
    clock_t t1,t2;
    t1=clock();
    
	printf("\n%d",power(729));
	printf("\n%d",power(99497877));
	printf("\n%d",power(921997877));

    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff/CLOCKS_PER_SEC<<endl;
    return 0;    
}*/
//rum on ideone to check time even more