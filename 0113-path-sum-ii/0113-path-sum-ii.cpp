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
    void helper(TreeNode *root, int target, int sum, vector<int>&cur, vector<vector<int>>&ans){
        if(!root)return;
        
        sum += root->val;
        cur.push_back(root->val);
        
        //leaf
        if(!root->left && !root->right){
            if(sum == target){
                ans.push_back(cur);
            }
        }
        
        helper(root->left, target, sum, cur, ans);
        helper(root->right, target, sum, cur, ans);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>cur;
        vector<vector<int>>ans;
        helper(root, targetSum, 0, cur, ans);
        return ans;
    }
};