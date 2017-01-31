#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t,n,x;
  cin>>t;
  while(t--){
    int zero=0, one=0;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>x;
      if (x==0) zero++;
      if (x==1) one++;
    }
    if((n-one-zero)<2)
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
  return 0;
}
 