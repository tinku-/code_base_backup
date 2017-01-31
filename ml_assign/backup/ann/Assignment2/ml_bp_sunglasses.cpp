#include <bits/stdc++.h>
using namespace std;

#define I 960
#define H 3
#define O 2
#define alpha 0.3
#define eta 0.3
#define iterations 50000
#define training_set "train_sunglasses.txt"
#define testing_set "test_sunglasses2.txt"
#define feature_dict eyes_dict
#define feature eyes

double input[I] = {0};
double wh[H][I] = {0};
double wk[O][H] = {0};
double hidden[H] = {0};
double output[O] = {0};
double target[O] = {0};
double delh[H] = {0};
double delk[O] = {0};
double delwh1[H][I] = {0}; //1 is old delta 
double delwk1[O][H] = {0};
double delwh2[H][I] = {0}; //2 is new
double delwk2[O][H] = {0};

string name_dict[]={"an2i","at33", "boland", "bpm", "ch4f", "cheyer", "choon", "danieln", "glickman", "karyadi", "kawamura", "kk49", "megak", "mitchell", "night", "phoebe", "saavik", "steffi", "sz24", "tammo"};
string pose_dict[]={"straight", "up", "left", "right"};
string eyes_dict[]={"open","sunglasses"};


vector< vector < double > > target_vectors;
vector< vector < double > > input_vectors;

double sigmoid(double x)
{
	return (1.0/(1.0 + exp(-x)));
}

void random_initialize()
{
	for(int i=0;i<H;i++)
		for(int j=0;j<I;j++)
			wh[i][j] = -1 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(2)));
	for(int i=0;i<O;i++)
		for(int j=0;j<H;j++)
			wk[i][j] = -1 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/(2)));
	return ;
}

void forward_prop()
{
	double temp = 0.0;

	for(int i=0;i<H;i++)
	{
		temp = 0.0;
		for(int j=0;j<I;j++)
			temp += wh[i][j]*input[j];
		hidden[i] = sigmoid(temp);
	}
	
	for(int i=0;i<O;i++)
	{
		temp = 0.0;
		for(int j=0;j<H;j++)
				temp += wk[i][j]*hidden[j];
		output[i] = sigmoid(temp);
	}
		
}
void back_prop()
{
	//outer layer
	double sum=0;
	for(int k=0;k<O;k++)
		delk[k] = (target[k] - output[k])*output[k]*(1.0-output[k]);
	//inner layer
	for(int j=0;j<H;j++)
	{
		for(int k=0;k<O;k++)
			sum = delk[k]*wk[k][j];
		delh[j] = hidden[j]*(1.0-hidden[j])*sum;
	}

	//outer update ...
	for(int k=0;k<O;k++)
		for(int j=0;j<H;j++)
		{
			delwk2[k][j] = eta*delk[k]*hidden[j] + alpha*delwk1[k][j];
			delwk1[k][j] = delwk2[k][j];
			wk[k][j] += delwk2[k][j];
		}
	// hidden update ...
	for(int j=0;j<H;j++)
		for(int i=0;i<I;i++)
		{
			delwh2[j][i] = eta*delh[j]*input[i] + alpha*delwh1[j][i];
			delwh1[j][i] = delwh2[j][i];
			wh[j][i] += delwh2[j][i];
		}
}

void pgm_converter(string s,bool flag)
{
	double d;
	vector<double> v;
	v.reserve(I);
	int len = s.size(); 
	int cyx=0,i,j;
	int N, M, Q;		// N=Rows   M=Cols   Q=GreyLevels
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
			v.push_back(d/255.0);
			cyx++;
		}
	input_vectors.push_back(v);
	//cout << cyx << endl ;

	for(i=len-1;i>=0;i--)
	{
 		if(s[i]=='/')
 			break;
 	}
	i++;
	string name = "",dir = "",expression = "",eyes = ""; 
	while(s[i] != '_')
 		name+=s[i++];
	i++; 
 	while(s[i]!='_')
 	{
 		dir+=s[i++];
 	}
 	i++; 
 	while(s[i]!='_')
 	{
 		expression+=s[i++];
 	}
 	i++; 
 	while(s[i]!='_')
 	{
 		eyes+=s[i++];
 	}
 	i++; 
	vector< double > temp2;
	for(i=0;i<O;i++)
		temp2.push_back(0.1);
 	for(i=0;i<O;i++)
 	{
		
 		if(strcmp(feature_dict[i].c_str(),feature.c_str()) == 0)
 		{
 			temp2[i] = 0.9; 
 			target_vectors.push_back(temp2);
 			break;
 		}
	}
	temp2.clear();
	v.clear();
	if(flag == true)
		cout<<feature_dict[i];
	return ;
}

bool prediction(bool flag)
{
	forward_prop();
	double max = -99999.99;
	int max_index = 0;
	for(int i=0;i<O;i++)
	{
		if(output[i] > max)
		{
			max_index = i;
			max = output[i];
		}
	}
	if(flag == true)
	{
		cout<<feature_dict[max_index];
	}
	if(target[max_index] == 0.9)
		return true;
	else
		return false;
}

int main()
{
	int x = 0,temp1 = 0,temp2 = 0,correct = 0;
	string list;
	while(1)
	{
		cout<<"Press 1:Train\nPress 2:Test\nPress 3:To Quit\nPress 4:To Enjoy\n";
		cin>>x;
		if(x == 1)
		{
			cout<<"Input Training List\n";
			temp1 = 0;
			//cin>>list;
			list = training_set;
			char file_name[100];
			ifstream if1;
			if1.open(list.c_str(),ifstream::in);
			while(if1.getline(file_name,100,'\n') != 0)
			{
				pgm_converter(file_name,false);
				temp1++;
			}
			cout<<temp1<<endl;
			if1.close();

			random_initialize();
			for(int i=0;i<iterations;i++)
			{
				for(int j=0;j<I;j++)
					input[j] = input_vectors[i%input_vectors.size()][j];
				for(int j=0;j<O;j++)
					target[j] = target_vectors[i%target_vectors.size()][j];
				forward_prop();
				back_prop();
				if(i%400 == 0)
				{
					for(int j=0;j<O;j++)
						cout<<output[j]<<" ";
					cout<<endl;
				}
			}
			input_vectors.clear();
			target_vectors.clear();
			
		}
		else if(x == 2)
		{
			cout<<"Input Testing List\n";
			temp1 = 0;
			//cin>>list;
			list = testing_set;
			char file_name2[100];
			ifstream if2;
			if2.open(list.c_str(),ifstream::in);
			while(if2.getline(file_name2,100,'\n') != 0)
			{
				pgm_converter(file_name2,false);
				temp1++;
			}
			cout<<temp1<<endl;
			correct = 0;

			for(int i=0;i<temp1;i++)
			{
				for(int j=0;j<I;j++)
					input[j] = input_vectors[i][j];
				for(int j=0;j<O;j++)
					target[j] = target_vectors[i][j];
				if(prediction(false) == true)
				{
					correct++;
					cout<<"correct"<<endl;
				}
				else
					cout<<"incorrect"<<endl;
			}
			cout<<"Accuracy :"<<((double)correct/(double)(temp1))*100.0<<endl;
			input_vectors.clear();
			target_vectors.clear();
		}
		else if(x == 3)
			return 0;
		else if(x == 4)
		{
			input_vectors.clear();
			target_vectors.clear();
			cout<<endl;

			string str;
			cout<<"Input Image Name : ";
			cin>>str;
			cout<<"Target :";
			pgm_converter(str,true);
			
			str = "xdg-open " + str;
			const char* constant_char = str.c_str();
			system((const char*)constant_char);
			
			cout<<endl;
			cout<<"Prediction : ";
			for(int j=0;j<I;j++)
				input[j] = input_vectors[0][j];
			for(int j=0;j<O;j++)
				target[j] = target_vectors[0][j];
			forward_prop();
			prediction(true);
			cout<<endl;

			input_vectors.clear();
			target_vectors.clear();
			cout<<endl;
		}
		else
			cout<<"Invalid Choice\n";
	}
}	