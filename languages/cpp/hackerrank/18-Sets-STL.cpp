#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin >> q;
    set<int> s;
    for(int i = 0; i < q; i++){
        int type, element;
        cin >> type >> element;
        if(type == 1){
            s.insert(element);
        } else if (type == 2) {
            if(s.find(element) != s.end()){
                s.erase(element);
            }
        } else if (type == 3) {
            if(s.find(element) != s.end()){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    } 
    return 0;
}
