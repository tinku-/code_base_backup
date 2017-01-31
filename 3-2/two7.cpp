#include <stdio.h>
#include <math.h>
int digit = 0;
int lucky(long long int x)
{
    while(x)
    {
        if(x%10 != 1 && x%10 != 7 && x%10 != 9)
            return 0;
        x = x/10;
    }
    return 1;
}
long long int reverse(long long int x)
{
    long long int y=0;digit = 0;
    while(x)
    {
        y = y*10 + x%10;
        x = x/10;
        digit++;
    }
    return y;
}
int last(long long int x,long long int y)
{
    if(lucky(y) == 1)
    {
          if(x%10 == 1 || x%10 == 7 || x%10 == 9) 
             return 1;   
    }
  
    return 0;
}
long long int ans(long long int x)
{ 
    long long int sum = 0,l=x%10,i=0,y=x;
    x = reverse(x);
    for(i=1;i<digit;i++)
    {
        sum += pow(3,i);
        //cout<<pow(3,i)<<endl;
    }
    digit--;
    while(x)
    {
        if(x%10 == 9)
        {
            sum += 2*pow(3,digit);
            x = x/10;
            digit--;
        }
        else if(x%10 == 8)
        {
            sum += 2*pow(3,digit);
            return sum;
        }
        else if(x%10 == 7)
        {
            sum += pow(3,digit);
            x = x/10;
            digit--;
        }
        else if(x%10 > 1 && x%10 < 7)
        {
            sum += pow(3,digit);
            return sum;
        }else if(x%10 <= 1)
        {
            x = x/10;
            digit--;
        }

    }
    sum += last(l,y);
    return sum;
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    printf("%lld\n",ans(n));
    return 0;
}