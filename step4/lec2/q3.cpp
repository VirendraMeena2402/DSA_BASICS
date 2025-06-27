#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (computeSum(nums, mid) <= threshold) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
