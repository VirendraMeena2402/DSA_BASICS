#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
