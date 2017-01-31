#include <iostream>
using namespace std;
int seve(long long int n){
	long long int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=0;
	long long int temp=0;
	for(int i=2;i*i<=n;i++){
			if(arr[i]==0){
			long long int j=i*i;
		    while(j<n){
		    	//cout<<j<<" ";
		    	arr[j]=1;
		    	j=j+i;
		    }
		}//cout<<endl<<endl;
	}for(int i=2;i<n;i++){
		if(arr[i]==0){
			//cout<<i<<" ";
			temp++;
		}
	}return temp;
}
int main(){
	long long int n;cin>>n;
	cout<<endl<<endl<<seve(n)<<endl;
	return 0;
}


/*
this is algorithm is faster than brute force and root(n) approach.
algorithm
pseudo code
Input: an integer n > 1
 
Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.
 
 for i = 2, 3, 4, ..., not exceeding √n:
  if A[i] is true:
    for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n :
      A[j] := false
 
Output: all i such that A[i] is true.

*/