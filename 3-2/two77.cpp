#include <stdio.h>
#include <math.h>
long long int an;
int summ[15];
long long int counter;
int a[15];
int nod;
void solve()
{
	int i;
	long long int num=0;

	for(i=0;i<nod;i++)
	{
		num = num*10+a[i];
	}
	//printf("%lld\n",num);
	if(num<=an)
		counter++;
	return ;

}
int dig(long long int nn)
{
	int dig=0;
	while(nn>0)
	{
		dig++;
		nn=nn/10;
	}
	//printf("%d",dig);
	return dig;
}
void fillsum()
{
	int i,sum=0,count=1;
	summ[0]=0;
	for(i=0;i<12;i++)
	{
		count=count*3;
		sum=sum+count;
		summ[i+1]=sum;

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
		a[n-1]=1;
		permutate(n-1);

		a[n-1]=7;
		permutate(n-1);

		a[n-1]=9;
		permutate(n-1);
	}
	return ;
}
int main()
{
	fillsum();
	scanf("%lld",&an);
	nod=dig(an);
	permutate(nod);
	printf("%lld\n",counter+summ[nod-1]);
	return 0;
}
