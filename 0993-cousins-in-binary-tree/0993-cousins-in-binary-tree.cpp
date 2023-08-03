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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)return false;
        
        bool cx = false, cy = false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front(); 
                q.pop();
                if(t->val == x)cx = true;
                if(t->val == y)cy = true;
                if(t->left&&t->right&&t->left->val==x&&t->right->val==y)return false;
                if(t->left&&t->right&&t->left->val==y&&t->right->val==x)return false;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            
            if(cx && cy)return true;
            cx = false;
            cy = false;
        }
        return false;
    }
};