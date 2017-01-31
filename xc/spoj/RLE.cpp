#include <iostream>
using namespace std;
int main()
{
	string A;
	while(cin>>A)
	{
		int spos=0,fpos=0;
		while(fpos<A.length())
		{
			for(fpos=spos;fpos<A.length();fpos++)
			{
				if(A[fpos]!=A[spos])
					break;
			}
			if(fpos-spos>3)
			{
				cout<<fpos-spos<<"!"<<A[spos];
			}
			else
			{
				for(int i=0;i<fpos-spos;i++)
					cout<<A[spos];
			}
			spos=fpos;
		}
		cout<<"\n";
	}
	return 0;
}