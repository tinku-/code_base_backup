#include <stdio.h>
int candidate(int arr[],int n)
{
	int majindex = 0,count = 1,i;
	for(i=1;i<n;i++)
	{
		if(arr[majindex] == arr[i])
			count++;
		else
			count--;
		if(count == 0)
		{
			majindex = i;
			count = 1;
		}
	}
	return arr[majindex];
}
int majority(int arr[],int n)
{
	int i=0,count = 0;
	int candid = candidate(arr,n);
	for(i=0;i<n;i++)
	{
		if(arr[i] == candid)
			count++;
	}
	if(count > n/2)
		printf("%d\n",candid);
	else
		printf("NONE\n");
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int arr[10000];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	majority(arr,n);
	return 0;
}


/*
http://www.geeksforgeeks.org/majority-element/
*/
//why this algoridam work?
/*
Image that there are 2m+1 people and every one has a vote. 
He can use this vote to add 1 point for himself, or to take 1 point off another.
 As we already know that there will be a winner X (he has at least m supporters).
 Consider the toughest situation for X to win the election: 
 All the other m people ally with each other and forms one big group.  
 Even in this situation, X will have at least 1 points in this end, while others all sacrifices. 
 Not to mention that the other m people may form smaller groups and fight with each other 
 (Moore Voting Algorithm actually is a reflection of this situation)
 */


