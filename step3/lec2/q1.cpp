#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                int a = mp[complement];
                int b = i;
                return a < b ? vector<int>{a, b} : vector<int>{b, a};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};
