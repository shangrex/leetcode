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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> qp;
        // use set to sort
        map<int, map<int, multiset<int>>> nodes;

        qp.push({root, {0, 0}});
        while(!qp.empty()){
            pair<TreeNode*, pair<int, int>> tp = qp.front();
            qp.pop();
            TreeNode *node = tp.first;
            int col = tp.second.first;
            int row = tp.second.second;
            
            nodes[col][row].insert(node->val);
   
            if(node->left)qp.push({node->left, {col-1, row+1}});
            if(node->right)qp.push({node->right, {col+1, row+1}});
        }
        
        vector<vector<int>> ret;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                // sort(q.second.begin(), q.second.end());
                // for(auto k : q.second){
                //     col.push_back(k);
                // }
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ret.push_back(col);
        }


        return ret;
    }
};