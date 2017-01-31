#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int edges,nodes,x,y,ans=0;
	cin>>nodes>>edges;
	vector<int> adj[10001];
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[y].push_back(x);
		//adj[y].push_back(x);
	}
	for(int i=1;i<=nodes;i++)
	{
		if(adj[i].size() == 0)
		{
			//cout<<i<<": "<<ans<<endl;
			ans++;
		}
	}
	cout<<nodes - ans;

}

