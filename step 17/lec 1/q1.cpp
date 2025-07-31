#include <vector>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxResult = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            int temp = maxResult | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(prefix ^ temp)) {
                    maxResult = temp;
                    break;
                }
            }
        }
        return maxResult;
    }
};
