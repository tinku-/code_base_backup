#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    clock_t t1,t2;
    t1=clock();
    long long int i=0,a=0,b=0;
    ifstream file("/home/ridam/cpp/pe/e22.txt");
    if (!file.is_open()){cout<<"error";return -1;}
    else cout<<"success reading file"<<"\n\n";
    vector<string> words;
    string token;
    while (getline(file, token, ','))
    {
        words.push_back(token);
    }
    sort(words.begin(), words.end());
    int rank=0;
    unsigned int ans=0;vector <string> v;
    /*//get total of each word and multiply with it's position
    for (int i=0;i<=words.size();i++)
    {
    	rank++;
    	string w(words[i].begin() + 1, words[i].end() - 1);
    	int value=0; 
        for(int j=0;j<w.size();j++){value=value+w[j]-64;}
        ans=ans+rank*value;
    }*/

    cout<<ans<<"\n\n";
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout<<diff<<endl;
    return 0;
}