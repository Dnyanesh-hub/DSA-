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
// dfs preorder travesal(root-left-right)
void postorder(TreeNode*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return ;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);


}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        postorder(root,result);
        return result;
        
    }