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
        
        bool found_x = false, found_y = false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* t = q.front(); 
                q.pop();
                if(t->val == x)found_x = true;
                if(t->val == y)found_y = true;
                if(t->left && t->right){
                    if(t->left->val == x && t->right->val == y)return false;
                    if(t->left->val == y && t->right->val == x)return false;
                }
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            
            if(found_x && found_y)return true;
            found_x = false;
            found_y = false;
        }
        return false;
    }
};