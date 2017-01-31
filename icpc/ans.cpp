#include <bits/stdc++.h>
using namespace std;

int main(){
  int t,a,b,x,y;
  cin>>t;
  while(t--){
    cin>>a>>b>>x>>y;
    if(a==x && y>b)
      cout<<"up"<<endl;
    else if(a==x && y<b)
      cout<<"down"<<endl;
    else if(a<x && y==b)
      cout<<"right"<<endl;
    else if(a>x && y==b)
      cout<<"left"<<endl;
    else
      cout<<"sad"<<endl;
  }
  return 0;
}
