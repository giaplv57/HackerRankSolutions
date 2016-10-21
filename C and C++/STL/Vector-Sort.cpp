#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    vector<int> numbers;
    cin >> n;
    int tempNumber = 0;
    for (int i=0; i<n; i++){
        cin >> tempNumber;
        numbers.push_back(tempNumber);
    }
    sort(numbers.begin(), numbers.end());
    for (int i=0; i<n; i++){
        cout << numbers.at(i) << " ";
    }
    return 0;
}
