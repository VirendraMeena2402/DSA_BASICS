#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0, neededDays = 1;
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                neededDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return neededDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for (int weight : weights) {
            right += weight;
        }
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
