#include <bits/stdc++.h>
using namespace std;

#define R 70
#define C 60
#define smoothing_constant 1
#define train_size 451
#define training_file "facedatatrain"
#define training_label_file "facedatatrainlabels"
#define test_size 150
#define testing_file "facedatatest"
#define testing_label_file "facedatatestlabels"

double Pyes_train = 0;
double Pno_train  = 0;
double Pyes_test  = 0;
double Pno_test   = 0;
double yes_train  = 0;
double no_train   = 0;
double yes_test   = 0;
double no_test    = 0;
double train_input[train_size][R][C] = {0};
double test_input[test_size][R][C] = {0};
double train_target[train_size] = {0};
double test_target[test_size] = {0};
double test_output[test_size] = {0};
double P1yes[R][C] = {0};
double P1no[R][C]  = {0};
double P0yes[R][C] = {0};
double P0no[R][C]  = {0};
int true_positive  = 0;
int true_negative  = 0;
int false_positive = 0;
int false_negative = 0;
int corr = 0;

void initialize_probablities() //for smoothing
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			P1yes[i][j] = smoothing_constant;
			P1no[i][j]  = smoothing_constant;
			P0yes[i][j] = smoothing_constant;
			P0no[i][j]  = smoothing_constant;
		}
}

void normalize_probablities() //normalizing probablities
{
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		{
			P1yes[i][j] /= yes_train;
			P1no[i][j]  /= no_train;
			P0yes[i][j] /= yes_train;
			P0no[i][j]  /= no_train;
		}
}

void read_input_file(string file1,string file2,int flag)
{
	//this function opens and read files 1 and 2 as string and convert it into integer data
	int temp = 0;
	int k = 0;
	string str;
	if(flag == 0) //training
	{
		ifstream if1(file1.c_str()); //file1 corresponds to train data file
    	k = 0; 
    	while (getline(if1, str))
    	{
        	for(int i=0;i<str.size();i++)
        	{
        		if(str[i] == '#')
        			train_input[k/R][k%R][i] = 1;
        	}
        	k++;
    	}
    	cout<<"# trainfile lines "<<k<<endl;
    	if1.close();

    	ifstream if2(file2.c_str()); // file2 corresponds to train data labels file
    	k = 0; 
    	while (getline(if2, str))
    	{
        	if(str[0] == '1')
        		train_target[k] = 1;
        	k++;
    	}
    	cout<<"# train lines "<<k<<endl;
    	if2.close();	
	}
	else //testing
	{
		ifstream if3(file1.c_str()); //file 1 corresponds to test data file 
    	k = 0; 
    	while (getline(if3, str))
    	{
        	for(int i=0;i<str.size();i++)
        	{
        		if(str[i] == '#')
        			test_input[k/R][k%R][i] = 1;
        	}
        	k++;
    	}
    	cout<<"# testfile lines "<<k<<endl;
    	if3.close();

    	ifstream if4(file2.c_str()); //file 2 corresponds to test data file label 
    	k = 0; 
    	while (getline(if4, str))
    	{
        	if(str[0] == '1')
        		test_target[k] = 1;
        	k++;
    	}
    	cout<<"# test lines "<<k<<endl;
    	if4.close();	
	}
}

void train()
{
	//this function update the probablities to learn from data
	yes_train = 0;
	no_train  = 0;
	yes_test  = 0;
	no_test   = 0;
	for(int i=0;i<train_size;i++)
		yes_train += train_target[i];
	no_train = train_size - yes_train;
	for(int i=0;i<test_size;i++)
		yes_test += test_target[i];
	no_test = test_size - yes_test;

	Pyes_train = yes_train/train_size;
	Pno_train  = no_train/train_size;
	Pyes_test  = yes_test/test_size;
	Pno_test   = no_test/test_size;
	//cout<<Pyes_train<<" "<<Pno_train<<" "<<Pyes_test<<" "<<Pno_test<<endl; 
	
	initialize_probablities();

	for(int k=0;k<train_size;k++)
	{
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(train_input[k][i][j] == 1 && train_target[k] == 1)
					P1yes[i][j]++;
				else if(train_input[k][i][j] == 1 && train_target[k] == 0)
					P1no[i][j]++;
				else if(train_input[k][i][j] == 0 && train_target[k] == 1)
					P0yes[i][j]++;
				else
					P0no[i][j]++;
			}
		}
	}

	normalize_probablities();
}

void test()
{
	double Y;
	double N;
	for(int k=0;k<test_size;k++)
	{
		Y = log(Pyes_train);
		N = log(Pno_train);
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				if(test_input[k][i][j] == 0)
				{
					Y += log(P0yes[i][j]);
					N += log(P0no[i][j]);
				}
				else 
				{
					Y += log(P1yes[i][j]);
					N += log(P1no[i][j]);
				}
			}
		}
		if(Y > N)
			test_output[k] = 1;
		else
			test_output[k] = 0;
	}
}

void analyze()
{
	//prints the confusion matrix and calculate the accuracy.
	true_positive  = 0;
	true_negative  = 0;
	false_positive = 0;
 	false_negative = 0;
	corr = 0;
	for (int i=0;i<test_size;i++)
	{
		if(test_output[i] == test_target[i])
		{
			corr++;
			cout<<i+1<<": correct"<<endl;
			if(test_output[i] == 1)
				true_positive++;
			else
				true_negative++;
		}
		else
		{
			cout<<i+1<<": incorrect"<<endl;
			if(test_output[i] == 1)
				false_positive++;
			else
				false_negative++;
		}
			
	}
	cout<<endl;
	cout<<endl;
	double accuracy = ((double)corr/(double)test_size)*100.0;
	cout<<"accuracy :"<<accuracy<<"%"<<endl<<endl;
	cout<<"correct predictions:"<<corr<<" "<<"out of :"<<test_size<<endl<<endl;
	cout<<"confusion matrix ........"<<endl<<endl;
	cout<<"true_positive  : "<<true_positive<<"    "<<"false_positive : "<<false_positive<<endl;
	cout<<"false_negative : "<<false_negative<<"    "<<" true_negative  : "<<true_negative<<endl;
	cout<<endl;
	cout<<endl;
}

int main()
{	
	//driver function
	int x;
	initialize_probablities();
	read_input_file(training_file,training_label_file,0);
	read_input_file(testing_file,testing_label_file,1);
	/*
	while(1)
	{
		cout<<"press 1 :to train\npress 2 :to test\npress 3 :exit\n";
		cin>>x;
		if(x == 1)
			train();
		else if(x == 2)
		{
			test();
			analyze();
		}
		else if(x == 3)
			return 0;
		else
			cout<<"invalid option\n";
	}
	*/
	train();
	test();
	analyze();
	//*/
	return 0;	
}
