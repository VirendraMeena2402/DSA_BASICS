#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, curr, res);
            curr.pop_back();
        }
    }
};
