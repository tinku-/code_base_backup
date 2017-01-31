#include <bits/stdc++.h>
using namespace std;

vector <int> random_n(int n,int max)
{
	srand (rand()*time(NULL) );
	vector <int> v;
	set <int> s;
	while(s.size() != n)
		s.insert(rand()%max);

	set <int> :: iterator it;
	for(it = s.begin();it != s.end();it++)
		v.push_back(*it);

	return v;
}
int forest_id3(int n)
{
	vector<int> rv = random_n(5,15);
	int count = 0 , ans = 0;
	for(int i=0;i<n;i++)
	{
		root = create_id3(root,rv);
		ans = test_ide3(test_row,root,rv);
		if(ans == 1)
			count++;

	}
	if(count >= n/2)
		return 1;
	else
		return 0;
}
int main()
{
	int t = 5;
	vector<int> v;

	while(t--){
		v = random_n(5,15);
		for(int i = 0;i != v.size();i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
}