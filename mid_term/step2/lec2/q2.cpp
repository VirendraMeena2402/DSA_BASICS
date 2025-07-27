#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> quickSort(vector<int>& nums) {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSortHelper(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(nums, low, high);
            quickSortHelper(nums, low, pivotIndex - 1);
            quickSortHelper(nums, pivotIndex + 1, high);
        }
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);
        return i + 1;
    }
};
