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
 /*
 old solution
     vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<TreeNode*>q;
        root.push(root);

        vector<vector<int>> rst;
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(!t){
                rst.push_back(0)
            }
            q.push(t->left);
            q.push(t->rigth);
        }
    }
 */













class Solution {
public:
/*
Hint: impossible to solve in dfs traversal.

*/

    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> qp;
        map<int, vector<int>> mp;

        int min_col = 0;
        qp.push({root, 0});
        while(!qp.empty()){
            pair<TreeNode*, int> tp = qp.front();
            qp.pop();
            TreeNode *node = tp.first;
            int dirc = tp.second;
            if(!node) continue;
            if(min_col > dirc)min_col = dirc;
            mp[dirc].push_back(node->val);
            qp.push({node->left, dirc-1});
            qp.push({node->right, dirc+1});
        }

        vector<vector<int>> v(mp.size());
        for(auto it : mp){
            
            v[it.first-min_col] = it.second;
        }
        return v;
        
    }
};