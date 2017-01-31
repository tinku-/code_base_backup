#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	double n,ans=0;cin>>n;
	vector<long long int> v;
	for(int i=2;i<=n;++i)
		{for(int j=2;j<=n;++j){v.push_back(pow(i,j));}}
	sort(v.begin(),v.end());
	//sort( vec.begin(), vec.end() );
    v.erase( unique( v.begin(), v.end() ), v.end() );
	//for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	//for(int i=1;i<v.size();i++){if(v[i-1]==v[i])ans++;}
	cout<<"\n\n"<<v.size()-ans<<"\n\n";
	return 0;
}