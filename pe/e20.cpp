#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long int n=0,a=0,i=0,temp=0,carry=0;char c;
	vector <int> v;cin>>n;
	for(int i=0; i<n;i++){cin>>c;v.push_back(c-'0');}
    while(n--){a=a*10+(v[i]);i++;}cout<<a<<"\n\n";
    for(int j=a-1;j>0;j--)
    {   cout<<j<<" ";
    	for(int i=0;i<v.size();i++)
    	{temp=v[v.size()-i-1]*j+carry;v[v.size()-i-1]=temp%10;carry=temp/10;}
        while(carry){v.insert(v.begin(),1,carry%10);carry=carry/10;}
    }
    cout<<"\n\n";
    for(int i=0;i<v.size();i++)cout<<v[i];
    cout<<"\n\n";
    return 0;
}