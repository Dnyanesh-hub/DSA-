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
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
}

// bottom view of the binary tree
vector<int> bottomView(TreeNode *root)
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
        q.pop();
        TreeNode *node = it.first;
        int line = it.second;
        mp[line] = node->val;
        if (node->left)
        {
            q.push({node->left, line - 1});
        }
        if (node->right)
        {
            q.push({node->right, line + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
// root to node path
bool getPath(TreeNode *root, vector<int> &ans, int x)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->val);
    if (root->val == x)
    {
        return true;
    }
    if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> solution(TreeNode *root, int x)
{
    vector<int> ans;
    getPath(root, ans, x);
    return ans;
}
// root to leaf path
void dfs(TreeNode *root, string path, vector<string> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (path == "")
    {
        path = to_string(root->val);
    }
    else
    {
        path += "->" + to_string(root->val);
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(path);
        return;
    }
    dfs(root->left, path, ans);
    dfs(root->right, path, ans);
}
vector<string> binaryTreePath(TreeNode *root)
{
    vector<string> result;
    string p = "";
    dfs(root, p, result);
    return result;
}
void leftDFS(TreeNode *node, int level, vector<int> &res)
{
    // Base case: null node
    if (!node)
        return;

    // If this is the first node at the current level
    if (res.size() == level)
        res.push_back(node->val);

    // Explore left subtree first
    leftDFS(node->left, level + 1, res);

    // Then explore right subtree
    leftDFS(node->right, level + 1, res);
}

// Recursive function to get right view
void rightDFS(TreeNode *node, int level, vector<int> &res)
{
    if (!node)
        return;

    if (res.size() == level)
        res.push_back(node->val);

    // Explore right subtree first
    rightDFS(node->right, level + 1, res);

    // Then explore left subtree
    rightDFS(node->left, level + 1, res);
}

vector<int> leftView(TreeNode *root)
{
    vector<int> res;
    leftDFS(root, 0, res);
    return res;
}

vector<int> rightView(TreeNode *root)
{
    vector<int> res;
    rightDFS(root, 0, res);
    return res;
}
// symmetric tree or not

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2)
{
    // Check if either subtree is NULL
    if (root1 == NULL || root2 == NULL)
    {
        // If one subtree is NULL, the other
        // must also be NULL for symmetry
        return root1 == root2;
    }
    // Check if the data in the current nodes is equal
    // and recursively check for symmetry in subtrees
    return (root1->val == root2->val) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}
bool isSymmetric(TreeNode *root)
{
    // Check if the tree is empty
    if (!root)
    {
        // An empty tree is
        // considered symmetric
        return true;
    }
    // Call the utility function
    // to check symmetry of subtrees
    return isSymmetricUtil(root->left, root->right);
}

//  maintain binary tree child sum property(root=sum of left child +sum or right child)
void reorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left)
    {
        child += root->left->val;
    }
    if (root->right)
    {
        child += root->right->val;
    }
    if (child >= root->val)
    {
        root->val = child;
    }
    else
    {
        if (root->left)
        {
            root->left->val = child;
        }
        if (root->right)
        {
            root->right->val = child;
        }
    }
    reorder(root->left);
    reorder(root->right);
    int tot = 0;
    if (root->left)
    {
        tot += root->left->val;
    }
    if (root->right)
    {
        tot += root->right->val;
    }
    if (root->left, root->right)
    {
        root->val = tot;
    }
}
// print nodes at distance k from the given target node
void markParents(TreeNode *root,
                 TreeNode *target,
                 unordered_map<TreeNode *, TreeNode *> &track)

{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();

        if (current->left)
        {
            track[current->left] = current;
            q.push(current->left);
        }

        if (current->right)
        {
            track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> track;

    markParents(root, target, track);

    unordered_map<TreeNode *, bool> visited;

    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;

    int level = 0;

    while (!q.empty())
    {

        int size = q.size();

        if (level++ == k)
        {
            break;
        }

        for (int i = 0; i < size; i++)
        {

            TreeNode *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {

                q.push(curr->left);
                visited[curr->left] = true;
            }

            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }

            if (track[curr] && !visited[track[curr]])
            {

                q.push(track[curr]);

                visited[track[curr]] = true;
            }
        }
    }

    vector<int> result;

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }

    return result;
}
// counting the nodes of binary tree recursively brite force apporach
void inorder(TreeNode *root, int &count)
{
    // If current node is NULL, stop processing
    if (root == NULL)
    {
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
int countNodes(TreeNode *root)
{
    // If tree is empty, return 0
    if (root == NULL)
    {
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
int findHeightLeft(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}

// Helper function to find height of rightmost path
int findHeightRight(TreeNode *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->right;
    }
    return height;
}
int countNodes(TreeNode *root)
{
    // If tree is empty, return 0
    if (root == NULL)
    {
        return 0;
    }
    // Get height from left side
    int lh = findHeightLeft(root);
    // Get height from right side
    int rh = findHeightRight(root);
    // If heights are equal, it's a perfect binary tree
    if (lh == rh)
    {
        // Use formula: 2^h - 1
        return (1 << lh) - 1;
    }
    // Otherwise, recursively count left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}
//  min time required to burn the binary tree from given node & min time required to infect binary tree
TreeNode *mapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mpp, int start)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *res = NULL;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        if (node->val == start)
        {
            res = node;
        }
        q.pop();
        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int maxiTime(unordered_map<TreeNode *, TreeNode *> &mpp, TreeNode *target)
{
    queue<TreeNode *> q;
    q.push(target);
    unordered_map<TreeNode *, bool> vis;
    vis[target] = true;
    int time = 0;
    while (!q.empty())
    {
        int sz = q.size();
        bool fl = false;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                fl = true;
                vis[node->left] = true;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                fl = true;
                vis[node->right] = true;
                q.push(node->right);
            }
            if (mpp.find(node) != mpp.end() && !vis[mpp[node]])
            {
                fl = true;
                vis[mpp[node]] = true;
                q.push(mpp[node]);
            }
        }
        if (fl)
        {
            time++;
        }
    }
    return time;
}
int amountOfTime(TreeNode *root, int start)
{
    unordered_map<TreeNode *, TreeNode *> mpp;
    TreeNode *target = mapParents(root, mpp, start);
    return maxiTime(mpp, target);
}
// building unique binary tree using inorder and preorder traversal of tree
TreeNode *build(vector<int> &preorder, int prest, int preend,
                vector<int> &inorder, int inst, int inend,
                map<int, int> &inMap)
{
    if (prest > preend || inst > inend)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[prest]);
    int inroot = inMap[root->val];
    int numleft = inroot - inst;
    root->left = build(preorder, prest + 1, prest + numleft, inorder, inst,
                       inroot - 1, inMap);
    root->right = build(preorder, prest + numleft + 1, preend, inorder,
                        inroot + 1, inend, inMap);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = build(preorder, 0, preorder.size() - 1, inorder, 0,
                           inorder.size() - 1, mp);
    return root;
}
// building unique binary tre from postorder and inorder traversal
TreeNode *build(vector<int> &inorder, int inst, int inend, vector<int> &postorder, int postst, int postend, map<int, int> &mp)
{
    if (inst > inend || postst > postend)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[postend]);

    int inroot = mp[root->val];
    int numleft = inroot - inst;
    root->left = build(inorder, inst, inroot - 1, postorder, postst, postst + numleft - 1, mp);
    root->right = build(inorder, inroot + 1, inend, postorder, postst + numleft, postend - 1, mp);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    TreeNode *root = build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mp);
    return root;
}
// serialize and deserialize the binary tree
// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (root == NULL)
    {
        return "";
    }
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(node->val) + ',');
        }
        if (node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.size() == 0)
    {
        return NULL;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#")
        {
            node->left = NULL;
        }
        else
        {
            TreeNode *leftnode = new TreeNode(stoi(str));
            node->left = leftnode;
            q.push(leftnode);
        }
        getline(s, str, ',');
        if (str == "#")
        {
            node->right = NULL;
        }
        else
        {
            TreeNode *rightnode = new TreeNode(stoi(str));
            node->right = rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
// morris inorder traversal using threaded binary tree concept morris tree gives us O(n) time complexity and O(1) space comeplexity
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr != NULL)
    {

        if (curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}
// flatten binary tree  brute force approach

// previous node pointer for reverse preorder linking

// flatten tree to right-skewed linked list (preorder sequence)
void flatten(TreeNode *root)
{
    TreeNode *prev = nullptr;
    // return if node is null
    if (root == nullptr)
        return;
    // flatten right subtree first
    flatten(root->right);
    // flatten left subtree next
    flatten(root->left);
    // connect current node's right to previously processed node
    root->right = prev;
    // nullify left pointer
    root->left = nullptr;
    // update previous to current
    prev = root;
}
// flatten binary tree using stack

void flattenTreeUsingStack(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        if (curr->right != NULL)
        {
            st.push(curr->right);
        }
        if (curr->left != NULL)
        {
            st.push(curr->left);
        }
        if (!st.empty())
        {
            curr->right = st.top();
        }
        curr->left = NULL;
    }
}
// optimal approach to flatten binary tree using the concept of morris traversal in the O(1) space complexity
void flatten(TreeNode *root)
{
    // Initialize a pointer
    // 'curr' to the root of the tree
    TreeNode *curr = root;

    // Iterate until 'curr'
    // becomes NULL
    while (curr)
    {
        // Check if the current
        // node has a left child
        if (curr->left)
        {
            // If yes, find the rightmost
            // node in the left subtree
            TreeNode *pre = curr->left;
            while (pre->right)
            {
                pre = pre->right;
            }

            // Connect the rightmost node in
            // the left subtree to the current
            //  node's right child
            pre->right = curr->right;

            // Move the entire left subtree to the
            // right child of the current node
            curr->right = curr->left;

            // Set the left child of
            // the current node to NULL
            curr->left = NULL;
        }

        // Move to the next node
        // on the right side
        curr = curr->right;
    }
}
// searching element in binary search tree using O(logn) space
TreeNode *searchInBst(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (root->val = val)
        {
            return root;
        }
        else if (root->val > val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return NULL;
}
// smallest value which is greater or equal  than the key -ceil
int ceil(TreeNode *root, int key)
{
    int ceil = -1;
    while (root != NULL)
    {
        if (root->val == key)
        {
            ceil = root->val;
            return ceil;
        }
        if (key > root->val)
        {
            root = root->right;
        }
        else
        {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

// floor in the binary tree the largest value which is lesser than the given key
int floor(TreeNode *root, int key)
{
    int floor = -1;
    while (root != NULL)
    {
        if (root->val == key)
        {
            floor = root->val;
            return floor;
        }
        if (key > root->val)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
}
// brute force for finding ceil and floor for each of the query
class Solution
{
public:
    //   the smallest largest value greater than the key
    int ceil(TreeNode *root, int key)
    {
        int ceil = -1;
        while (root != NULL)
        {
            if (root->val == key)
            {
                ceil = root->val;
                return ceil;
            }
            if (key > root->val)
            {
                root = root->right;
            }
            else
            {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
    //    floor function floor is the smallest largest value greater than key
    int floor(TreeNode *root, int key)
    {
        int floor = -1;
        while (root != NULL)
        {
            if (root->val == key)
            {
                floor = root->val;
                return floor;
            }
            if (key > root->val)
            {
                floor = root->val;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return floor;
    }
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector<int>> ans;
        int n = queries.size();
        for (int i = 0; i < n; i++)
        {
            int c = ceil(root, queries[i]);
            int f = floor(root, queries[i]);
            ans.push_back({f, c});
        }
        return ans;
    }
};
vector<int> arr;
void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
}
// optimal solution for the finding ceil and floor of given query using lower bound concept
vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
{
    inorder(root);
    vector<vector<int>> ans;
    for (int q : queries)
    {
        auto it = lower_bound(arr.begin(), arr.end(), q);
        int floor = -1;
        int ceil = -1;
        if (it != arr.end())
        {
            ceil = *it;
        }
        if (it != arr.begin())
        {
            floor = *(prev(it));
        }
        if (it != arr.end() && *it == q)
        {
            floor = q;
            ceil = q;
        }
        ans.push_back({floor, ceil});
    }
    return ans;
}

// insert value in the binary tree
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    TreeNode *curr = root;
    while (true)
    {
        // agar value to insert is greater than current value aisa hua toh
        // go to right
        if (curr->val <= val)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new TreeNode(val);
                break;
            }
        }
        // agar curr val insert krni hain uss value se choti hogi toh will
        // go the left
        else
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}
// deleting the node in the binary tree by mainting the propert of binary tree
TreeNode *findLastRight(TreeNode *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findLastRight(root->right);
}
TreeNode *helper(TreeNode *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    TreeNode *rightChild = root->right;
    TreeNode *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == key)
    {
        return helper(root);
    }
    TreeNode *temp = root;
    while (root != NULL)
    {
        if (root->val > key)
        {
            if (root->left != NULL && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return temp;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    int curr = root->val;
    if (curr < p->val && curr < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (curr > p->val && curr > q->val)
    {

        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}
// Two sum in the binary search tree using the concept inorder and extra space of O(n)
void inorder(TreeNode *root, vector<int> &inor)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, inor);
    inor.push_back(root->val);
    inorder(root->right, inor);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> ans;
    inorder(root, ans);
    int i = 0;
    int j = ans.size() - 1;
    while (i < j)
    {
        int sum = ans[i] + ans[j];
        if (sum == k)
        {
            return true;
        }
        if (sum > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
// two sum for the binary tree using the concept of BSTIterator that gives us the space complexity of O(h)
class BSTIterator
{
public:
    stack<TreeNode *> st;
    bool reverse;

    BSTIterator(TreeNode *root, bool isreverse)
    {
        reverse = isreverse;
        pushAll(root);
    }

    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);

            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }

    bool hasNext() { return !st.empty(); }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;

        BSTIterator l(root, false); // smallest
        BSTIterator r(root, true);  // largest

        int i = l.next();
        int j = r.next();

        while (i < j)
        {

            if (i + j == k)
                return true;

            else if (i + j < k)
                i = l.next();

            else
                j = r.next();
        }

        return false;
    }
};
// binary search itreator which checks and gives the next element if there is next element it will return the value of
// that next node and if there will next node it will give true that there is next node and and if there is no next it
// will simply return the false and we are using satck to do this cuz it stores our inorder traversal in O(h) space comeplexity

class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *tempNode = st.top();
        st.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);     // save current node
            node = node->left; // move left
        }
    }
};
// recover binary search tree by swaping two nodes
class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);

        // violation found
        if (prev != NULL && root->val < prev->val)
        {

            // first violation
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // second violation
            else
            {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {

        first = NULL;
        middle = NULL;
        last = NULL;
        prev = NULL;

        inorder(root);

        // two non-adjacent nodes swapped
        if (first && last)
        {
            swap(first->val, last->val);
        }

        // adjacent nodes swapped
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};

// maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).
class Solution
{
    int ans = 0;

    struct Info
    {
        bool isBST;
        int mini;
        int maxi;
        int sum;

        Info(bool b, int mn, int mx, int s)
        {
            isBST = b;
            mini = mn;
            maxi = mx;
            sum = s;
        }
    };

    Info solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return Info(true, INT_MAX, INT_MIN, 0);
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBST && right.isBST && root->val > left.maxi &&
            root->val < right.mini)
        {

            int total = left.sum + right.sum + root->val;

            ans = max(ans, total);

            return Info(true, min(left.mini, root->val),
                        max(right.maxi, root->val), total);
        }

        // not BST
        return Info(false, INT_MIN, INT_MAX, 0);
    }

public:
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};
// making binary search tree from the preorder traversal
class Solution {
public:
    int index = 0;
    TreeNode*build(vector<int>&preorder,int low,int high){
    if(index==preorder.size()){
        return NULL;
    }
    int value=preorder[index];
    if(value<low || value>high){
        return NULL;
    }
    TreeNode*root=new TreeNode(value);
    index++;
    root->left=build(preorder,low,value-1);
    root->right=build(preorder,value+1,high);
    return root;

    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MIN,INT_MAX);
    }
};