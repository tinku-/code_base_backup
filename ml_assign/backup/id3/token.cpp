#include <bits/stdc++.h>
using namespace std; 

#define fname "small_data.txt" //adult.data.txt small_data.txt
#define pb push_back

int continuous_index[15] = {1,0,1,0,1,0,0,0,0,0,1,1,1,0,0};
int no_attributes[15] = {2,8,2,16,2,7,14,6,5,2,2,2,2,41,2};
vector < vector < int > > encoded_input ;
vector < int > target_vector;
vector < int > mode_vector;

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
void mode(vector<int> temp)
{
    int mode_value = 0,c = 1,max_c = 0;
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size()-1;i++)
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
            c = 0;
        }
    }
    mode_vector.pb(mode_value);
}
void filling_missing_values()
{
    vector<int> temp;
    
    for(int i=0;i<14;i++)
    {
        temp.clear();
        for(int j=0;j<encoded_input.size();j++)
            temp.pb(encoded_input[j][i]);
        mode(temp);
    }
    cout<<endl;
    for(int i=0;i<mode_vector.size();i++)
    {
        cout<<mode_vector[i]<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i < encoded_input.size();i++)
    {
        for(int j = 0 ; j < encoded_input[i].size() ;j++)
        {
            //cout<<encoded_input[i].size()<<endl;
            if(encoded_input[i][j] == -1)
                {encoded_input[i][j] = mode_vector[j];}//cout<<j<<" "<<mode_vector[j]<<endl;}
        }
    }
}
void resolve_name(string s)
{
    vector <int > v ;
    //v.reserve(15); 

    char input[500];
    strcpy(input,s.c_str());

    string token; 
    token = strtok(input, ", ");

    if(token[0] == '?')
        v.pb(-1);
    else
        v.pb(atoi(token.c_str()));    

    for(int i = 1 ; i < 14 ; i++)
    {
        token = strtok(NULL,", "); 

        if(token[0] == '?')
            v.pb(-1);
        else
        {
            if(continuous_index[i]==1)
                v.pb(atoi(token.c_str()));
            else
            {
                for(int j=0; j< no_attributes[i] ; j++)
                    if(token.compare(attribute_list[i][j]) == 0)
                        {v.pb(j);break;}
            }
        }
    }

    if(s.at(s.size()-4)=='=')
        target_vector.pb(0);
    else
        target_vector.pb(1);  

    encoded_input.pb(v);
    return ; 
}

void readfile()
{
    ifstream raw ; 
    raw.open(fname,ifstream::in);
    char s[500]; 
    cout << 1 ;  
     
    while(raw.getline(s,500,'\n')!=0)
    {
        resolve_name(s);
    }
    raw.close();
    return ; 
}

int median(vector<int> &v)
{
    int n = v.size() / 2;
    nth_element(v.begin(), v.begin()+n, v.end());
    return v[n];
}
int main()
{
    readfile();

    for(int i = 0 ; i < encoded_input.size();i++)
    {
        for(int j = 0 ; j < encoded_input[i].size() ; j++)
        {
            cout << encoded_input[i][j] << " " ;
        }

        cout << target_vector[i];
        cout << endl ;
    }
    filling_missing_values();   
    cout<<endl<<encoded_input[4].size()<<endl;
    for(int i = 0 ; i < encoded_input.size();i++)
    {
        cout<<encoded_input[i].size()<<endl;
        for(int j = 0 ; j < encoded_input[i].size() ; j++)
        {
            cout << encoded_input[i][j] << " " ;
        }

        cout << target_vector[i];
        cout << endl ;
    }
    
    return 0 ; 
}


/*

    for(int i = 0 ; i < encoded_input.size();i++)
    {
        for(int j = 0 ; j < encoded_input[i].size() ; j++)
        {
            cout << encoded_input[i][j] << " " ;
        }

        cout << target_vector[i];
        cout << endl ;
    }


*/