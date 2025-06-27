#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if (arr.empty()) return 0;

        int minPrice = arr[0];
        int maxProfit = 0;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] < minPrice) {
                minPrice = arr[i];
            } else {
                int profit = arr[i] - minPrice;
                if (profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};
