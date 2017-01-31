    #include <bits/stdc++.h>
    using namespace std;
    struct point
	{
		int x;
		int y;
		int dir;
	};
	int mod4(int a)
	{
		if(a%4 < 0)
			return (a%4 + 4);
		else
			return a%4;
	}
	int main()
	{
		struct point p;
		p.x = 0;
		p.y = 0;
		p.dir = 0;
		string s;cin>>s;
		int j;
		for(int i=0;i<4*s.size();i++)
		{
			j = i%s.size();
			if(s[j] == 'G')
			{
				if(p.dir == 0)//north
					p.y++;
				if(p.dir == 1)//east
					p.x++;
				if(p.dir == 2)//south
					p.y--;
				if(p.dir == 3)//west
					p.x--;
			}
			if(s[j] == 'L')
			{
				p.dir--;
				p.dir = mod4(p.dir);
			}
			if(s[j] == 'R')
			{
				p.dir++;
				p.dir = mod4(p.dir);
			}
			//cout<<p.x<<" "<<p.y<<" "<<p.dir<<endl;
		}
		if(p.x == 0 && p.y ==0 && p.dir == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;	
	}
