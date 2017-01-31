#include <bits/stdc++.h>
using namespace std; 
#define fname "small_data.txt"
#define pb push_back
int india = 0;
int input_size;
int continuous_index[]={1,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0};
int no_attributes[15]={2,8,2,16,2,7,14,6,5,2,2,2,2,41,2};

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
    {">50K","<=50K"}
};
//0 0 40 1 1 0
//Black, Male, 0, 0, 40, United-States, <=50K

vector< vector< int > > encoded_input ;
vector<int > target_vector;
vector<int> temp;
vector<int> mode_vector;
vector<int> median_vector;

struct treenode{
	int attr; 
	int flag;
	vector< treenode* > attr_type;
};


void resolve_name(string s)
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
    		{v.pb(-1);}
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
	    			}
	    		}		
	    	}
    	}
	}

	if(s[j]=='>')
	{
		target_vector.pb(0);
	}	
	else
	{
		target_vector.pb(1);
	}


	encoded_input.pb(v);

	return ; 
}

void readfile()
{
	string s ; 
	ifstream f1;
	int i = 0; 
	f1.open("adult.data", ifstream::in);

	  while(getline(f1,s,'\n'))
	  { 
	  	resolve_name(s);
	  }
	  
	f1.close();
	return ; 
}

int cal_median(vector<int> &v)
{
    int n = v.size() /2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}


void mode_median(int index)
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

    mode_vector[index]=mode_value;
    median_vector[index]=temp[j + (input_size-j)/2];
    return ;
}


void missing_split()
{

	int i ; 
	int j ;

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
				encoded_input[j][i]=mode_vector[i];
			}
		}
	}



	return ; 
}

void initalize()
{
	temp.clear();
	mode_vector.clear();
	mode_vector.reserve(14);
	median_vector.clear();
	median_vector.reserve(14);
	input_size=encoded_input.size();
}

double calc_entropy(int pos , int neg)
{
	double E ; 

	if(pos==pos+neg)
	{
		return 0.0 ;
	}
	else if(neg==neg+pos)
	{
		return 0.0 ; 
	}
	else
	{
		double m = (double)pos/(double)(pos+neg);
		double n = (double)neg/(double)(pos+neg);
		m = m*(double)log(m)/(double)log(2);
		n = n*(double)log(n)/(double)log(2);
		E=-1*(m+n);
	}

	return E ;
}



treenode * create_id3(vector<int> indexes, vector<int> used_attributes)
{	
	for(int i=0;i<14;i++)
		cout << used_attributes[i] << " " ;
	if(india>250)
		return NULL; 

	cout << india++<<endl;
	treenode * root;
	root=new treenode;

	int i , j , k , l , m ;
	int count_usedattr=0;

	for(i=0;i<14;i++)
		if(used_attributes[i]==1)
			count_usedattr++;

	int nop=0;
	int non=0;
	double max_gain=-1.0;
	int max_en_attribute=0;

	vector< pair<int , int > > positive_negatives;
	vector< vector<int > > next_level;
	vector<int> temp;

	double total_gain = 0;
	double sum=0;
	int ff =0, ss=0 , tot=0; 


	for(i=0;i<indexes.size();i++)
	{
		if(target_vector[indexes[i]]==1)
			nop++;
		else
			non++;

	}
	cout << nop << " "<< non << endl;
	//cout<<indexes.size()<<endl;
	//cout<<nop<<" "<<non<<" "<<endl;

	if(non==0)
	{
		root->flag=1;
		root->attr=-1; 
		cout<<"all positive "<<max_en_attribute<<endl;
		return root ;
	}
	else if(nop==0)
	{
		root->flag=-1;
		root->attr=-1;
		cout<<"all negative "<<max_en_attribute<<endl;
		return root ;	
	}
	else
	{
		if(count_usedattr==14)
		{
			if(nop>non)
			{
				root->flag=1;
				return root;
			}	
			else
			{
				root->flag=-1;
				return root;
			}
			//cout<<"all 14 used "<<max_en_attribute<<endl;
		}
		else
		{


			total_gain = calc_entropy(nop,non);
			double temp1 = total_gain;
			
			//cout<<total_gain<<endl;
			//cout<<"max_en_attribute "<<max_en_attribute<<endl;
			
			for(i=0;i<14;i++)
			{
				if(used_attributes[i]==0)
				{
					sum=0;	
					positive_negatives.clear();
					for(k=0;k<no_attributes[i];k++)
					{
						positive_negatives.push_back(make_pair(0,0));
					}		

					for(j=0;j<indexes.size();j++)
					{
						if(target_vector[indexes[j]]==1)
						{
							positive_negatives[encoded_input[indexes[j]][i]].first++;
						}
						else
						{
							positive_negatives[encoded_input[indexes[j]][i]].second++;	
						}
					}

					total_gain = temp1;

					for(k=0;k<no_attributes[i];k++)
					{
						ff=positive_negatives[k].first;
						ss=positive_negatives[k].second;
						tot=ss+ff;

						total_gain-=((double)(tot)/(double)(nop+non))*calc_entropy(ff,ss);
					}
					cout<<"lolo "<<total_gain<<endl;
				}

				if(max_gain<total_gain)
				{
					max_gain=total_gain;
					max_en_attribute=i;
				}

			}
		//we have max en attri 

			for(l=0;l<no_attributes[max_en_attribute];l++)
			{
				next_level.pb(temp);
			}

			next_level.reserve(no_attributes[max_en_attribute]);
			for(i=0;i<indexes.size();i++)
			{
				next_level[encoded_input[indexes[i]][max_en_attribute]].pb(indexes[i]);
			}

			used_attributes[max_en_attribute]=1;
			root->attr=max_en_attribute;
			root->flag=0;
		
			for(int m=0;m<no_attributes[max_en_attribute];m++)
			{
				//used_attributes[max_en_attribute]=1;
				treenode * next=create_id3(next_level[m],used_attributes);
				(root->attr_type).push_back(next);

			}
			return root ;
			} 
		}

		return root ;

	
}

void control_continuous()
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


int main()
{
	readfile();
	initalize();
	missing_split();
	control_continuous();


	vector<int > used_attributes(14,0);
	vector<int> indexes;

	for(int i=0;i<input_size;i++)
		indexes.pb(i);

	treenode * root ; 
	


//	for(int i = 0 ; i < encoded_input.size();i++)
//	{
//		cout << "vector size " << encoded_input[i].size() << endl ;
//
//		for(int j = 0 ; j < encoded_input[i].size() ; j++)
////		{
//			cout << encoded_input[i][j] << " " ;
//		}
//
//		cout << "target : " << target_vector[i];
//		cout << endl ;
//	}

	cout << endl; 


	//cout<<calc_entropy(9,5)<<endl;
	//cout<<log(2);
	root = create_id3(indexes,used_attributes);

	return 0 ; 
}



/*


	for(int i=0;i<14;i++)
	{
		cout << mode_vector[i] << " " << median_vector[i] << endl;	
	}


*/