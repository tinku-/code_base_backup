#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>
#include "porter2_stemmer.h"
#include <bits/stdc++.h>
#define k 10
using namespace std;
struct docIdScoreMap{
	int docId;
	double score;
};
bool myfunc(struct docIdScoreMap &lhs, struct docIdScoreMap &rhs){
	return lhs.score > rhs.score;
}
int main(int argc, char *argv[]){
	cout<<"run"<<endl;
	int numDocuments;
	map<string, vector<pair<int,double> > > termPostingListsMapping;
	map<int, pair<string, string> > docIdTitleMapping;
	map<string, int> termFrequencyMapping;
	unordered_map<int, int> docLength;
	boost::filesystem::path corpus(argv[1]);
    int assignDocId = 0;
    string title, fileName, token;
    for (boost::filesystem::directory_iterator itr(corpus); itr!=boost::filesystem::directory_iterator(); ++itr)
	{
    	title.clear();
    	termFrequencyMapping.clear();
        fileName = itr->path().string();
        if (boost::ends_with(fileName, ".txt")){
	        ifstream ifs(fileName);
	        getline(ifs, title);
	        string content((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	        docLength[assignDocId] = title.length() + content.length();
	        boost::tokenizer<> tok(title);
	        for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
	   			token = *beg;
	   			boost::algorithm::to_lower(token);
	   			Porter2Stemmer::stem(token);
	   			termFrequencyMapping[token]++;
	   		}
	   		boost::tokenizer<> tok_c(content);
	   		for(boost::tokenizer<>::iterator beg=tok_c.begin(); beg!=tok_c.end();++beg){
	       		token = *beg;
	       		boost::algorithm::to_lower(token);
	       		Porter2Stemmer::stem(token);
	       		termFrequencyMapping[token]++;
	   		}
	        docIdTitleMapping[assignDocId].first = title;
	        docIdTitleMapping[assignDocId].second = fileName;
	        for(map<string, int>::iterator it = termFrequencyMapping.begin(); it!= termFrequencyMapping.end(); it++){
	        	termPostingListsMapping[it->first].push_back(make_pair(assignDocId, (log10(1+ it->second))));
	        }    
	        assignDocId++;
	    }
    }
    numDocuments = assignDocId;
    struct docIdScoreMap scores[numDocuments];
    map<string, int> queryTermFreequency;
    while(1){
    	queryTermFreequency.clear();
		int flag = 0;
		cout << endl << "Enter the search query (or q to quit)" << endl << endl;
		string query;
		getline(cin, query);
		if(query == "q")
			return 1;
		for(int i=0; i<numDocuments; i++){
			scores[i].docId = i;
			scores[i].score = 0.0;
		}
		boost::tokenizer<> tok(query);
   		for(boost::tokenizer<>::iterator beg=tok.begin(); beg!=tok.end();++beg){
   			token = *beg;
   			boost::algorithm::to_lower(token);
   			Porter2Stemmer::stem(token);
   			queryTermFreequency[token]++;
   		}
   		for(map<string, int>::iterator it = queryTermFreequency.begin(); it!= queryTermFreequency.end(); it++){
   			int len = termPostingListsMapping[it->first].size();
   			for(int i=0; i < len; i++){
   				flag = 1;
   				scores[termPostingListsMapping[it->first][i].first].score += termPostingListsMapping[it->first][i].second * (log10(numDocuments/len)) * log10(1+it->second);
   			}
   		}
   		if(flag == 0){
   			cout << endl << "Sorry the query you entered does not match any of the document" << endl ;
   			continue;
   		}
   		for(int i=0; i<numDocuments; i++)
   			scores[i].score /= docLength[i];
   		sort(scores, scores+numDocuments, myfunc);
   		for(int i=0; i<k; i++){
   			cout << scores[i].docId << " -> " << docIdTitleMapping[scores[i].docId].first << " -> " << docIdTitleMapping[scores[i].docId].second << endl;
   		}
    }

    return 0;
}