#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility> // For pair
#include <regex>
#include <string>
using namespace std;
const string tagNameExpression("<(.*?) ");
const string attibutesExpression(" (.*?) = \"(.*?)\"");

struct tag{
	public:
		string tagName;
		vector<pair<string, string> > attributes;
		vector<tag*> childrenTags;
		tag* parentTag;
};

class tagTree{
	public:
		tag* root;
		tag* mostRecentTag;
		tagTree(tag* root, tag* mostRecentTag){
			this->root = root;
			this->mostRecentTag = mostRecentTag;
		}
		void addTag(tag* newTag){
			this->mostRecentTag->childrenTags.push_back(newTag);
			newTag->parentTag = this->mostRecentTag;
			this->mostRecentTag = newTag;
		}
};

void regexForC(vector<pair<string, vector<string> > >* matchAndGroups, string str, string regexExpression, int groupAmount = 0){
	regex exp(regexExpression);
	smatch res;
	// Find the number of group in regex expression if it's not being specified
	if (groupAmount == 0){
		regex groupMatchRe("[(].*?[)]");
		string tmpRegexExpression = regexExpression;
		while (regex_search(tmpRegexExpression, res, groupMatchRe)) {
	        groupAmount++;
	        tmpRegexExpression = res.suffix();;
	    }
    }
    // Find all the matches result together with corresponding groups
    while (regex_search(str, res, exp)) {
    	vector<string> groupsVector;
    	(*matchAndGroups).push_back(make_pair(res[0], groupsVector));
        for (int i = 1; i <= groupAmount; i++){
        	(*matchAndGroups)[(*matchAndGroups).size() - 1].second.push_back(res[i]);
        }
        str = res.suffix();;
    }
}

void parse(string data, tag* currentTag){
	smatch m;
	regex tagNameRe(tagNameExpression);
	regex_search(data, m, tagNameRe);
	currentTag->tagName = m[1];
	vector<pair<string, vector<string> > > attributes;
	regexForC(&attributes, data, attibutesExpression, 2);
	for (const auto &p : attributes) {
	    currentTag->attributes.push_back(make_pair(p.second.at(0), p.second.at(1)));
	}
}

int main() {
	// tag* node = new tag();
	// string data = "<tag4 name = \"Name4\" text = \"Super\" val123 = \"122\"><tlk >";
	// parse(data, node);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N, Q;
	cin >> N >> Q;
	string data;
	getline(cin, data);
	tag rootTag;
	parse(data, &rootTag);
	tagTree tree(&rootTag, &rootTag);

	for (int i = 0; i < N-1; i++){

		getline(cin, data);
//		cout << data << endl;
		if (data[0] == '<' && data[1] != '/'){
			tag newTag;
			parse(data, &newTag);
			tree.addTag(&newTag);
		}else{
			//close tag
		}
	}
    return 0;
}
//-std=c++0x