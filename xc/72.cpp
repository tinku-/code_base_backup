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
	for(int i=0;i<72;i++)
		for(int j=i;j<72;j++)
			for(int k=j;k<72;k++)
				if(i*j*k==72)cout<<i<<" "<<j<<" "<<k<<"="<<i+j+k<<"\n";
	return 0;
}