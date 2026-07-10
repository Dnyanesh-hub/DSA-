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
// number of islands
void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid, int delrow[], int delcol[])
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col}); // pushing starting node into queue
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && grid[row][col] == '1')
            {
                cnt++;
                bfs(row, col, vis, grid, delrow, delcol);
            }
        }
    }
    return cnt;
}
// number of provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adj, vis);
        }
    }
    return count;
}
// flood fill
// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.
void dfs(int row, int col, vector<vector<int>> &ans,
         vector<vector<int>> &image, int delrow[], int delcol[], int color,
         int iniColor)
{
    ans[row][col] = color;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != color)
        {
            dfs(nrow, ncol, ans, image, delrow, delcol, color, iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image; // cuz never ever tamper the given data
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    dfs(sr, sc, ans, image, delrow, delcol, color, iniColor);
    return ans;
}