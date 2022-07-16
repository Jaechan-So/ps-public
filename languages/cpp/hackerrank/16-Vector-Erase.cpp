#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int cur;
        cin >> cur;
        v.push_back(cur);
    }
    int x;
    cin >> x;
    v.erase(v.begin() + x - 1);
    int a, b;
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << endl;
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}
