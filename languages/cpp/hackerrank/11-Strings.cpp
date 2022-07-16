#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << a.length() << " " << b.length() << endl;
    cout << a + b << endl;

    char cha, chb;
    cha = b[0]; chb = a[0];
    a[0] = cha; b[0] = chb;
    cout << a << " " << b << endl;
    return 0;
}