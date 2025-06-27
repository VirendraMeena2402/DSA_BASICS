#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

private:
    void backtrack(vector<string>& res, string curr, int open, int close, int max) {
        if (curr.length() == max * 2) {
            res.push_back(curr);
            return;
        }
        if (open < max)
            backtrack(res, curr + '(', open + 1, close, max);
        if (close < open)
            backtrack(res, curr + ')', open, close + 1, max);
    }
};
