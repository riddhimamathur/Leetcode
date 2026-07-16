class Solution {
public:
    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& visited,
             vector<bool>& recStack,
             vector<int>& ans)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int neigh : adj[node])
        {
            if (!visited[neigh])
            {
                if (dfs(neigh, adj, visited, recStack, ans))
                    return true;
            }
            else if (recStack[neigh])
            {
                return true; // Cycle found
            }
        }

        recStack[node] = false;
        ans.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        // b -> a
        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, recStack, ans))
                    return {};
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};