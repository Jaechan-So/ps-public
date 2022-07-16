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
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int num;
        cin >> num;
        vector<int>::iterator loc = lower_bound(v.begin(), v.end(), num);
        if(*loc == num){
            cout << "Yes" << ' ' << (loc - v.begin() + 1) << endl;
        } else {
            cout << "No" << ' ' << (loc - v.begin() + 1) << endl;
        }
    } 
    return 0;
}
