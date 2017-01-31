#include <stdio.h>

char A[8];
int a[]={1,2,3,4,5,6,7,8,9};
int count;


void solve()
{
	int i;
	long long int num=a[0];
	long long int sum=0;
	int pin=0,cin=0;
	int nin=0;
	char psign='+';

	for(i=0;i<8;i++)
	{

		if(A[i]=='*')
		{
			num=num*10+a[i+1];

		}
		else
		{
			if(psign=='+')
			{
				sum=sum+num;
				num=a[i+1];

			}
			else
			{
				sum=sum-num;
				num=a[i+1];


			}
			psign=A[i];

		}

		
	}

	if(num!=0)
	{
		if(psign=='+')
		sum=sum+num;
		else
		sum=sum-num;
		num=0;

	}


	if(sum==100)
	{
		count++;
		printf("%d",a[0]);
		for(i=0;i<8;i++)
		{
			if(A[i]!='*')
				printf("%c",A[i]);
			printf("%d",a[i+1]);
		}

		printf(" = %lld",sum);
		printf("\n");

	}


	return ;


}

void permutate(int n)
{
	if(n<1)
	{
		solve();
	}
	else
	{
		A[n-1]='+';
		permutate(n-1);

		A[n-1]='-';
		permutate(n-1);

		A[n-1]='*';
		permutate(n-1);
	}
}


int main()
{

	int n;

	// scanf("%d",&n);

	n=100;


	permutate(8);


printf("Total number of ways are: %d\n",count);
	
	return 0;
}