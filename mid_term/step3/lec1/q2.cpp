#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findSecondLargest(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        int largest = nums[0];
        int secondLargest = -1;
        bool foundSecond = false;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                foundSecond = true;
            } else if (nums[i] < largest) {
                if (!foundSecond || nums[i] > secondLargest) {
                    secondLargest = nums[i];
                    foundSecond = true;
                }
            }
        }

        return foundSecond ? secondLargest : -1;
    }
};
