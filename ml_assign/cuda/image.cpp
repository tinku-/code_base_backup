#include <bits/stdc++.h>
using namespace std;
#define I 960
vector< vector <int> > input_vectors;
void calculate(string s)
{
	char d;
	vector<int> v;
	v.reserve(I);
	int cyx=0,i,j;
	int N, M, Q;		// N=Rows   M=Cols   Q=GreyLevels
	cout << "INPUT image file: ? ";
						//	ReadImage
	ifstream ifp;
	ifp.open(s.c_str(), ios::binary);
	char header [100], *ptr;
	if (!ifp)
	{
		cout << "Can't read image: <" << s << '>' << endl;
		//getch();
		exit(1);
	}
	ifp.getline(header,100,'\n');
	if((header[0]!='P') || header[1]!='5')   // 'P5' Forma 
	{
		cout << "Image <" << s << "> is not in binary PGM 'P5' format." << endl;
		//getch();
		exit(1);
	}
	ifp.getline(header,100,'\n');
		while(header[0]=='#')
		ifp.getline(header,100,'\n');

	M=strtol(header,&ptr,0);
	N=atoi(ptr);
	ifp.getline(header,100,'\n');
	Q=strtol(header,&ptr,0);
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
		{
			d = ifp.get();

			v[cyx++]=d;
			//cout << (long)d << endl;
		}
	input_vectors.push_back(v);
	cout << cyx << endl ;

	return ;
}

int main()
{

	int a = 0;
	string list;
	cin>>list;
	char file_name[100];
	ifstream if1;
	if1.open(list.c_str(),ifstream::in);
	while(if1.getline(file_name,100,'\n') != 0)
	{
		calculate(file_name);
		a++;
	}cout<<a<<endl;
}