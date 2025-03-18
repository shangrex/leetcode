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
    dfs
    in each iteration count the rout to leaf number and add
    if reach the leaf then add it to vector

    sum all the num in vector
    */

    void getSum(vector<int>&ret, TreeNode *root, int num){
        num = root->val + num*10;
        if(!root->left && !root->right){
            ret.push_back(num);
            return;
        }

        if(root->left) getSum(ret, root->left, num);
        if(root->right) getSum(ret, root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        vector<int>ret;
        getSum(ret, root, 0);
        int ans = 0;
        for(auto i : ret){
            ans += i;
        }
        return ans;
    }
};