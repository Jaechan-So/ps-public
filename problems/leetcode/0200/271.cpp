// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/description/

using namespace std;

#include <string>
#include <vector>

class Codec {
public:
  void pushLength(string &result, int length) {
    if (length == 0) {
      return;
    }

    pushLength(result, length / 10);
    result.push_back('0' + length % 10);
  }

  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    int n = strs.size();
    string result;

    for (int i = 0; i < n; i++) {
      if (i != 0) {
        result.push_back(' ');
      }
      pushLength(result, strs[i].size());
      result.push_back(' ');
      result += strs[i];
    }

    return result;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    int n = s.size(), i = 0;
    vector<string> decoded;

    while (i < n) {
      int length = 0;
      string current;

      while (s[i] != ' ') {
        length *= 10;
        length += (s[i] - '0');
        i++;
      }

      i++;

      for (int j = 0; j < length; j++) {
        current.push_back(s[i + j]);
      }
      decoded.push_back(current);

      i += (length + 1);
    }

    return decoded;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
