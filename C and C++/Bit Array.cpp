#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    unsigned int N, S, P, Q;
    cin >> N >> S >> P >> Q;
    unsigned int powNumber = pow(2,31);
    vector<bool> isAppear(powNumber);
    unsigned int newNumber = S % powNumber;
    isAppear[newNumber] = true;
    int numberAmount = 1;
    for (unsigned int i=1; i<= N-1; i++){
        newNumber = ((newNumber*P % powNumber)+Q) % powNumber;
        if (isAppear[newNumber]) break;
        numberAmount++;
        isAppear[newNumber] = true;
    }
    cout << numberAmount;
    return 0;
}
