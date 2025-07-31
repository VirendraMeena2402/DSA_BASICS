#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left;
            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();
                idx -= left; // normalize index
                right = idx;
                if (node->left) q.push({node->left, 2 * idx});
                if (node->right) q.push({node->right, 2 * idx + 1});
            }
            maxWidth = max(maxWidth, (long long)(right + 1)); // ✅ Cast to same type
        }
        return (int)maxWidth;
    }
};
