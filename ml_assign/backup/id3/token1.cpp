#include <bits/stdc++.h>
using namespace std;
vector<vector <int> > data;
vector<int> mode_vector;
int mode()
{
	int count[2000000] = {0};
	vector <int> temp;
	for(int i=0;i<temp.size();i++)
		count[temp[i]]++;
	mode_vector.pb(*max_element(count,count+2000000));

}
int main()
{
	//data_decoding();
}