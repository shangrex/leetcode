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
    bool match(TreeNode *l_root, TreeNode* r_root){
        if(!l_root && !r_root) return true;
        if(!l_root) return false;
        if(!r_root) return false;

        if(l_root->val == r_root->val && match(l_root->left, r_root->right) 
            && match(l_root->right, r_root->left)){
                return true;
            }
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        return match(root->left, root->right); 
    }
};