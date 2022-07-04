// 161. One Edit Distance
// https://leetcode.com/problems/one-edit-distance/

using namespace std;

#include <string>

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lengthDiff = s.size() - t.size();

        if(lengthDiff == -1) {
            return isOneInsert(s, t);
        } else if(lengthDiff == 0) {
            return isOneReplace(s, t);
        } else if(lengthDiff == 1) {
            return isOneDelete(s, t);
        }

        return false;
    }

    bool isOneInsert(string& s, string& t) {
        int i = 0, j = 0, sLength = s.size(), tLength = t.size(); // sLength - tLength == -1

        while(i < sLength && j < tLength) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else if (i == j && s[i] != t[j]) {
                j++;
            } else {
                return false;
            }
        }

        return true;
    }

    bool isOneReplace(string& s, string& t) {
        int i = 0, j = 0, sLength = s.size(), tLength = t.size(); // sLength - tLength == 0
        bool alreadyDuplicate = false;

        while(i < sLength && j < tLength) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else if (!alreadyDuplicate && s[i] != t[j]) {
                alreadyDuplicate = true;
                i++;
                j++;
            } else {
                return false;
            }
        }

        return alreadyDuplicate;
    }

    bool isOneDelete(string& s, string& t) {
        int i = 0, j = 0, sLength = s.size(), tLength = t.size(); // sLength - tLength == 1

        while(i < sLength && j < tLength) {
            if(s[i] == t[j]) {
                i++;
                j++;
            } else if (i == j && s[i] != t[j]) {
                i++;
            } else {
                return false;
            }
        }

        return true;
    }
};
