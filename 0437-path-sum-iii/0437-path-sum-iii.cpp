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
    int rst = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        findpath(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return rst;
    }

    void findpath(TreeNode*root, long long targetSum){
        if(!root) return;
        if(root->val == targetSum){
            rst++;
        }
        findpath(root->left, targetSum-root->val);
        findpath(root->right, targetSum-root->val);
    }
};