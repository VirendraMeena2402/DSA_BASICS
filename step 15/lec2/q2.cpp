#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            graph[b].push_back(a);
            indegree[a]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            order.push_back(course);
            
            for (int next : graph[course]) {
                indegree[next]--;
                if (indegree[next] == 0) q.push(next);
            }
        }
        
        if (order.size() == numCourses) return order;
        return {};
    }
};
