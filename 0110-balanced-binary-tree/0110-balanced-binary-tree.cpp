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
    /*
    Definition of height-balacned:
    All the node in the tree must meet the condition that abs(height(left) - height(right)) > 1
    */
    int dfs(TreeNode* cur){
        if(!cur) return 0;
        int left = dfs(cur->left);
        int right= dfs(cur->right);

        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        cur->val = max(left, right)+1;
        return cur->val;
    }
    bool isBalanced(TreeNode* root) {
        int rst = dfs(root);
        if(rst == -1) return false;
        else return true;
    }
};