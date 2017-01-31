#include <iostream>
#include <ctime>
using namespace std;


int main()
{
    clock_t t1,t2;
    t1=clock();
    
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff<<endl;
    return 0;    
}