#include <bits/stdc++.h>
using namespace std;
int main()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(0);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	vector<int> :: const_iterator it = max_element(v.begin(),v.end());;
	cout<<*it<<endl;
}