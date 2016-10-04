#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    int **sequences = new int*[N];
    int numberAmount;
    for (int i = 0; i < N; i++){
        cin >> numberAmount;
        sequences[i] = new int[numberAmount];
        for (int j = 0; j < numberAmount; j++){
            cin >> sequences[i][j];
        }
    }
    int x, y;
    for (int i = 0; i < Q; i++){
        cin >> x >> y;
        cout << sequences[x][y] << endl;
    }
	return 0;
}
