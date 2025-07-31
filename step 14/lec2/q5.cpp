#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root, k, s);
    }
private:
    bool dfs(TreeNode* root, int k, unordered_set<int>& s) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return dfs(root->left, k, s) || dfs(root->right, k, s);
    }
};
