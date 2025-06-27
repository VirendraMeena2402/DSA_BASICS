#include <iostream>
using namespace std;

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 1e9 + 7;
        long long evenCount = (n + 1) / 2; // even indices
        long long oddCount = n / 2;        // odd indices
        return (powmod(5, evenCount, mod) * powmod(4, oddCount, mod)) % mod;
    }

private:
    long long powmod(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};
