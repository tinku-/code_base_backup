#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
using namespace std;
int max(int i,int j){
	if(i>j)
		return i;
	return j;
}
int main()
{
	int sum = -100;
	int arr[6][6];
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++){
			cin>>arr[i][j];
		}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			sum = max(sum,(arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]));
		}
	cout<<sum;
	return 0;
}