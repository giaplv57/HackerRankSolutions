#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> temp;
    stringstream ss;
    ss << str;
    int number; char tempChar;
    while (ss.rdbuf()->in_avail()!=0){
        ss >> number >> tempChar;
        temp.push_back(number);
    }
    return temp;
    
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}