#include <vector>
#include <algorithm>
#include <array>
using namespace std;

struct TrieNode {
    TrieNode* child[2] = {nullptr, nullptr};
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            if (!node->child[b]) node->child[b] = new TrieNode();
            node = node->child[b];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        if (!node->child[0] && !node->child[1]) return -1;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int b = (num >> i) & 1;
            int toggledBit = b ^ 1;
            if (node->child[toggledBit]) {
                maxXor |= (1 << i);
                node = node->child[toggledBit];
            } else {
                node = node->child[b];
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int q = queries.size();
        vector<array<int, 3>> offlineQueries; // {mi, xi, index}
        for (int i = 0; i < q; i++) {
            offlineQueries.push_back({queries[i][1], queries[i][0], i});
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;
        vector<int> ans(q, -1);
        int idx = 0;

        for (auto& [mi, xi, i] : offlineQueries) {
            while (idx < n && nums[idx] <= mi) {
                trie.insert(nums[idx++]);
            }
            ans[i] = trie.getMaxXOR(xi);
        }
        return ans;
    }
};
