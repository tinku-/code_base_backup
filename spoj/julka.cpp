#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
using namespace std;
int longby2(vector<int>& a){
	long long int carry=0,p=0,temp=0;std::vector<int> v;
	for(int i=0;i<a.size();i++)
		{
			a[i]=carry*10+a[i];
			temp=a[i]/2;v.push_back(temp);carry=a[i]%2;
		}
		for(int i=0;i<v.size();i++)if(v[i]>0 || p!=0){cout<<v[i];p++;}
		if(p==0){cout<<0;}
	return 0;
}
int longadd(vector<int>& a,vector<int>& b){
	long long int temp=0,carry=0;
	for(int i=0;i<b.size();i++){temp=carry+a[a.size()-1-i]+b[b.size()-1-i];a[a.size()-1-i]=temp%10;carry=temp/10;}
	for(int i=(a.size()-b.size()-1);i>=0;i--){temp=a[i]+carry;a[i]=temp%10;carry=temp/10;}
	while(carry){a.insert(a.begin(),carry%10);carry=carry/10;}
	longby2(a);
	return 0;
}
int longsub(vector<int>& a,vector<int>& b){
	long long int temp=b.size();
	for(int i=0;i<(a.size()-temp);i++){b.insert(b.begin(),0);}
	for(int i=0;i<a.size();i++){
		if(a[a.size()-1-i]>=b[b.size()-1-i]){a[a.size()-1-i]=a[a.size()-1-i]-b[b.size()-1-i];}
		else {a[a.size()-1-i]=(10+a[a.size()-1-i]-b[b.size()-1-i]);a[a.size()-2-i]=a[a.size()-2-i]-1;}

	}
	longby2(a);
	return 0;
}

int main(){
	for(int i=0;i<10;i++)
	{
		string s1,s2;
		vector<int> a,b,c,d,e;cin>>s1>>s2;
		for(int i=0;i<s1.size();i++)
		{a.push_back(s1[i]-'0');c.push_back(s1[i]-'0');e.push_back(0);}
		for(int i=0;i<s2.size();i++)
		{b.push_back(s2[i]-'0');d.push_back(s2[i]-'0');}
		longadd(a,b);cout<<"\n";
		longsub(c,d);cout<<"\n";
	}
	return 0;
}


