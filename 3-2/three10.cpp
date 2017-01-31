#include <stdio.h>
#include <math.h>
int arr[10001] = {-1};
int brr[10001] = {-1};
int crr[10001] = {-1};
int abs(int a,int b)
{
	if(a>=b)
		return a-b;
	return b-a;
}
int min(int a,int b,int c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	return c;
}
int brute(int l,int m,int n)
{
	int i=0,j=0,k=0,ans = 100000;
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			for(k=0;k<n;k++)
			{
				int temp=abs(arr[i],brr[j])+abs(brr[j],crr[k])+abs(arr[k],crr[i]);
				if(temp<=ans)
					ans=temp;
			}
	return ans;
}
int main()
{
	int l,m,n,i,ans = 100000;
	scanf("%d",&l);
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=0;i<l;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<m;i++)
		scanf("%d",&brr[i]);
	for(i=0;i<n;i++)
		scanf("%d",&crr[i]);
	int j=0,k=0;i=0;
	while(i<l && j<m && k<n )
	{
		int temp=abs(arr[i],brr[j])+abs(brr[j],crr[k])+abs(arr[k],crr[i]);
		if(temp<=ans)
			ans=temp;
		if(min(arr[i],brr[j],crr[k]) == arr[i])
			i++;
		else if	(min(arr[i],brr[j],crr[k]) == brr[j])
			j++;
		else
			k++;
	}
	printf("%d\n",ans);
	printf("correct ans %d\n",brute(l,m,n));//checking in O(n^3);

}