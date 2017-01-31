#include <bits/stdc++.h>
using namespace std; 
#define fname "adult.txt"
#define testfile "adult.data"
#define pb push_back

int input_size;
int continuous_index[15]={1,0,1,0,1,0,0,0,0,0,1,1,1,0,0};
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


vector< vector< int > > encoded_input ;
vector<int > target_vector;
vector<int> mode_vector;
vector<int> median_vector;
vector<int > temp;
//vector<int > test_output_vector;
struct treenode{
	int attr; 
	int flag;
	vector< treenode * > attr_type;
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
		target_vector.pb(1);
	}	
	else
	{
		target_vector.pb(0);
	}


	encoded_input.pb(v);
	v.clear();

	return ; 
}

void readfile()
{
	string s ; 
	ifstream f1;
	int i = 0; 
	f1.open(fname, ifstream::in);	
	  while(getline(f1,s,'\n'))
	  { 
	  	
	  	resolve_name(s);
	  }
	  
	f1.close();
	return ; 
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

void initalize()
{
	mode_vector.clear();
	mode_vector.reserve(14);
	median_vector.clear();
	median_vector.reserve(14);
	input_size=encoded_input.size();
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


double entropy(int pos, int neg)
{
    int total = pos + neg;  
    
    if(pos == 0 || neg == 0)
        return 0.0;
    double p1, p2;
    p1 = (1.0 * pos) / total, p2 = (1.0 * neg) / total;
    return -1.0 * (p1 * log2(p1) + p2 * log2(p2));
}


pair<double , int > info_gain(vector<int > indexes,double E , int attribute)
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


	//cout << " " << E << " " << attribute << " " << endl ;

	pair <double , int > rr =make_pair(E,attribute);
	return rr;

}

int n = 0  ; 


treenode * ID3(vector<int > indexes , vector<int > used_attr , int depth)
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

	for(i=0 ; i < indexes.size();i++)
	{
		if(target_vector[indexes[i]]==1)
			nop++;
		else
			non++;
	}

	if(nop==0)
	{
		root->flag=1;
		root->attr=-1;
	//	cout << "all pos" << endl;
		return root ; 
	}
	else if(non==0)
	{
		root->flag=1;
		root->attr=-1;
	//	cout << "all neg" << endl;
		return root ; 
	}
	else if(depth==0)
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
		double E=entropy(non,nop);

		for(i=0;i<14;i++)
		{
			if(used_attr[i]==0)
			{
				info_attr = info_gain(indexes,E,i);
			}

			if(info_attr.first>max_gain)
			{
				max_gain=info_attr.first;
				max_en_attr=info_attr.second;
			}
		}		

		//cout << max_en_attr << " " ;
		next_level.reserve(no_attributes[max_en_attr]);
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
			if(depth==0 || next_level[i].size()==0)
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
				treenode * tr = ID3(next_level[i],used_attr,depth-1);
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


int correct=0;
int wrong=0; 


void predict(vector<int > v,treenode * root , int ans)
{

	while(root->flag==0 )
	{
		root=root->attr_type[v[root->attr]];
	}


	if(root->flag==ans)
		{correct++;
			cout<<root->flag<<" "<<ans<< " yes";}
	else
		{wrong++;cout<<root->flag<<" "<<ans<< " no";}


//	cout << root->flag << " " << root->attr << " " << root->attr_type.size()<< endl;


	v.clear();


	return ; 
}


void resolve_op(treenode * root,string s)
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
    			if(continuous_index[k]==0)
    				v.pb(mode_vector[k]);
    			else
    				v.pb(median_vector[k]);
    		}
    	else
    	{
    		if(continuous_index[k]==1)
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
		//test_output_vector.pb(0);
		ans=-1;
		//cout<<-1<<" ";
	}	
	else
	{
		//test_output_vector.pb(1);
		ans=1;
		//cout<<-1<<" ";
	}


//	for(int i=0;i<14 ; i++)
//	{
//		cout << v[i] << " " ;
//	}

	cout << endl;
	predict(v,root,ans);
	//v.clear();

	return ; 
}



void test(treenode * root)
{
	string s ; 
	ifstream f2;

	f2.open(testfile, ifstream::in);	
	  int i = 0 ; 

	  getline(f2,s,'\n');

	  while(getline(f2,s,'\n'))
	  { 
	  	resolve_op(root , s);
	  	i++;
	  //	cout<<i;
	  }
	  
	//  cout << i;
	f2.close();
	 

	//cout << test_output_vector.size() << endl ;
return ;

}

int main()
{
	readfile();
	initalize();
	missing_split();
	control_continuous();

	int i;


	vector<int > used_attr ; 
	vector<int > indexes;

	for(i=0;i<input_size;i++)
	{indexes.pb(i);}

	for(i=0;i<14;i++)
	{used_attr.pb(0);}

	treenode * root =new treenode;
	root = ID3(indexes,used_attr,13);	

	cout << "tree crealted " << endl ;
	
	test(root);

	cout << correct << " " << wrong << endl;
	double accuracy = (double)(correct)/(double)(correct+wrong);
	accuracy*=100.0;

	cout << endl << accuracy;

	return 0 ; 
 
}

//	treenode * root = ID3(indexes,used_attr,13);
/*	for(i = 0 ; i < input_size ; i++)
	{
		for(int j = 0 ; j < 14 ; j++)
		{
			cout << encoded_input[i][j] << " " ;
		}
		cout << endl ;
	}

	cout << input_size ;
*/

/*
1. read files .... 
2. resolve names ....
3. input processing and missing values handling 
4. build tree
	a. see all pos
	b. see all neg
	c. i not.. max entropy gain attribute 

	d: once found that... calculate the final entropy gain : 	

4. process test data 
5. calcuate accuray 

.............

random forest later



*/