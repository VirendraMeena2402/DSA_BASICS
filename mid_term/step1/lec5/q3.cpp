#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        return checkPalindrome(s, 0, s.length() - 1);
    }

private:
    bool checkPalindrome(const string& s, int left, int right) {
        if (left >= right) return true;
        if (s[left] != s[right]) return false;
        return checkPalindrome(s, left + 1, right - 1);
    }
};

