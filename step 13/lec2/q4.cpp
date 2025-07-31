#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> nodes; 
        queue<tuple<TreeNode*, int, int>> q; 
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();
            if (!node) continue;
            nodes[col].push_back({row, node->val});
            q.push({node->left, row + 1, col - 1});
            q.push({node->right, row + 1, col + 1});
        }
        
        vector<vector<int>> result;
        for (auto &entry : nodes) {
            auto &vec = entry.second;
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });
            vector<int> colVals;
            for (auto &p : vec) colVals.push_back(p.second);
            result.push_back(colVals);
        }
        return result;
    }
};
