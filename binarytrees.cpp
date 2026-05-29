#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// level order traversal

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root == NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
// dfs post travesal(left right root)
void postorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    postorder(root, result);
    return result;
}

// dfs inorder traversal
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    { // left root right
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

//  dfs preorder traversal
void preorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    // root left right
    vector<int> ans;
    preorder(root, ans);
    return ans;
}
class Solution
{
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, k);

        cnt++;

        if (cnt == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return ans;
    }
};
class BoundaryOrder
{

    bool isLeaf(TreeNode *node)
    {
        return (node->left == NULL && node->right == NULL);
    }
    void leftBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *cur = root->left;
        // travels till the leaf node and go go left and if there is no left then and then only go to right
        while (cur)
        {
            if (!isLeaf(cur))
            {
                res.push_back(cur->val);
            }
            if (cur->left)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
    void rightBoundary(TreeNode *root, vector<int> &res)
    {
        TreeNode *cur = root->right;
        vector<int> temp;
        while (cur)
        {
            if (!isLeaf(cur))
            {
                temp.push_back(cur->val);
            }
            if (cur->right)
            {
                cur = cur->right;
            }
            else
            {
                cur = cur->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            res.push_back(temp[i]);
        }
    }
    void addLeaves(TreeNode *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->val);
            return;
        }
        if (root->left)
        {
            addLeaves(root->left, res);
        }
        if (root->right)
        {
            addLeaves(root->right, res);
        }
    }

public:
    vector<int> printBoundary(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return res;
        }
        if (!isLeaf(root))
        {
            res.push_back(root->val);
        }
        leftBoundary(root, res);
        addLeaves(root, res);
        rightBoundary(root, res);
        return res;
    }
};
vector<vector<int>> findVertical(TreeNode *root)
{
    // A map is used to store nodes grouped by vertical and level
    map<int, map<int, multiset<int>>> nodes;

    // A queue is used for BFS, storing node and its coordinates
    queue<pair<TreeNode *, pair<int, int>>> todo;

    // Push the root node with vertical = 0 and level = 0
    todo.push({root, {0, 0}});

    // Perform BFS traversal
    while (!todo.empty())
    {
        // Get the front element in queue
        auto p = todo.front();
        todo.pop();

        // Extract node
        TreeNode *temp = p.first;
        // Extract vertical (x)
        int x = p.second.first;
        // Extract level (y)
        int y = p.second.second;

        // Insert the node into map by vertical and level
        nodes[x][y].insert(temp->val);

        // If left child exists, push with updated coordinates
        if (temp->left)
        {
            todo.push({temp->left, {x - 1, y + 1}});
        }

        // If right child exists, push with updated coordinates
        if (temp->right)
        {
            todo.push({temp->right, {x + 1, y + 1}});
        }
    }

    // Final answer vector
    vector<vector<int>> ans;

    // Iterate through verticals in map
    for (auto p : nodes)
    {
        vector<int> col;
        // Collect all nodes in order of levels
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        // Push the column into result
        ans.push_back(col);
    }

    // Return final vertical order traversal
    return ans;
}

// top view of the binary tree
vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        TreeNode *node = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
        {
            // if this line will not be there in the map we will store that line and that data in map cuz our map is storing a our top view

            mp[line] = node->val;
        }
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
}

// bottom view of the binary tree
vector<int>bottomView(TreeNode*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
   map<int,int>mp;
   queue<pair<TreeNode*,int>>q;
   q.push({root,0});
   while(!q.empty()){
      auto it=q.front();
      q.pop();
      TreeNode*node=it.first;
      int line=it.second;
      mp[line]=node->val;
      if(node->left){
        q.push({node->left,line-1});
      }
      if(node->right){
        q.push({node->right,line+1});
      }

   }
   for(auto it:mp){
    ans.push_back(it.second);
   }
   return ans;
}
