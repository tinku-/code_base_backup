#include <iostream>
#include <cmath>
using namespace std;
int prime(long long int a)
{
	bool flag=true;
	long long int b=pow(a,0.5);
	for(int i=2;i<=b;i++)
		{if(a%i==0){flag=false;return flag;}}
	return flag;
}
int main()
{
	long long int min,max;
	cin>>min>>max;
	if(min<2)min=2;
	for(int i=min;i<=max;i++)
		if(prime(i)==true)cout<<i<<"  ";
	return 0;
}
/*this is brute force approach for finding no of prime no
min and maxThe most basic method of checking the primality of a given integer n is called trial division. This routine consists of dividing n by each integer m that is greater than 1 and less than or equal to the square root of n. If the result of any of these divisions is an integer, then n is not a prime, otherwise it is a prime. Indeed, if n=a b is composite (with a and b ≠ 1) then one of the factors a or b is necessarily at most \sqrt{n}. For example, for  n = 37 , the trial divisions are by m = 2, 3, 4, 5, and 6. None of these numbers divides 37, so 37 is prime. This routine can be implemented more efficiently if a complete list of primes up to \sqrt{n} is known—then trial divisions need to be checked only for those m that are prime. For example, to check the primality of 37, only three divisions are necessary (m = 2, 3, and 5), given that 4 and 6 are composite.

While a simple method, trial division quickly becomes impractical 
for testing large integers because the number of possible factors 
grows too rapidly as n increases. According to the prime number 
theorem explained below, the number of prime numbers less than 
\sqrt{n} is approximately given by \sqrt{n} / \ln(\sqrt{n}), so 
the algorithm may need up to this number of trial divisions to check
 the primality of n. For n = 10^20, this number is 450 million—too
  large for many practical applications.

https://en.wikipedia.org/wiki/Prime_number */


