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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }
private:
    TreeNode* build(vector<int>& preorder, int& index, int bound) {
        if (index == preorder.size() || preorder[index] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, bound);
        return root;
    }
};
