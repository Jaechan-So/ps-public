#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int length, queries;
    cin >> length >> queries;
    cin.ignore();

    vector<int> arr[length];
    for(int i = 0; i < length; i++){
        vector<int> vec;
        int count;
        cin >> count;
        for(int j = 0; j < count; j++){
            int element;
            cin >> element;
            vec.push_back(element);
        }
        arr[i] = vec;
    }
    for(int i = 0; i < queries; i++){
        int index, location;
        cin >> index >> location;
        cout << arr[index][location] << endl;
    }
    return 0;
}