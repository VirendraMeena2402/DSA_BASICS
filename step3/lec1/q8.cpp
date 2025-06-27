#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> unionSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                ++i;
            } else if (nums1[i] > nums2[j]) {
                if (result.empty() || result.back() != nums2[j]) {
                    result.push_back(nums2[j]);
                }
                ++j;
            } else {
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }

        while (i < nums1.size()) {
            if (result.empty() || result.back() != nums1[i]) {
                result.push_back(nums1[i]);
            }
            ++i;
        }

        while (j < nums2.size()) {
            if (result.empty() || result.back() != nums2[j]) {
                result.push_back(nums2[j]);
            }
            ++j;
        }

        return result;
    }
};
