#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;
        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
