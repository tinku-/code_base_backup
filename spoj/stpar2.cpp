#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>	
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
	for(;;){
		long long int n,x=1,p=0;cin>>n;
		if(n==0)return 0;
		std::vector<int> v1;
		for(int i=0;i<n;i++)
			{int a;cin>>a;v1.push_back(a);}
		bool flag=true;
		stack<int> s;s.push(0);
		vector<int> v2;int z=v1.size();
		for(int i=0;i<z;i++){
			if(v1[i]==x){
				v2.push_back(v1[i]);
				v1.erase(v1.begin()+i-1);
				x++;
				while(s.top()==x){
					v2.push_back(s.top());
					s.pop();
					x++;
				}
			}else {
				s.push(v1[i]);
			}	
		}z=s.size();
		for(int i=0;i<v2.size();i++){
			if(v2[i]!=i+1){flag=false;}
		}
		if(flag==true && v2.size()==n)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		for(int i=0;i<v2.size();i++){cout<<v2[i]<<" ";}cout<<endl;
		for(int i=0;i<z;i++){cout<<s.top()<<" ";s.pop();}cout<<endl;
	}return 0;
}