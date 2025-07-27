#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, maxLength = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
