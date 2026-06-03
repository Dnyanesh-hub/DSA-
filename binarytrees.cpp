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
// root to node path 
bool getPath(TreeNode*root,vector<int>&ans,int x){
    if(root==NULL){
        return false;
    }
    ans.push_back(root->val);
    if(root->val==x){
        return true;
    }
    if(getPath(root->left,ans,x)||getPath(root->right,ans,x)){
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int>solution(TreeNode*root,int x){
    vector<int>ans;
    getPath(root,ans,x);
    return ans;
}
// root to leaf path 
void dfs(TreeNode*root,string path,vector<string>&ans){
    if(root==NULL){
        return ;
    }
    if(path==""){
        path=to_string(root->val);
    }
    else{
        path+="->"+to_string(root->val);
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(path);
        return ;
    }
    dfs(root->left,path,ans);
    dfs(root->right,path,ans);
}
vector<string>binaryTreePath(TreeNode*root){
    vector<string>result;
    string p="";
    dfs(root,p,result);
    return result;
}
  void leftDFS(TreeNode* node, int level, vector<int>& res) {
        // Base case: null node
        if (!node) return;

        // If this is the first node at the current level
        if (res.size() == level)
            res.push_back(node->val);

        // Explore left subtree first
        leftDFS(node->left, level + 1, res);

        // Then explore right subtree
        leftDFS(node->right, level + 1, res);
    }

    // Recursive function to get right view
    void rightDFS(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level)
            res.push_back(node->val);

        // Explore right subtree first
        rightDFS(node->right, level + 1, res);

        // Then explore left subtree
        rightDFS(node->left, level + 1, res);
    }

    vector<int> leftView(TreeNode* root) {
        vector<int> res;
        leftDFS(root, 0, res);
        return res;
    }

    vector<int> rightView(TreeNode* root) {
        vector<int> res;
        rightDFS(root, 0, res);
        return res;
    }
// symmetric tree or not

    bool isSymmetricUtil(TreeNode* root1, TreeNode* root2) {
        // Check if either subtree is NULL
        if (root1 == NULL || root2 == NULL) {
            // If one subtree is NULL, the other
            // must also be NULL for symmetry
            return root1 == root2;
        }
        // Check if the data in the current nodes is equal
        // and recursively check for symmetry in subtrees
        return (root1->val == root2->val)
            && isSymmetricUtil(root1->left, root2->right)
            && isSymmetricUtil(root1->right, root2->left);
    }
     bool isSymmetric(TreeNode* root) {
        // Check if the tree is empty
        if (!root) {
            // An empty tree is
            // considered symmetric
            return true;
        }
        // Call the utility function
        // to check symmetry of subtrees
        return isSymmetricUtil(root->left, root->right);
    }

//  maintain binary tree child sum property(root=sum of left child +sum or right child)
void reorder(TreeNode*root){
    if(root==NULL){
        return ;
    }
    int child=0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }
    if(child>=root->val){
        root->val=child;

    }
    else{
        if(root->left){
            root->left->val=child;
        }
        if(root->right){
            root->right->val=child;
        }
    }
    reorder(root->left);
    reorder(root->right);
    int tot=0;
    if(root->left){
        tot+=root->left->val;
    }
    if(root->right){
        tot+=root->right->val;
    }
    if(root->left,root->right){
        root->val=tot;
    }
}
// print nodes at distance k from the given target node
void markParents(TreeNode* root,
                 TreeNode* target,
                 unordered_map<TreeNode*, TreeNode*>& track) 

{
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();

        if(current->left){
            track[current->left] = current;
            q.push(current->left);
        }

        if(current->right){
            track[current->right] = current;
            q.push(current->right);
        }
    }   
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    unordered_map<TreeNode*,TreeNode*> track;
    

    markParents(root,target,track);

    unordered_map<TreeNode*,bool> visited;
    

    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;

    int level = 0;

    while(!q.empty()){

        int size = q.size();

        if(level++ == k){
            break;
        }

        for(int i=0;i<size;i++){

            TreeNode* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                

                q.push(curr->left);
                visited[curr->left] = true;
            }

            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if(track[curr] && !visited[track[curr]]){
                

                q.push(track[curr]);
                

                visited[track[curr]] = true;
            
            }
        }
    }

    vector<int> result;

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }

    return result;
}
// counting the nodes of binary tree recursively brite force apporach 
 void inorder(TreeNode* root, int &count) {
        // If current node is NULL, stop processing
        if (root == NULL) {
            return;
        }
        // Increment count for current node
        count++;
        // Recursively count nodes in the left subtree
        inorder(root->left, count);
        // Recursively count nodes in the right subtree
        inorder(root->right, count);
    }

    // Function to count total number of nodes in the binary tree
    int countNodes(TreeNode* root) {
        // If tree is empty, return 0
        if (root == NULL) {
            return 0;
        }
        // Variable to store node count
        int count = 0;
        // Perform inorder traversal to count nodes
        inorder(root, count);
        // Return total number of nodes
        return count;
    }
    // optimal approach using tree height concept 2^h-1
        int findHeightLeft(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }

    // Helper function to find height of rightmost path
    int findHeightRight(TreeNode* node) {
        int height = 0;
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
      int countNodes(TreeNode* root) {
        // If tree is empty, return 0
        if (root == NULL) {
            return 0;
        }
        // Get height from left side
        int lh = findHeightLeft(root);
        // Get height from right side
        int rh = findHeightRight(root);
        // If heights are equal, it's a perfect binary tree
        if (lh == rh) {
            // Use formula: 2^h - 1
            return (1 << lh) - 1;
        }
        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }


