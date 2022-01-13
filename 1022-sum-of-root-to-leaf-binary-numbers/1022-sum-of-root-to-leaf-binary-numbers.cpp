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
    
    A1
    1. know the level of tree
    2. add the number to the 2 power
    3. triverse with dfs and add
    
    A2
    1. val will multiply to the level number to the 2 power
    2. sum all val
    
    A3
    Use bit wise operator to calculate the number
    
    */
    void dfs(TreeNode* root, int num, int &sum){
        num <<= 1;
        num |= root->val;
        if(root->left == NULL && root->right == NULL){
            sum += num;
        }
        if(root->left)dfs(root->left, num, sum);
        if(root->right)dfs(root->right, num, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};