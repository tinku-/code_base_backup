#include <bits/stdc++.h>
using namespace std;

int bsearch(int aux[],int left,int right,int key)
{
	int mid;
	while(left < right - 1)
	{
		mid = left + (right - left)/2;
		//cout<<"fds";
		if(aux[mid] >= key)
			right = mid;
		else 
			left = mid;
	}
	return right;
}
int main()
{
	int n;cin>>n;
	int arr[n];
	int aux[n+5];
	memset(aux,0,sizeof(aux));
	int length  = 1;
	aux[0] = arr[0];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		if(arr[i] < aux[0])
			aux[0] = arr[i];
		else if(arr[i] > aux[length - 1])
			aux[length++] = arr[i];
		else
			aux[bsearch(aux,0,length-1,arr[i])] = arr[i];
	}
	for(int i=0;i<length;i++)
		cout<<aux[i]<<" ";
	cout<<endl;
	cout<<length;
}

/*
16 
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15

0 1 3 7 11 15 
6

#include <bits/stdc++.h> //check 
using namespace std;
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	set<int> st;
	set<int>::iterator it;
	st.clear();
	for(int i=0;i<n;i++)
	{
		st.insert(arr[i]);
		it = st.find(arr[i]);
		it++;
		if(it != st.end())
			st.erase(it);
	}cout<<st.size();
	return 0;
}

*/