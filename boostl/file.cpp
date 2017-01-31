#include <boost/tokenizer.hpp>
#include <boost/filesystem.hpp>
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{

	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	string s = "Boost C++ Libraries";
	tokenizer tok{s};
    for(tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
    	cout<<*it<<endl;

    boost::filesystem::path p(argv[1]);
    //cout<<endl;
    cout<<p.native()<<endl;

    
    boost::filesystem::path path(argv[1]);
    boost::filesystem::recursive_directory_iterator itr(path);
	while (itr != boost::filesystem::recursive_directory_iterator())
	{
		string fileName = itr->path().string();
		cout<<fileName<<endl;
		itr++;
	}

	for (boost::filesystem::directory_iterator itrr(path); itrr!=boost::filesystem::directory_iterator(); ++itrr)
	{
    	cout << itrr->path().filename() << ' '; // display filename only
    	if (is_regular_file(itrr->status())) cout << " [" << file_size(itrr->path()) << ']';
    	cout << '\n';
}
}