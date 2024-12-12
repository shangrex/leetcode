/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> rst;
        vector<int>path;
        findpath(rst, path, root, targetSum);
        return rst;
    }

    void findpath(vector<vector<int>>&rst, vector<int>&path, TreeNode*root, int targetSum){
        if(!root) return;
        path.push_back(root->val);
        if(root->val == targetSum && !root->left && !root->right){
            rst.push_back(path);
        }
        findpath(rst, path, root->left, targetSum-root->val);
        findpath(rst, path, root->right, targetSum-root->val);
        path.pop_back();
    }
};