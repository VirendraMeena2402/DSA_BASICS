#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0 || index == candidates.size()) return;

        curr.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], index, curr, res);
        curr.pop_back();
        backtrack(candidates, target, index + 1, curr, res);
    }
};
