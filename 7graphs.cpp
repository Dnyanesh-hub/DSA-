#include <bits./stdc++.h>
using namespace std;
// dfs
void dfs(int v, vector<int> adj[],
         vector<int> &visited,
         vector<int> &result)
{

    // Mark current node as visited
    visited[v] = 1;

    // Store node in result
    result.push_back(v);

    // Traverse all neighbours
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            dfs(u, adj, visited, result);
        }
    }
}
// bfs
vector<int> bfs(vector<vector<int>> &adj)
{
    
    int n = adj.size();
    vector<int> bfs;
    vector<int> vis(n, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
