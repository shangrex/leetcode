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
    bool check(TreeNode *root, TreeNode* subRoot){
        if((!root && subRoot) || (root && !subRoot)) return false;
        if(!root && !subRoot) return true;
        //cout << root->val << " " << subRoot->val << endl;
        if(root->val != subRoot->val) return false;
        if (check(root->left, subRoot->left) && check(root->right, subRoot->right)){
            if(root->val == subRoot->val) return true;
        }
        return false;
    }
    
    bool dfs(TreeNode* root, TreeNode* subRoot){
        if(!root) return false;
        bool rst = false;
        if(root->val == subRoot->val) rst |= check(root, subRoot);
        rst |= dfs(root->left, subRoot);
        rst |= dfs(root->right, subRoot);
        return rst;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot); 
    }
};