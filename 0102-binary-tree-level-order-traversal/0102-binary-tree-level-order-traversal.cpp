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
        vector<vector<int>> rst;
        
        queue<TreeNode*> q;
        if(root)q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> rst_level;
            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
                rst_level.push_back(tp->val);
            }
            rst.push_back(rst_level);
        }
        return rst;
    }
};