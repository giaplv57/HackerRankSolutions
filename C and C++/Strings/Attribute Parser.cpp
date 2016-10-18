#include <cstdio>
#include <vector>
#include <iostream>
#include <utility> // For pair
#include <regex>
#include <string>

using namespace std;
const string tagNameExpression("<(.*?)[ |>]");
const string attibutesExpression(" (.*?) = \"(.*?)\"");

struct tag {
public:
    tag() {

    }

    string tagName;
    vector<pair<string, string> > attributes;
    vector<tag *> childrenTags;
    tag *parentTag;
};

class tagTree {
public:
    tag *root;
    tag *mostRecentTag;

    tagTree(tag *root, tag *mostRecentTag) {
        this->root = root;
        this->mostRecentTag = mostRecentTag;
    }

    void addTag(tag *newTag) {
        this->mostRecentTag->childrenTags.push_back(newTag);
        newTag->parentTag = this->mostRecentTag;
        this->mostRecentTag = newTag;
    }

    void closeTag() {
        if (this->mostRecentTag != this->root) {
            this->mostRecentTag = this->mostRecentTag->parentTag;
        }
    }

    string query(string query){
        smatch m;
        regex queryAttrRe("^(.*?)\\~(.*?)$");
        regex_search(query, m, queryAttrRe);
        if (m[2] == "") { //Can not find any attribute in the query
            return "Not Found!";
        } else {
            string queryAttr = m[2];
            stringstream ss;
            ss.str(m[1]);
            string token;
            tag *currentTag = this->root;
            vector<string> queryTags;
            while (getline(ss, token, '.')) {
                queryTags.push_back(token); //Get all tags in the query
            }
            bool changed = false;
            for (int i = 0; i < queryTags.size(); i++) {
                changed = false;
                for (auto child:currentTag->childrenTags) {
                    if (child->tagName == queryTags[i]) {
                        currentTag = child;
                        changed = true;
                        break;
                    }
                }
                if (changed == false) {
                    return "Not Found!";
                }
            }
            if (changed != false) {
                for (auto pair:currentTag->attributes) {
                    if (pair.first == queryAttr) {
                        return pair.second;
                    }
                }
            }
        }
        return "Not Found!";
    }
};

void regexForC(vector<pair<string, vector<string> > > *matchAndGroups, string str, string regexExpression,
               int groupAmount = 0) {
    regex exp(regexExpression);
    smatch res;
    // Find the number of group in regex expression if it's not being specified
    if (groupAmount == 0) {
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
        for (int i = 1; i <= groupAmount; i++) {
            (*matchAndGroups)[(*matchAndGroups).size() - 1].second.push_back(res[i]);
        }
        str = res.suffix();;
    }
}

void parse(string data, tag *currentTag) {
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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    cin >> N >> Q;
    string data;
    string query;
    cin.ignore();
    tag rootTag;
    rootTag.tagName = "Here is the root tag!";
    rootTag.parentTag = nullptr;
    tagTree tree(&rootTag, &rootTag);

    for (int i = 0; i < N; i++) {
        getline(cin, data);
        if (data[0] == '<' && data[1] != '/') {
            tag *newTag = new tag();
            parse(data, newTag);
            tree.addTag(newTag);
        } else {
            tree.closeTag();
        }
    }

    for (int i = 0; i < Q; i++) {
        getline(cin, query);
        cout << tree.query(query) << endl;
    }
    return 0;
}