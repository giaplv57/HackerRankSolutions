#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, removePos, removeBegin, removeEnd;
    vector<int> numbers;
    cin >> n;
    int tempNumber;
    for (int i=0; i<n; i++){
        cin >> tempNumber;
        numbers.push_back(tempNumber);
    }
    cin >> removePos >> removeBegin >> removeEnd;
    numbers.erase(numbers.begin()+removePos-1);
    numbers.erase(numbers.begin()+removeBegin-1, numbers.begin()+removeEnd-1);
    cout << numbers.size() << endl;
    for (auto number:numbers){
        cout << number << " ";
    }
    return 0;
}
