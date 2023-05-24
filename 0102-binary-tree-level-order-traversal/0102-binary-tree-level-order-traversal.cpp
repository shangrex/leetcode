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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> rst;
        
        if(root!=NULL)q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int>level;
            for(int i = 0; i < n; i++){
                TreeNode *tp = q.front();
                level.push_back(tp->val);
                q.pop();
                if(tp->left)q.push(tp->left);
                if(tp->right)q.push(tp->right);
            }
            rst.push_back(level);
        }
        return rst;
    }
};