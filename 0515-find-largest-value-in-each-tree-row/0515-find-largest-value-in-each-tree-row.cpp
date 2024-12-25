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
            int curMax = INT_MIN;
            for(int i = 0; i < q_size; i++){
                TreeNode *node = q.front();
                curMax = max(curMax, node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            rst.push_back(curMax);
        }
        return rst;
    }
};