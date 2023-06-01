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
         34
        -6 
    -21 null
 */
class Solution {
public:
    bool check(TreeNode* root, long int left, long int right){
        if(root == NULL)return true;
        
     
        if(root->val <= left || root->val >= right)return false;
        
        return check(root->left, left, root->val) && check(root->right, root->val, right);
        
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        // 0 means left, 1 means right
        return check(root->left, LLONG_MIN, root->val) && check(root->right, root->val, LLONG_MAX	);
    }
};