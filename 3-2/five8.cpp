#include <stdio.h>
struct algoridam
{
	char name[100];
	int ones;
};
void one(struct algoridam arr[],int i)
{
	int ans,ascii=0,j=0;
	while(arr[i].name[j] != '\0')
	{
		ascii += arr[i].name[j];
		j++;
	}
	ans = 0;
	while(ascii)
	{
		if(ascii%2 == 1)
			ans++;
		ascii = ascii/2;
	}
	arr[i].ones = ans;
}
int countsort(struct algoridam arr[],int n)
{
	int i=0;
	struct algoridam crr[1000];
	int brr[100000] = {0};
	for(i=0;i<n;i++)
		brr[arr[i].ones]++;
	for(i=1;i<100000;i++)
		brr[i] = brr[i] + brr[i-1];
	for(i=n-1;i>=0;i--)
	{
		crr[brr[arr[i].ones]] = arr[i];
		brr[arr[i].ones]--;
	}
	for(i=1;i<=n;i++)
		printf("%s %d\n",crr[i].name,crr[i].ones);//remove %d and ,crr[i].ones for required output
}
int main()
{
	int n,i;
	scanf("%d",&n);
	struct algoridam arr[1000];
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i].name);
		one(arr,i);
	}
	countsort(arr,n);
}
/*
input:
5
ridam
rohan
rahul
romil
apple

output:
rohan 3
apple 3
ridam 4
rahul 4
romil 4
*/