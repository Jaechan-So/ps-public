#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    map<string, int> m;
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1){
            string name;
            int mark;
            cin >> name >> mark;
            if(m.find(name) != m.end()){
                m[name] += mark;
            } else {
                m.insert(make_pair(name, mark));
            }
        } else if(type == 2 || type == 3){
            string name;
            cin >> name;
            if(type == 2 && m.find(name) != m.end()){
                m.erase(name);
            } else if(type == 3){
                if(m.find(name) != m.end()){
                    cout << m[name] << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }  
    return 0;
}



