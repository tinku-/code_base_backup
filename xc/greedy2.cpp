#include <bits/stdc++.h>
using namespace std;
struct realm
{
	int x;
	int y;
}new_subjects[100010],current_subjects[100010];
bool myFunc(struct realm a,struct realm b)
{
	if(a.x<b.x)
		return true;
	else if(a.x==b.x && a.y<b.y)
		return true;
	else 
		return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,g,h;
		cin>>m>>n;
		assert(m>=1 && m<=100000);
		assert(n>=1 && n<=100000);
		for(int i=0;i<m;i++)
		{
			cin>>new_subjects[i].x>>new_subjects[i].y;
			assert(new_subjects[i].x>=1 && new_subjects[i].x<=10000);
			assert(new_subjects[i].y>=1 && new_subjects[i].y<=10000);	
		}
		for(int i=0;i<n;i++)
		{
			cin>>current_subjects[i].x>>current_subjects[i].y;
			assert(current_subjects[i].x>=1 && current_subjects[i].x<=10000);
			assert(current_subjects[i].y>=1 && current_subjects[i].y<=10000);		
		}
		cin>>g>>h;
		assert(g>=1 && g<=100000);
		assert(h>=1 && h<=100000);
		sort(new_subjects,new_subjects+m,myFunc);
		sort(current_subjects,current_subjects+n,myFunc);
		int i,j,good=0,great=0;
		for(i=0,j=0;i<m &&j<n;)
		{
			if(new_subjects[i].x==current_subjects[j].x)
			{
				if(new_subjects[i].x==current_subjects[j].x && new_subjects[i].y==current_subjects[j].y)
					great++;
				if(new_subjects[i].x==current_subjects[j].x)
					good++;
				j++;	
			}
			else if(new_subjects[i].x>current_subjects[j].x)
			{
				while(new_subjects[i].x>current_subjects[j].x)
					j++;
			}
			i++;
		}	
		if(g==good && h==great)
			cout<<"Great"<<endl;
		else if(g==good)
			cout<<"Good"<<endl;
		else
			cout<<":("<<endl;		
	}
	
	return(0);
}

//copied :P