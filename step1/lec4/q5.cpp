#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isArmstrong(int n) {
        int original = n, sum = 0;
        int digits = log10(n) + 1;
        while (n > 0) {
            int digit = n % 10;
            sum += pow(digit, digits);
            n /= 10;
        }
        return sum == original;
    }
};
