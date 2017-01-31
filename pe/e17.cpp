#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector <string> v1;
	vector <string> v2;
	vector <string> v3;
	string s1[9]={"one","two","three","four","five","six","seven","eight","nine"};
	string s2[8]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	string s3[1]={"hundred"};
    string s4[1]={"and"};
    string s5[1]={"teneleventwelvethirteenfourteenfifteensixteenseventeeneighteennineteen"};    
    string s6[1]={"onethousand"};
    //for(int k=0;k<10;k++)
    {for(int i=0;i<9;i++)v1.push_back(s1[i]);
        v1.push_back(s5[0]);
        for(int i=0;i<8;i++){v1.push_back(s2[i]);for(int j=0;j<9;j++){v1.push_back(s2[i]);v1.push_back(s1[j]);}}
    }
    //v1.push_back(s3[0]);
    //for(int i=0;i<100;i++){v2.push_back(s1[i]);v2.push_back(s3[0]);}
    //for(int i=0;i<99;i++)v2.push_back(s4[0]);
   // v2.push_back(s6[0]);
    for(int i=0;i<v1.size();i++)cout<<v1[i];
    //for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";
    return 0;
}