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

    void dfs(TreeNode *root, double target, double diff, int& ret){
        if(!root) return;
        double t_diff = abs(target - (double)root->val);
        if(t_diff == 0){
            ret = root->val;
            return;
        }
        if(diff > t_diff){
            diff = t_diff;
            ret = root->val;
        }
        else if(diff == t_diff){
            ret = min(ret, root->val);
        }
        
        if(root->val > target){
            if(root->left) dfs(root->left, target, diff, ret);
        }
        else {
            if(root->right) dfs(root->right, target, diff, ret);
        }
    }
    int closestValue(TreeNode* root, double target) {
        double diff = DBL_MAX;
        int ret = 0;
        dfs(root, target, diff, ret);
        return ret;
    }
};