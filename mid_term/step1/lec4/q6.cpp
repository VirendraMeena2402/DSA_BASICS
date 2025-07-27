#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDivisors(int n) {
        vector<int> divisors;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
            }
        }
        return divisors;
    }
};
