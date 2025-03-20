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

    void dfs(TreeNode*root, int &ret, int& low, int& high){
        if(root->val >= low && root->val <= high){
            ret += root->val;
            if(root->left) dfs(root->left, ret, low, high);
            if(root->right) dfs(root->right, ret, low, high);
        }
        else if(root->val < low){
            if(root->right) dfs(root->right, ret, low, high);
        }
        else if(root->val > high){
            if(root->left) dfs(root->left, ret, low, high);
        }
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ret = 0;
        dfs(root, ret, low, high);
        return ret;
    }
};