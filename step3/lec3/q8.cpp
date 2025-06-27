#include <vector>
using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1, count = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
                count += (mid - i + 1);
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
        return count;
    }

    int countInversions(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int inv = countInversions(nums, left, mid);
        inv += countInversions(nums, mid + 1, right);
        inv += mergeAndCount(nums, left, mid, right);
        return inv;
    }

    int inversionCount(vector<int>& nums) {
        return countInversions(nums, 0, nums.size() - 1);
    }
};
