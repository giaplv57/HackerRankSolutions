#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, tempNumber;
    vector<int> numbers;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tempNumber;
        numbers.push_back(tempNumber);
    }
    cin >> q;
    for (int i=0; i<q; i++){
        cin >> tempNumber;
        auto pos = lower_bound(numbers.begin(), numbers.end(), tempNumber);
        if (numbers[pos-numbers.begin()] == tempNumber) cout << "Yes" << " " << pos-numbers.begin() + 1 << endl;
        else cout << "No" << " " << pos-numbers.begin() + 1 << endl;
    }
    return 0;
}
