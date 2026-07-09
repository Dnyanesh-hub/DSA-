#include <bits./stdc++.h>
using namespace std;
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