#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int mostFrequentElement(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int maxFreq = 0;
        int result = arr[0];  

        for (auto& entry : freq) {
            int num = entry.first;
            int count = entry.second;
            if (count > maxFreq || (count == maxFreq && num < result)) {
                maxFreq = count;
                result = num;
            }
        }

        return result;
    }
};
