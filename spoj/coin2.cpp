#include<bits/stdc++.h>  
 #include "iostream"  
 using namespace std;  
 map<long long,long long> dp;  
 long long coins(long long i)  
 {       
      if(i>=0 && i<12)  
      {  
           if(! dp[i])  
                dp[i] = i;  
           return dp[i];  
      }  
      else  
      {  
           if(! dp[i]){  
                dp[i] = coins(i/2)+coins(i/4)+coins(i/3);   
           }  
           return dp[i];  
      }  
 }  
 int main()  
 {  
      long long n;  
      while(cin>>n){  
           cout<<coins(n)<<endl;  
      }  
 }  