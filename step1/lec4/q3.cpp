#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {
        int original = n, reversed = 0;
        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }
        return original == reversed;
    }
};
