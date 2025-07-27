#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        unordered_map<int, int> xorCount;
        int count = 0, xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
            if (xorSum == k) count++;
            if (xorCount.find(xorSum ^ k) != xorCount.end()) {
                count += xorCount[xorSum ^ k];
            }
            xorCount[xorSum]++;
        }
        return count;
    }
};
