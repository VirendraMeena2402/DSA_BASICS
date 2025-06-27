#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapping;
        unordered_set<char> used;

        for (int i = 0; i < s.length(); ++i) {
            char sc = s[i], tc = t[i];
            if (mapping.count(sc)) {
                if (mapping[sc] != tc) return false;
            } else {
                if (used.count(tc)) return false; 
                mapping[sc] = tc;
                used.insert(tc);
            }
        }

        return true;
    }
};
