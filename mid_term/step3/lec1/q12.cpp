#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubarrayWithSumK(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumIndex;
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
                int len = i - prefixSumIndex[sum - k];
                if (len > maxLen) {
                    maxLen = len;
                }
            }

            if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
                prefixSumIndex[sum] = i;
            }
        }

        return maxLen;
    }
};
