#include <iostream>
#include <deque> 
using namespace std;
void printKMax(int arr[], int n, int k){
    deque<int> myDeque (k,0);
    for (int i=0; i<k; i++){
        while(!myDeque.empty() && arr[i]>=arr[myDeque.back()]){
            myDeque.pop_back();
        }
        myDeque.push_back(i);
    }
    for (int i=k; i<=n; i++){
        cout << arr[myDeque.front()] << " ";
        if (myDeque.front() == i-k){
            myDeque.pop_front();
        }
        while(!myDeque.empty() && arr[i]>=arr[myDeque.back()]){
            myDeque.pop_back();
        }
        myDeque.push_back(i);
    }
    cout << endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
