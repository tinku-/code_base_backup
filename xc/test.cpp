#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	long long int k;
    clock_t t1,t2;
    t1=clock();
    for(int i=0;i<200000;i++)
    	for(int j=0;j<200000;j++)
    	{
    		k=i*j;
    	}
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cout<<seconds<<endl;
    return 0;    
}