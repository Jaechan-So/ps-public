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

		/* Enter your code here */
        cout << left << showbase << nouppercase << hex << (long long)A << endl;
        cout << internal << noshowbase << uppercase << dec;
        
        cout << setw(0xf) << right << showpos << fixed << setprecision(2) << setfill('_') << B << endl;
        cout << internal << noshowpos << setfill(' ');
        
        cout << right << uppercase << scientific << setprecision(9) << C << endl;

	}
	return 0;

}