#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "",a = "",b = "",temp;
	int t=0,x=0,y=0;
	cin>>s;
	int n = s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i] != ';' && s[i] != ',' && s[i] != '\0')
		{
			temp = temp + s[i];
		}
		else
		{
			//cout<<temp<<endl;	
			t = 0;
			for(int j=0;j<temp.size();j++)
			{  
				if(temp[j] == '0' || temp[j] == '1' || temp[j] == '2' || temp[j] == '3' || temp[j] == '4' || temp[j] == '5' || temp[j] == '6' || temp[j] == '7' || temp[j] == '8' || temp[j] == '9' )
				{
					t ++;//cout<<"M"<<endl;
				}
			}
			if(temp[0] == '0' && temp.size() != 1)
				t = 0;

			if(t == temp.size() && temp != "")
			{
				a = a + "," + temp;
				temp = "";
			}
			else
			{
				b = b + "," + temp;
				temp = "";
			}
		}
	}
	if(a == "")
		cout<<"-"<<endl;
	else
		{a[0] = '"';cout<<a<<"\""<<endl;}
	if(b == "")
		cout<<"-";
	else
		{b[0] = '"';cout<<b<<"\""<<endl;}
	return 0;
}
//aba,123;1a;0