#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int opn(string s){
	stack<char> stack;
	vector<char> v;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='(' && s[i]!='+' && s[i]!='-' && s[i]!='*' &&  s[i]!='/' && s[i]!='^' && s[i]!=')' ){v.push_back(s[i]);}
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' ||  s[i]=='/' || s[i]=='^' ){stack.push(s[i]);}
		if(s[i]==')'){v.push_back(stack.top());stack.pop();}
	}
	for(int i=0;i<v.size();i++)cout<<v[i];
}
int main(){
	string s;long long int t=0;cin>>t;
	while(t--){cin>>s;opn(s);cout<<"\n";}
	return 0;
}



/*
other solution..............



#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std;
int main ()
{
    int t;
    cin>>t;
    char str[1000];
    stack <char> s;
    while (t--) 
    {
        cin>>str;
        int len = strlen (str);

        for(int i=0;i<len;i++ ) 
        {
            if(isalpha(str[i])) //////////////////////////////////////////////////
                cout << str[i];
            else if(str[i] == ')' ) 
            {
                cout << s.top ();
                s.pop ();
            }

            else if (str[i] != '(' )
                s.push (str[i]);
        }

        cout << endl;
    }

    return 0;
}
*/