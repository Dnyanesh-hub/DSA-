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
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid,int delrow[],int delcol[]){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});// pushing starting node into queue
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }

        }
    }
  }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1')
                {   
                    cnt++;
                    bfs(row,col,vis,grid,delrow,delcol);
                }

            }
        }
        return cnt;
        
    }
