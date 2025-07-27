#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        reverseHelper(arr, 0, arr.size() - 1);
    }

private:
    void reverseHelper(vector<int>& arr, int left, int right) {
        if (left >= right) return;
        swap(arr[left], arr[right]);
        reverseHelper(arr, left + 1, right - 1);
    }
};
