#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (wordSet.find(endWord) == wordSet.end()) return res;

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> dist;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int d = dist[word];
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (wordSet.find(temp) != wordSet.end()) {
                        adj[temp].push_back(word);
                        if (!dist.count(temp)) {
                            dist[temp] = d + 1;
                            q.push(temp);
                        }
                    }
                }
            }
        }

        vector<string> path = {endWord};
        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                return;
            }
            for (auto& prev : adj[word]) {
                if (dist[prev] == dist[word] - 1) {
                    path.push_back(prev);
                    dfs(prev);
                    path.pop_back();
                }
            }
        };

        if (dist.count(endWord)) dfs(endWord);
        return res;
    }
};
