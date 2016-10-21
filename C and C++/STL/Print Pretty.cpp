#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		cout << setw(0) << showbase << hex << nouppercase << long(A) << endl;
		cout << right << setfill ('_') << setw (15) << showpos << setprecision(2) << fixed << B << endl;
		cout << uppercase << noshowpos << setprecision(9) << fixed << scientific << C << endl;
	}
	return 0;
}
