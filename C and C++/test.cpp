#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map<string,int> students;
    int q;
    cin >> q;
    int queryType;
    string name, mark;
    for (int i=0; i<q; i++){
        cin >> queryType >> name;
        switch(queryType){
            case 1:
                cin >> mark;
                students.insert(make_pair(name, mark));
            case 2:
                students[name] = 0;
            case 3:
                cout << students[name] << endl;
        }
    }
    return 0;
}
