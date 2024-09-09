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
    void inorder(TreeNode* root, int &k){
        if(!root) return ;
        inorder(root->left, k);
        if(--k == 0) rst = root->val;
        cout << k << " " << root->val << endl;
        inorder(root->right, k);        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return rst;
    }
};