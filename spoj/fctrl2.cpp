#include <iostream>
#include <vector>
using namespace std;
int fctrl2(int a){
    std::vector<int> v;
    long long int temp=0,carry=0,b=0;b=a;
    while(a)
    {v.insert(v.begin(),a%10);a=a/10;}
    for(int j=b-1;j>0;j--)
    {   //cout<<j<<" ";
        for(int i=0;i<v.size();i++)
        {temp=v[v.size()-i-1]*j+carry;v[v.size()-i-1]=temp%10;carry=temp/10;}
        while(carry){v.insert(v.begin(),1,carry%10);carry=carry/10;}
    }
    for(int i=0;i<v.size();i++)cout<<v[i];
    cout<<"\n";
    
}
int main(){
    long long int t=0,a=0;cin>>t;
    for(int i=0;i<t;i++)
        {cin>>a;fctrl2(a);}
    return 0;
}