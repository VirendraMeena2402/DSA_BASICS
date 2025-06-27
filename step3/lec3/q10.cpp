#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0], currMax = nums[0], currMin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(currMax, currMin);
            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};
