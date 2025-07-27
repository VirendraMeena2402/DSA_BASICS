#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int subarrays = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                subarrays++;
                currentSum = 0;
            }
            currentSum += num;
        }
        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = 0;
        for (int num : nums) {
            right += num;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
