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

// dfs inorder traversal 
 void inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){    //left root right
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
        
    }

//  dfs preorder traversal
void preorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // root left right
        vector<int>ans;
         preorder(root,ans);
        return ans;
    } 
   class Solution {
public:
    int cnt = 0;
    int ans = -1;

    void inorder(TreeNode* root, int k) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, k);

        cnt++;

        if(cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
 class BoundaryOrder{
    
    bool isLeaf(TreeNode* node){
    return (node->left == NULL && node->right == NULL);
}
    void leftBoundary(TreeNode*root,vector<int>&res){
        TreeNode*cur=root->left;
        // travels till the leaf node and go go left and if there is no left then and then only go to right 
        while(cur){     
            if(!isLeaf(cur)){
                res.push_back(cur->val);
            }
            if(cur->left){
                cur=cur->left;
            }
            else {
                cur=cur->right;
            }

        }
    }
    void rightBoundary(TreeNode*root,vector<int>&res){
        TreeNode*cur=root->right;
        vector<int>temp;
        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur->val);
            }
            if(cur->right){
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
        }
        for(int i=temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }

    }
    void addLeaves(TreeNode*root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->val);
            return;
        }
        if(root->left){
            addLeaves(root->left,res);
    
        }
        if(root->right){
            addLeaves(root->right,res);
        }
    }
    public:
    vector<int>printBoundary(TreeNode*root){
        vector<int>res;
        if(root==NULL){
            return res;
        }
        if(!isLeaf(root)){
            res.push_back(root->val);
        }
        leftBoundary(root,res);
        addLeaves(root,res);
        rightBoundary(root,res);
        return res;
    }

 };