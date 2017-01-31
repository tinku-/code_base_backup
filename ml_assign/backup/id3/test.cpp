#include <bits/stdc++.h>
using namespace std;

void create_attributes_map()
{
	map < string, int > attributes;
    attributes["age"]=2;
    attributes["workclass"]=8;
    attributes["fnlwgt"] = 2;
    attributes["education"] = 16;
    attributes["education-num"] = 2;
    attributes["marital-status"] = 7;
    attributes["occupation"] = 14;
    attributes["relationship"] = 6;
    attributes["race"] = 5;
    attributes["sex"] = 2;
    attributes["capital-gain"] = 2;
    attributes["capital-loss"] = 2;
    attributes["hours-per-week"] = 2;
    attributes["native-country"] = 41;

}
int test_id3(struct input_node test_row,noden* root)
{
	int index1 = 0;
	map < string , int > :: iterator it1;
	for(it1 = attribute.begin();it1 != attribute.end();it1++)
	{
		if(strcmp(it->first,root->attribute_name) == 0)
		{
			break;
		}
		index1++;
	}
	for(int i=0;i<it1->second;i++)
	{
		if(strcmp(root->children[i]->attribute_value,test_row.data[index1]) == 0)
		{
			if(root->children[i]->fclass == -1)
				return test_id3(test_row,root->children[i]->child_attribute_name);
			else
				return root->children[i]->fclass;
		}
	}
}