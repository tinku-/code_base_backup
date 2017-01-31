//working....
#include <iostream>
using namespace std;
void insertionsort(long long int a[],long long int n){
	for(int i=1;i<n;i++){
		long long int key=a[i];
		long long int j=i-1;
		while(j>=0 && a[j]<key){
			(a[j+1]=a[j]);
			(a[j]=key);
			j--;
		}
	}
}

//driver function...........
int main(){
	long long int n;cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}insertionsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;return 0;
}


/*
time complexiety of insertion sort [O(n),O(n^2)], average case:O(n^2);

pseudo code for insertion sort

for i ← 1 to length(A) - 1
    j ← i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j ← j - 1
    end while
end for

*/