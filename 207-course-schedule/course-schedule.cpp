#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfsCycle(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& recStack) {
        if (recStack[u]) return true;
        if (visited[u]) return false;
        visited[u] = true;
        recStack[u] = true;
        for (int v : adj[u]) {
            if (dfsCycle(adj, v, visited, recStack)) return true;
        }
        recStack[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfsCycle(adj, i, visited, recStack)) return false; 
            }
        }
        return true; 
    }
};