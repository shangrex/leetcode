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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rst;
        if(!root) return rst;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            int tmp_rst = INT_MIN;
            for(int i = 0; i < q_size; i++){
                TreeNode *tp = q.front();
                tmp_rst = max(tmp_rst, tp->val);
                q.pop();
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right);
            }
            rst.push_back(tmp_rst);
        }
        return rst;
    }
};