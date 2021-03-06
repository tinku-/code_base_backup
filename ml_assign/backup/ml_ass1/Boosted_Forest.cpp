/*

Author Names :	Bhavya Mishra
				Manaswini Pandey
				Mohit Jain
				Ridam Jain
Dated : 11/11/2016
Boosted trees algorithm using Ada boosting 
*/

/*
.............

Ada Boosting algorithm : 

1. Create a random forest as before
2. create a scouting matrix with 1 being given for misclassification and 0 for classified
3. for selecting m superclassifiers from the pool, run the loop for m times,
	a. calculate the weight of the error and select the one with least error
	b. update the weights of all instances with incorrectly classified having higher weights
	c. go to step 3
4. calculate the accuracy 
Enjoy!
............
*/

#include <bits/stdc++.h>
using namespace std; 

#define fname "adult.data" // input file 
#define testfile "adult.txt" // output file : first line in the file is ignored 
#define pb push_back 
#define NOT 100 // Number of trees created in the forest
#define NOA 5 // number of attributes 
#define TREESIZE input_size/3 // number of items in a sample
#define NOSC 20 //number of super classifiers 

int input_size; // number of lines in the input file 
int continuous_index[15]={1,0,1,0,1,0,0,0,0,0,1,1,1,0,0}; // shows if the data is index or not 
int no_attributes[15]={2,8,2,16,2,7,14,6,5,2,2,2,2,41,2}; // number of values per attribute 

int correct=0;//number of correct
int wrong=0;  // number of wrong predictions


string attribute_list[][42] =
{
    {"age", "ltm","gtm"},
    {"workclass","Private", "Self-emp-not-inc", "Self-emp-inc", "Federal-gov", "Local-gov", "State-gov", "Without-pay", "Never-worked"},
    {"fnlwgt","ltm","gtm"},
    {"education","Bachelors", "Some-college", "11th", "HS-grad", "Prof-school", "Assoc-acdm", "Assoc-voc", "9th", "7th-8th", "12th", "Masters", "1st-4th", "10th", "Doctorate", "5th-6th", "Preschool"},
    {"education-num", "ltm","gtm"},
    {"marital-status", "Married-civ-spouse", "Divorced", "Never-married", "Separated", "Widowed", "Married-spouse-absent", "Married-AF-spouse"},
    {"occupation", "Tech-support", "Craft-repair", "Other-service","Sales", "Exec-managerial", "Prof-specialty", "Handlers-cleaners", "Machine-op-inspct", "Adm-clerical", "Farming-fishing", "Transport-moving", "Priv-house-serv", "Protective-serv", "Armed-Forces"},
    {"relationship","Wife", "Own-child", "Husband", "Not-in-family", "Other-relative", "Unmarried"},
    {"race", "White", "Asian-Pac-Islander", "Amer-Indian-Eskimo", "Other", "Black"},
    {"sex","Female", "Male"},
    {"capital-gain", "ltm","gtm"},
    {"capital-loss","ltm","gtm"},
    {"hours-per-week", "ltm","gtm"},
    {"native-country","United-States", "Cambodia", "England", "Puerto-Rico", "Canada", "Germany", "Outlying-US(Guam-USVI-etc)", "India", "Japan", "Greece", "South", "China", "Cuba", "Iran", "Honduras", "Philippines", "Italy", "Poland", "Jamaica", "Vietnam", "Mexico", "Portugal", "Ireland", "France", "Dominican-Republic", "Laos", "Ecuador", "Taiwan", "Haiti", "Columbia", "Hungary", "Guatemala", "Nicaragua", "Scotland", "Thailand", "Yugoslavia", "El-Salvador", "Trinadad&Tobago", "Peru", "Hong", "Holand-Netherlands"},
    {">50K","<=50K"}
}; // array containing the possible values of the attributes, the continuous values are labeled as less then median(ltm) and greater than median(gtm)

struct treenode{ // node of a decision tree

	int attr;  //attribute to be considered while checking for decision
	int flag; //tells what decision to take: if it is -1 or +1, returns negative or positive results respectively, but if 0, it shows that its not the leaf node and hence should look for another node
	vector< treenode * > attr_type; // pointers to the children trees : Not equal to NULL only if flag = o
};

vector< vector< int > > encoded_input ; //stores the input in the form of numbers with their values corresponging to their index in the in attribute_list array
vector<int > target_vector; //stores the target value per value of encoded input
vector<int> mode_vector; //calculates the modes of attributes
vector<int> median_vector; //calculates the median values of the vectors
vector<int > temp; // a temporary vector 
vector < treenode * > Roots;//stores forest , pointers to the roots

//boosting structures
vector<double > data_weights; //weights of the instances
vector<double> tree_weights; //weights per tree
vector<vector < int > > scouting; //scouting matrix as described in the algo
vector<treenode *> experts; // vector of expert classifier
vector< int > isSuper; // 1 if already selected as expert


void resolve_name(string s) //take input as string and encodes it, and saves it in the input array 
{
	int len =s.size();
	int j = 0 ;
	int i = 0; 
	int k =0; 

	vector<int> v;
	v.reserve(14);

	for(k=0;k<14;k++)
	{
	   string temp=""; 
	 
	   for(i=j;i<len;i++)
	   {
	      if(s[i]==',')
			 break;
		  temp=temp+s[i];
	   }
	   j=i;
	   j+=2;
		if(temp[0] == '?')
    		{v.pb(-1);}//all missing values are replaced with -1 
    	else
    	{
    		if(continuous_index[k]==1)
	    		{v.pb(atoi(temp.c_str()));}
	    	else
	    	{
	    		for(int j=0; j< no_attributes[k] ; j++)
	    		{
	    			if(temp.compare(attribute_list[k][j+1])==0)
	    			{
	    				v.pb(j); 
	    				break ; 
	    			} // compare each and every input string after tokenizing, with attribute list  
	    		}		
	    	}
    	}
	}

	if(s[j]=='>')
	{
		target_vector.pb(1); // stores the target vector per input , 1 for positive and 0 for negative
	}	
	else
	{
		target_vector.pb(-1);
	}


	encoded_input.pb(v);//pushes to the input vector 
	v.clear();

	return ; 
}

void readfile()//to read the file line by line and send the line to resolve name to solve further
{
	string s ; 
	ifstream f1;
	int i = 0; 
	f1.open(fname, ifstream::in);	
	//getline(f1,s,'\n');

	  while(getline(f1,s,'\n'))
	  { 
	  	
	  	resolve_name(s);
	  }
	  
	f1.close();
	return ; 
}

void mode_median(int index)//calculate mode and median per vector and stores as well 
{
	int mode_value = 0,c = 1,max_c = 0;
    int i=0,j=0; 

    sort(temp.begin(),temp.end());
    j=0;

    while(j<input_size && temp[j]==-1)
    {
    	j++;
    }

    for(i=j;i<input_size;i++)
    {
        if(temp[i] == temp[i+1])
            c++;
        else
        {
            if(c > max_c)
            {
                max_c = c;
                mode_value = temp[i];
            }
            c = 1;
        }
    }

    if(c > max_c)          
    {
        max_c = c;
        mode_value = temp[i];
    }

    mode_vector[index]=mode_value;//mode
    median_vector[index]=temp[j + (input_size-j)/2];//median
    return ;
}

void missing_split()//calculates the median per attribute by calling mode_median function 
{

	int i, j ; 

	for(i=0;i<14;i++)
	{
		temp.clear();

		for(j=0;j<input_size;j++)
		{
			temp.push_back(encoded_input[j][i]);
		}
		mode_median(i);
	}


	for(i=0;i<14;i++)
	{
		for(j=0;j<input_size;j++)
		{
			if(encoded_input[j][i]==-1)
			{
				if(continuous_index[i]==0)
				encoded_input[j][i]=mode_vector[i];
				else
				encoded_input[j][i]=median_vector[i];	
			}
		}
	}



	return ; 
}

void initalize() //to initalize vectors 
{
	mode_vector.clear();
	mode_vector.reserve(14);
	median_vector.clear();
	median_vector.reserve(14);
	input_size=encoded_input.size();
	Roots.assign(NOT,NULL);
}

void control_continuous()//replaces the missing values with mode in case of discrete values and median when continuous values
{
	for(int i=0;i<14;i++)
	{

		if(continuous_index[i]==1)
		{
			for(int k=0;k<input_size;k++)
			{
				if(encoded_input[k][i]>median_vector[i])
					encoded_input[k][i]=1;
				else
					encoded_input[k][i]=0;
			}
		}
	}
}

double entropy(int pos, int neg)//calculate the entroopy 
{
    int total = pos + neg;  
    
    if(pos == 0 || neg == 0)//if all positive or negative 
        return 0.0;
    double p1, p2;
    p1 = (1.0 * pos) / total, p2 = (1.0 * neg) / total;
    return -1.0 * (p1 * log2(p1) + p2 * log2(p2));
}

pair<double , int > info_gain(vector<int > indexes,double E , int attribute) //information gain per attribute , send the index as well as the gain with that attribute to the calling function
{
	int i ;
	int ff ,ss ; 

	vector< pair <int , int > > pos_neg;

	for(i=0;i<no_attributes[attribute];i++)
	{
		pos_neg.pb(make_pair(0,0));
	}

	for(i=0;i<indexes.size();i++)
	{
		if(target_vector[indexes[i]]==1)
		{
			pos_neg[encoded_input[i][attribute]].first+=1;
		}
		else
		{
			pos_neg[encoded_input[i][attribute]].second+=1;
		}
	}

	for(i=0;i<no_attributes[attribute];i++)
	{
		ff = pos_neg[i].first;
		ss = pos_neg[i].second;

		E-=((1.0 * (ff+ss))/(1.0 * indexes.size())) * entropy(ss,ff); 
	}

	pair <double , int > rr =make_pair(E,attribute);
	return rr;

}

vector<int > unique_random(int number,int max)
{
	//srand (rand()*time(NULL) );
	srand (rand()); 
	vector <int> indexes;
	set <int> s;
	set <int> :: iterator it;

	int i ;

	for(i=0;i<number;i++)
	{
		s.insert(rand()%max);
	}

	while(s.size() != number)
		s.insert(rand()%max);

	for(it = s.begin();it != s.end();it++)
		indexes.push_back(*it);
	return indexes;
}

treenode * ID3(vector<int > indexes , vector<int > used_attr , int depth)//create the tree ,recursively by taking 3 vectors in place , indexes to take care of what is the set of values that are needed to be considered among the whole dataset , used_attr contains the array of 0s and 1s where 1 is in the index of attribute that is already used and 0 otherwise. depth is the depth of the tree
{
	treenode * root = new treenode; 
	root->flag=0;

	int i , j , k , l , m;
	int nop=0,non=0;
	int index=0;
	double gain ; 
	pair <double  , int > info_attr; 
	vector< vector< int > > next_level;

	int max_en_attr=-1; 
	double max_gain = -999;

	set<int> next_attr; 
	//srand(time(0));
	srand(rand());
	int r ; //random variable 
	set<int > :: iterator it; 


	for(i=0 ; i < indexes.size();i++)
	{
		if(target_vector[indexes[i]]==1)
			nop++; // number of positive examples
		else
			non++; //number of negative examples
	}


	if(nop==0) //all neg's
	{
		root->flag=-1;
		root->attr=-1;
	//	cout << "all pos" << endl;
		return root ; 
	}
	else if(non==0) // all pos's
	{
		root->flag=1;
		root->attr=-1;
	//	cout << "all neg" << endl;
		return root ; 
	}
	else if(depth==0) // all attributes used :
	{
		if(nop>non)
		root->flag = 1;
		else
		root->flag=-1;
	//	cout << "depth reached" ; 
		return root; 
	}
	else
	{
		double E=entropy(non,nop);// entropy calculations

		while(next_attr.size()!=NOA)
		{
			r=rand()%14;
			if(used_attr[r]==0)
			{
				next_attr.insert(r);
			}
		}

		for(it=next_attr.begin();it!=next_attr.end();it++)
		{
			info_attr = info_gain(indexes,E,*it);

			if(info_attr.first>max_gain)
			{
				max_gain=info_attr.first; // maximum gain with the attribute 
				max_en_attr=info_attr.second; //attribute with max  information gain 
			}	
		}

		//cout << max_en_attr << " " ;
		next_level.reserve(no_attributes[max_en_attr]); 
		/* newly processed vector of vector used to segrigate the data into vectors as per the label of the attribute for example: if there are 10 values 3 correspondig for sunny, 3 for rainy and 4 for overcast, the next_level vector structure will be like this 
		vector 1 -> 3 values(sunny)
		vector 2 -> 3 values(rainy)
		vector 3 ->	4 values(overcast)*/

		used_attr[max_en_attr]=1;
		root->attr=max_en_attr;
		vector<int > temp;

		for(k = 0 ; k < no_attributes[max_en_attr];k++)
		{
			temp.clear();
			for(i=0;i<indexes.size();i++)
			{
				if(encoded_input[i][max_en_attr]==k)
					temp.pb(indexes[i]);

				//	next_level[encoded_input[indexes[i]][max_en_attr]].pb(indexes[i]);
			}

			next_level.pb(temp);
		}

		for(i=0;i<no_attributes[max_en_attr];i++)
		{
			if(depth==0 || next_level[i].size()==0)//in case if there are no values for a corresponding attribute : 
			{
				treenode * sub = new treenode;

				if(nop>non)
				{
					sub->attr=-1;
					sub->flag = 1 ;
				}
				else
				{
					sub->attr=-1;
					sub->flag = -1 ; 
				}

				root->attr_type.pb(sub); 
			}
			else
			{
				treenode * tr = ID3(next_level[i],used_attr,depth-1);//called ID3 for children nodes 
				root->attr_type.pb(tr);
			}	
		}

		next_level.clear();
		indexes.clear();
		used_attr.clear();

		return root ;

	}

	return root ;
}

int check(int instance , int tree) //used as a utility for scouting matrix, returns 1 if tree returns wrong answer else 0 
{
	int i ;
	treenode * root = Roots[tree];

	while(root->flag==0)
	{
		root=root->attr_type[encoded_input[instance][root->attr]];	
	}

	if(root->flag==target_vector[instance])
		return 0 ;
	else
		return 1; 

}

void scouting_matrix() //used to create the scouting matrix
{
	int i , j , k;
	temp.clear();

	int verdict;

	for(i=0;i<input_size;i++)
	{
		temp.clear();

		for(j=0;j<NOT;j++)
		{
			verdict = check(i,j);
			temp.pb(verdict);
		}
		scouting.pb(temp);
	}

	return ; 

}

pair<int , double> check_min_error() //check the tree with minimum error function and returns the ratio of correctly calculated and total calculated
{
	int i ,j ; 

	double tot_weight=0; 
	double temp_error=0;

	double error_weight=INT_MAX;
	int error_in;

	pair<int , double > ans; 

	for(i = 0;i<input_size ; i++)
	{
		tot_weight+=data_weights[i]; //calculating the total weight of the instances
	}

	for(int i = 0 ; i < NOT ; i++)
	{
		if(isSuper[i]==0)//donot select if it is already selected as the expert 
		{
			temp_error=0;

			for(j=0;j<input_size;j++)
			{
				temp_error+=((scouting[j][i])*data_weights[j]);//calculating the error function per tree
			}

			if(error_weight>temp_error)
			{
				error_weight=temp_error;
				error_in=i;
			}

		}
	}

	double em = error_weight/tot_weight;

	if(em==0)//in case of 0 em, weight will become infinity
		em=.000001;
	else if(em==1)
		em=1-.000001;

	ans=make_pair(error_in,em);
	return ans;
}

void Boost()// Ada boosting
{
	scouting_matrix();//scouting matrix created

	int i , m ;

	isSuper.assign(NOT,0);//initalizing all the trees as not expert
	data_weights.assign(input_size,1.0);//assigning all weights to 1
	tree_weights.assign(NOSC,0.0);
	experts.assign(NOSC,NULL);//no experts initially

	pair<int , double > new_tree;
	double in ; 
	double em ;


	for(m=0;m<NOSC;m++)
	{
		new_tree=check_min_error();

		in =new_tree.first;
		em=new_tree.second;

		//cout << in << " " << em << endl;
		isSuper[in]=1;
		experts[m]=Roots[in];
		tree_weights[m]=.5*log((1-em)/(em));

		for(i=0;i<input_size;i++)
		{
			if(scouting[i][in]==1)
			{
				data_weights[i]*=sqrt((1-em)/em);//updating weights
			}
			else
			{
				data_weights[i]*=sqrt((em+.1)/(1-(em+.1)));
			}
		}
	}
	return ;
}


void predict(vector<int > v,int ans)//to calculate the accuracy 
{
	int i ;
	treenode * root;

	double local=0;

	for(i=0;i<NOSC;i++)
	{
		root = experts[i];

		while(root->flag==0)
		{
			root=root->attr_type[v[root->attr]];
		}

		local+=(((double)(root->flag))*(tree_weights[i]));//total weights per test instances as per the linear combinnation 
	}

	if(local*double(ans)<0.0)//wrong predictions
	{
		wrong++;//cout << "wrong";
	}
	else
	{
		correct++; // correct prediction 
		//cout << "correct";
	}
	v.clear();
	return ; 
}


void resolve_op(string s)//to resolve the output , similar to the resolve_name function
{
	int len =s.size();
	int j = 0 ;
	int i = 0; 
	int k =0; 
	int random ; 

	vector<int> v;
	v.reserve(14);

	for(k=0;k<14;k++)
	{
	   string temp=""; 
	 
	   for(i=j;i<len;i++)
	   {
	      if(s[i]==',')
			 break;
		  temp=temp+s[i];
	   }
	   j=i;
	   j+=2;
		if(temp[0] == '?')
    		{//v.pb(no);
    			if(continuous_index[k]==0)//missing continuous is replaced with median and discrete data with mode
    				v.pb(mode_vector[k]);
    			else
    				v.pb(median_vector[k]);
    		}
    	else
    	{
    		if(continuous_index[k]==1)//median values normalized to greter than and less than average
	    		{random = atoi(temp.c_str());

	    			if(random>median_vector[k])
	    				v.pb(1);
	    			else
	    				v.pb(0);
	    		}
	    	else
	    	{
	    		for(int j=0; j< no_attributes[k] ; j++)
	    		{
	    			if(temp.compare(attribute_list[k][j+1])==0)
	    			{
	    				v.pb(j); 
	    				break ; 
	    			}
	    		}		
	    	}
    	}
	}

	int ans;
	if(s[j]=='>')
	{
		//test_output_vector.pb(1);
		ans=1;
	}	
	else
	{
		//test_output_vector.pb(0);
		ans=-1;
	}

	predict(v,ans);
	v.clear();
	//Roots.clear();
}


void test()//to test the input data by calling predict function for each line int he file , skips the first line as the input data doesnt contain the first line 
{
	string s ; 
	ifstream f2;

	f2.open(testfile, ifstream::in);	
	  int i = 0 ; 

	  getline(f2,s,'\n');

	  while(getline(f2,s,'\n'))
	  { 
	  	resolve_op(s);
	  	i++;
	  //	cout<<i;
	  }
	  
	//  cout << i;
	f2.close();

	//Roots.clear();
	//cout << test_output_vector.size() << endl ;
	return ;
}

void clear_resources()//to clear all the resources
{
	encoded_input.clear() ; 
	target_vector.clear(); 
	mode_vector.clear(); 
	median_vector.clear();
	temp.clear(); 
	Roots.clear();
	data_weights.clear();
 	tree_weights.clear();
	scouting.clear();
	experts.clear();
	isSuper.clear();
	return ;
}

int main(void)
{
	readfile();//read file
	initalize();//initalize the vectors 
	missing_split();//find mode and median and replaces them for the missing values
	control_continuous();//make data continuous

	int i , j , k ;
	int max = input_size;

	vector<int > used_attr ; //used vector to be sent
	vector<int > indexes; //indexes: initially from 0 to (inputsize - 1)
	used_attr.assign(14,0);

	for(i = 0 ; i<NOT;i++)
	{
		indexes.clear();
		indexes=unique_random(TREESIZE,input_size);

		Roots[i] = new treenode;
		Roots[i] = ID3(indexes,used_attr,NOA - 1);
		cout << i << "th tree created" << endl;	
	}

	cout << "Forest Ready\nAda Boosting . . ." <<endl;

	Boost();

	cout << endl << "Forest Boosted..\nTesting started..." << endl;

	test(); //testing the inputs
	cout  << endl ; 
	
	cout << correct << " " << wrong << endl; //printing the correct and wrong predictions 
	double accuracy = (double)(correct)/(double)(correct+wrong);
	accuracy*=100.0;

	cout << endl << accuracy << endl; //printing the accuracy 
	clear_resources();	

	return 0; 
}
