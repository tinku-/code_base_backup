#include<bits/stdc++.h>
using namespace std; 


#define fname adult.data

struct input_node
{
	string data[15];
};


struct nodev;
struct noden;


typedef struct nodev
{
    noden* parent_noden;
    int attribute_value;
    int fclass; // 1 if it's a positive leaf node
                // 0 if it's a negative leaf node
                // -1 otherwise
    noden* child_attribute_name;
} nodev;

typedef struct noden
{
    nodev* parent_nodev;
    int attribute_name;
    int no_of_attribute;
    nodev* children[42];
} noden;

/* PRINT FUNCTION FOR THE TREE

void print_tree(noden* root)
{
	vector<nodev*> child;
	vector<noden*> root_vector;
	vector<noden*>::iterator root_vector_it;
	root_vector.push_back(root);
	cout<<"\nID3 DECISION TREE\n";
	while(!root_vector.empty())
	{
		for(root_vector_it=root_vector.begin(); root_vector_it!=root_vector.end();root_vector_it++)
		{
			cout<< root_vector_it->attribute_name<<"\t";
		}
		cout<<endl;
		for(root_vector_it=root_vector.begin(); root_vector_it!=root_vector.end();root_vector_it++)
		{
			for(int i=0;i<root_vector_it->no_of_attribute;i++)
			{
				cout<< root_vector_it-> children[i]->attribute_value << "\t";
				child.push_back(root_vector_it->children[i]);
			}
			for(int i=0;i<root->no_of_attribute;i++)
			{
				if(child[i]->child_attribute_name ==NULL)
				{
					if(child[i]->fclass ==1)
						cout<<">50K\t";
					else
						cout<<"<=50K\t";
					root_vector.erase(root_vector_it);
				}
				else
				{
					//replace(root_vector_it,child[i]->child_attribute_name);
					root_vector.erase(root_vector_it);
					root_vector.insert(root_vector_it, child[i]->child_attribute_name);
				}
			}
		}
	}
	return;
}

*/

noden* create_noden(nodev* pn, int an, int noa)
{
    noden* node = new noden;
    node->parent_nodev = pn;
    node->no_of_attribute = noa;  
    node->attribute_name = an;
    for(int i=0; i<node->no_of_attribute; i++)
        node->children[i] = NULL;
    return node;
}

nodev* create_nodev(noden* parent_node,int av,int fc)
{
    nodev* node = new nodev;
    node->parent_noden = parent_node;
    node->attribute_value = av;
    node->fclass = fc;
    node->child_attribute_name = NULL;
    return node;
}

struct input_node input[33001];
struct encoded_input_node
{
	int data[15];
}encoded_input[33001];

vector<int> median;
int cont_index[]={1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0};
int attributes[15]={2,8,2,16,2,7,14,6,5,2,2,2,2,41,2};

string attribute_list[][42] =
{
    {"age", "lta","gta"},
    {"workclass","Private", "Self-emp-not-inc", "Self-emp-inc", "Federal-gov", "Local-gov", "State-gov", "Without-pay", "Never-worked"},
    {"fnlwgt","lta","gta"},
    {"education","Bachelors", "Some-college", "11th", "HS-grad", "Prof-school", "Assoc-acdm", "Assoc-voc", "9th", "7th-8th", "12th", "Masters", "1st-4th", "10th", "Doctorate", "5th-6th", "Preschool"},
    {"education-num", "lta","gta"},
    {"marital-status", "Married-civ-spouse", "Divorced", "Never-married", "Separated", "Widowed", "Married-spouse-absent", "Married-AF-spouse"},
    {"occupation", "Tech-support", "Craft-repair", "Other-service","Sales", "Exec-managerial", "Prof-specialty", "Handlers-cleaners", "Machine-op-inspct", "Adm-clerical", "Farming-fishing", "Transport-moving", "Priv-house-serv", "Protective-serv", "Armed-Forces"},
    {"relationship","Wife", "Own-child", "Husband", "Not-in-family", "Other-relative", "Unmarried"},
    {"race", "White", "Asian-Pac-Islander", "Amer-Indian-Eskimo", "Other", "Black"},
    {"sex","Female", "Male"},
    {"capital-gain", "lta","gta"},
    {"capital-loss","lta","gta"},
    {"hours-per-week", "lta","gta"},
    {"native-country","United-States", "Cambodia", "England", "Puerto-Rico", "Canada", "Germany", "Outlying-US(Guam-USVI-etc)", "India", "Japan", "Greece", "South", "China", "Cuba", "Iran", "Honduras", "Philippines", "Italy", "Poland", "Jamaica", "Vietnam", "Mexico", "Portugal", "Ireland", "France", "Dominican-Republic", "Laos", "Ecuador", "Taiwan", "Haiti", "Columbia", "Hungary", "Guatemala", "Nicaragua", "Scotland", "Thailand", "Yugoslavia", "El-Salvador", "Trinadad&Tobago", "Peru", "Hong", "Holand-Netherlands"},
    {"sal","<=50K",">50K"}
};

void print_input(int r)
{
	cout<<"\n******INPUT DATA******"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<15;j++)
			cout<<input[i].data[j]<<" ";
		cout<<endl;
	}
}

void print_int_vector(vector<int> v)
{
	cout<<"\nCONTENTS of 1D:"<<endl;
	for(int i=0;i<v.size();i++)
		cout<<i<<" "<<v[i]<<"\t";
	cout<<endl;
} 

void calculate_median(int r)
{
    vector<int> v;
    int i; 
	for(int k=0;k<15;k++)
	{
		if(cont_index[k] == 1)
		{
			for(i=0;i<r;i++)
			{
//				cout<<atoi((input[i].data[k]).c_str())<<" ";
				v.push_back( atoi((input[i].data[k]).c_str()) );
			}
			sort(v.begin(),v.end());
/*
			for(i=0;i<v.size();i++)
			{
				cout << v[i] << " " << endl;
			}
*/
			median.push_back(v[(v.size()/2)-1]);
		}
		else
			median.push_back(-99);
		v.clear();
	}
}  

void input_encoding(int r)
{
	vector<int> used_attribute; 
	calculate_median(r);	
	
	cout<<"*****MEDIAN VECTOR*****"<<endl;
	for(int i=0; i<15;i++)
		cout<<median[i]<<" ";
	cout<<endl;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<r; j++)
		{
			if(cont_index[i]==0)
			{
				for(int k=0;k<attributes[i];k++)
				{
					if( strcmp( input[j].data[i].c_str(), attribute_list[i][k+1].c_str() ) == 0)
						{
							encoded_input[j].data[i] = k;
							break;
						}
				}
			}
			else
			{
				encoded_input[j].data[i] = atoi(input[j].data[i].c_str());
				if(encoded_input[j].data[i] < median[i])
					encoded_input[j].data[i] = 0;
				else
					encoded_input[j].data[i] = 1;
			}
		}
	}
	
}

void print_encoded_input(int r)
{
	cout<<endl<<"*****ENCODED INPUT*****"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<15;j++)
		{
			cout<<encoded_input[i].data[j]<<" ";
		}
		cout<<endl;
	}		
}

vector<string> find_most_common(int r)
{
    vector<string> most_common;
    vector<int> a;
	//sahi hai
    for(int i=0;i<15;i++)
    {
        int noa = attributes[i];
        int max=0,k=0;
        for(int k =0; k<noa; k++)
            a.push_back(0);
        for(int j=0;j<r;j++)
        {
            for(k =0; k<noa;k++)
                {
                    if( strcmp(attribute_list[i][k+1].c_str(), input[j].data[i].c_str()) == 0)
                        a[k]++;
                }
        }
        for(k=1;k<a.size();k++)
        {
            if(a[k]>a[max])
                max = k;
        }
        most_common.push_back(attribute_list[i][max+1]);
        a.clear();
    }
    
    return most_common;
}

void replace_most_common(int l)
{
	vector<string> most_common;
    most_common = find_most_common(l);

    for(int i =0;i<15;i++)
    {
        for(int k=0;k<l;k++)
        {
            if( strcmp ((input[k].data[i]).c_str(), "?") == 0)
            {
                input[k].data[i] = most_common[i];
            }
        }
    }
}

noden* create_branch_noden(noden* node)
{
    int j=1,k;
    for(k=0;k<4;k++)
    {
        if( node->attribute_name ==k)
        {
            break;
        }
    }
    for(j=0;j<attributes[k];j++)
        {
            node->children[j] = create_nodev(node,j,-1);
        }
    return node;
}

bool all_positives(nodev* node, vector<int> rows)
{
    int i;
    bool flag;
    for(i= 0; i<rows.size(); i++)
    {
        if( encoded_input[rows[i]].data[14] == 0 )
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    return flag;
}

bool all_negatives(nodev* node, vector<int> rows)
{
    int i;
    bool flag;
    for(i= 0; i<rows.size(); i++)
    {
        if( encoded_input[rows[i]].data[14] == 1 )
        {
            flag = 0;
            break;
        }
        else
            flag = 1;
    }
    return flag;
}

double calculate_entropy(vector<int> category)
{
	double no_of_positives = 0, no_of_negatives = 0;
//    cout<<"In calculate entropy, for the rows :";
//    print_int_vector(category);
 
    int i=0 , j=0;

    	for(j=0;j<category.size();j++)
        if( encoded_input[category[j]].data[14] == 1 )
            no_of_positives ++;
        else
            no_of_negatives ++;
// 	cout<<"no_of_positives = "<<no_of_positives<<", no_of_negatives = "<<no_of_negatives<<endl;

	double val1 = (no_of_positives) / (no_of_positives + no_of_negatives);
    double val2 = (no_of_negatives) / (no_of_positives + no_of_negatives);
    double e1;
    if( (val1 == 1) || (val2 == 1) || (category.size() == 0) )
    {
    	e1 = 0;
    }
    else
    	e1 = -(val1 * log2(val1)) -(val2 * log2(val2));
//  	cout<<"val1 = "<<val1<<",val2 = "<<val2<<", e1 = "<<e1<<endl;

	return e1 ;
}

pair<int,double> calculate_gain(vector<int> used_attribute, vector<int > rows)
{

	int i ,j,k , l  , m ;
	double no_of_negatives=0,no_of_positives=0; 
	double val1, val2, E;
	vector< vector<int > > category;
	vector < int > count_per_category;
	double entropy_per_attribute;
	map<int,double> gain;
	map<int,double> :: iterator gi,mi;
	pair<int,double> return_gain;
//	cout<<"In calculate gain, for the rows :";
//    print_int_vector(rows);
    
	for(i=0;i<rows.size();i++)
	{
		if( encoded_input[rows[i]].data[14] == 1 )
            no_of_positives ++;
        else
            no_of_negatives ++;
	}
	cout<<"nop="<<no_of_positives<<" non="<<no_of_negatives<<endl;
	
	if((no_of_positives == 0) && (no_of_negatives == 0))
	{
		return_gain.first = -99;
		return_gain.second = -99;
		return return_gain;
	}
	else
	{
		val1 = (no_of_positives) / (no_of_positives + no_of_negatives);
		val2 = (no_of_negatives) / (no_of_positives + no_of_negatives);
		E = -(val1 * log2(val1)) -(val2 * log2(val2));
		cout<<"val1="<<val1<<", val2="<<val2<<", Es = "<<E<<endl;

		for(i=0;i<14;i++)
		{
			if(used_attribute[i]==0)
			{
	//           		if(cont_index[i]==0)
	//				{
	//                	cout<<"i = "<<i<<endl;
		            	k = attributes[i];

						for(j=0;j<k;j++)
						{
							category.push_back(count_per_category);
						}
	//    				cout<<"ROWS";
	//					print_int_vector(rows);
						
	//    				cout<<"CATEGORY VECTOR:";
	//    				print_2d_int_vector(category);

						for(j=0;j<rows.size();j++)
						{
							for(l=0;l<attributes[i];l++)
							{
	//    						cout<<"j="<<j<<",l="<<l<<"encoded_input[rows["<<j<<"]].data["<<i<<"]="<<encoded_input[rows[j]].data[i];
	//    						cout<<", attribute_list["<<i<<"]["<<l+1<<"] = "<<attribute_list[i][l+1]<<endl; 
								if(encoded_input[rows[j]].data[i] == l)
									{
	//    								cout<<"Pushing row "<<j<<" for attribute value "<<encoded_input[rows[j]].data[i]<<" in category "<<l<<endl;
										category[l].push_back(rows[j]);
										break;
									}
							}
						}
	//    				cout<<"CATEGORY VECTOR:"<<endl;
	//    				print_2d_int_vector(category);

	//    			}
	/*   			
		       		else
		        	{		
		            	k=2;
						int median = 0;
						median = calculate_median(i,rows);

						for(j=0;j<k;j++)
						{
							category.push_back(count_per_category);
						}

						for(j=0;j<rows.size();j++)
						{
								if(encoded_input[rows[j]].data[i] > median)
									category[1].push_back(rows[j]);
								else
		   			            	category[0].push_back(rows[j]);
				       	}
				    }
	*/		        
		        	double den=0;
					double sum=0;
					for(int j=0;j<attributes[i];j++)
					{
	//    				cout<<"Category["<<j<<"]:"<<attribute_list[i][j+1];
	//    				print_int_vector(category[j]);
						entropy_per_attribute=calculate_entropy(category[j]);
	//    				cout<<"Entropy for "<<attribute_list[i][j+1]<<" = "<<entropy_per_attribute<<", Num = "<<category[j].size();
						den=den+category[j].size();
	//	   				cout<<", den = "<<den<<endl;
						sum+=(entropy_per_attribute*category[j].size());
					}
					sum=sum/den;
					gain[i] = E - sum;
					cout<<"gain for "<<attribute_list[i][0]<<" = "<<"Es - E"<<attribute_list[i][0]<<" = "<<E<<" - "<<sum<<" = "<<gain[i]<<endl;
					category.clear();
			}
		}

		mi = gain.begin();
		for (gi = gain.begin(); gi != gain.end(); gi++)
		{
		   	if(gi->second > mi->second)
		   	{
		   	    mi = gi;
		   	}
		}
		
		return_gain.first = mi->first;
		return_gain.second = mi->second;
		return return_gain;
	}
}

vector<int> row_calculation (nodev* n, vector<int> rows)
{
    vector<int> return_rows;
    for(int i = 0; i< rows.size(); i++)
    {
        if( encoded_input[rows[i]].data[n->parent_noden->attribute_name] != n->attribute_value)
            rows[i] = -99;
    }
    
    for(int k=0;k<rows.size();k++)
        {
        	if(rows[k] != -99)
        		return_rows.push_back(rows[k]);
        }
    return return_rows;
}

int uaf=13;
int flag_exit = 10;
noden* create_id3(noden* node, vector<int> used_attribute, pair<int,double> gain, vector<int> rows)
{
    uaf =13;

    flag_exit --;

    if(flag_exit < 0)
    	exit(0);

    for(int i=0;i<14;i++)
    	if(used_attribute[i]==1)
    		uaf--;
   	if(uaf<0)
   		exit(0);

    vector<int> parent_rows;
    parent_rows = rows;
	cout<<"Root node created for : "<<attribute_list[node->attribute_name][0]<<endl;
//    cout<<"PARENT ROWS FOR :"<<attribute_list[node->attribute_name][0];
//    print_int_vector(parent_rows);
	
	if(node->parent_nodev != NULL)
		cout<<"Parent of "<<attribute_list[node->attribute_name][0]<<" "<< node->parent_nodev->attribute_value<<endl;

    // CREATING THE NODE VALUE BRANCHES.
    node = create_branch_noden(node);
	noden* child_name_node;
        
    // NEXT ITERATION.
    for(int i=0;i<node->no_of_attribute;i++)
    {
        nodev* child = node->children[i];
        rows = row_calculation(child, parent_rows );
        cout<<"\nInside iteration "<<attribute_list[node->attribute_name][i+1]<<" for node = "<<attribute_list[node->attribute_name][0]<<endl;
        if ( all_positives((node->children[i]), rows ) )
        {
            node->children[i]->fclass = 1;
            cout<<"positive leaf node create for "<<attribute_list[node->attribute_name][node->children[i]->attribute_value + 1]<<endl;
        }
        else if ( all_negatives((node->children[i]), rows) )
        {
            node->children[i]->fclass = 0;
            cout<<"negative leaf node create for "<<attribute_list[node->attribute_name][node->children[i]->attribute_value + 1]<<endl;
        }
        else
        {
            gain = calculate_gain(used_attribute, rows);
            if(gain.second != -99)
            {
		        child->child_attribute_name = create_noden(child,gain.first,attributes[gain.first]);
		        used_attribute[gain.first] = 1;
	
		        child_name_node = create_id3(child->child_attribute_name,used_attribute,gain, rows);
		    }
        }
    }
    return node;
}

void resolve_name(string s,int index )
{
	int len =s.size();
	int j = 0 ;
	int i=0; 
	int k =0; 

	for(k=0;k<15;k++)
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

	//cout << temp << endl ;
	input[index].data[k]=temp;

	}
	return ; 
}


int readfromfile()
{
	string s ; 
	ifstream f1;
	int i = 0; 
	f1.open("/home/kinjal/Desktop/BM OS/ml/adult.data", ifstream::in);
	
	while(getline(f1,s,'\n'))
	{
	 	resolve_name(s,i++);
	}
	f1.close();
	return i; 
}

int main()
{	
	//read from file ;
	int l;
	l = readfromfile();
	int noa;
	cout<<"NO of lines read: "<<l<<endl;
    //replacing "?" with most common attribute value.

	replace_most_common(l);
	
	input_encoding(l);
//	print_encoded_input(l);
	

    //Creating ID3.
    noden* root;
    vector<int> rows;
    vector<int> used_attribute; 

    for(int i=0;i<l;i++)(rows.push_back(i));
    
    for(int i = 0; i<14;i++)
        used_attribute.push_back(0);
	pair<int,double> return_gain;
    return_gain = calculate_gain(used_attribute, rows);
    noa = attributes[return_gain.first];
    used_attribute[return_gain.first] = 1;
    root = create_noden(NULL,return_gain.first, noa);
    root = create_id3(root,used_attribute, return_gain,rows);

	return 0 ; 
}
//39, State-gov, 77516, Bachelors, 13, Never-married, Adm-clerical, Not-in-family, White, Male, 2174, 0, 40, United-States, <=50K

