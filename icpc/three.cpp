#include <bits/stdc++.h>
using namespace std;
int printDivisors(int n)
{
	int n;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                binary_serch();
 
            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
}