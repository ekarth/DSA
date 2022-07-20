// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

#include<bits/stdc++.h>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<pair<TreeNode*, int>> pending_nodes;
        vector<vector<int>> ans;

        if(root == NULL) return ans;
        
        pending_nodes.push({root, 0});
        
        while(!pending_nodes.empty())
        {
            auto fetch = pending_nodes.front();
            pending_nodes.pop();

            TreeNode *currNode = fetch.first;
            int level = fetch.second;

            // if current level is not in ans array then add the vector containing val of current node
            if(ans.size() == level) ans.push_back({currNode->val}); 

            // else push the val of current node in that level 
            else ans[level].push_back(currNode->val);

            // checking for left and right child of current node
            if(currNode->left) pending_nodes.push({currNode->left, level+1});
            if(currNode->right) pending_nodes.push({currNode->right, level+1});
        }

        return ans;
    }
};
int main()
{

}
