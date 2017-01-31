#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	clock_t t1,t2;
    t1=clock();
	double a=0,u=0,p=0;
	cin>>a>>u>>p;//stock price<<up move coefficient<<period
	vector <double> v;v.push_back(a);vector <double> w;
	double d=1/u;
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<i;j++) 
		{if(j==0){w.push_back(v[0]*u);w.push_back(v[0]*d);}
	     else {w.push_back(v[j]*d);}}
		cout<<"\n"<<"round:"<<i<<"\n";
		for(int j=0;j<w.size();j++)cout<<fixed<<setprecision(2)<<w[j]<<" ";
		v.clear();
	    for(int j=0;j<w.size();j++)v.push_back(w[j]);
	    w.clear();
	}
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<"\n\n"<<diff<<endl;
    //system ("pause");
    return 0;
}