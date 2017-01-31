#include <bits/stdc++.h>
using namespace std;
void possibleSubsets(char A[], int N)
{
    for(int i = 0;i < (1 << N); ++i)
    {
        for(int j = 0;j < N;++j)
            if(i & (1 << j))
                cout<<j<<": "<<A[j]<<" ";
        cout<<endl;
	}
}
int main()
{
	char A[3] = {'a','b','c'};
	possibleSubsets(A,3);
}