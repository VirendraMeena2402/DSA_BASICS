#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateLeftByOne(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int first = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = first;
    }
};
