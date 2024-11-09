/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // use BFS to encode
    // Encodes a tree to a single string.

    // hint, both queue
    // helper is important
    string serialize(TreeNode* root) {
        string rst = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(!t){rst+="#,";continue;}
            else rst += to_string(t->val)+",";

            if(t->left){
                q.push(t->left);
            }
            else q.push(NULL);
            if(t->right){
                q.push(t->right);
            }
            else q.push(NULL);
        }
        cout <<rst << endl;
        return rst;
    }

    string helper(string &data){
        int sp = data.find(",");
        string front = data.substr(0, sp);
        data = data.substr(sp+1);
        return front;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#')return NULL;
        queue<TreeNode*>q;
        string t = helper(data);
        TreeNode *head = new TreeNode(stoi(t));
        q.push(head);
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; i++){
                string ls = helper(data);
                TreeNode *tp = q.front();
                cout << tp->val << endl;
                q.pop();
                cout << ls << endl;
                if(ls != "#"){
                    tp->left = new TreeNode(stoi(ls));
                    q.push(tp->left);
                }
                else tp->left = NULL;
                string rs = helper(data);
                cout << rs << endl;
                if(rs != "#"){
                    tp->right = new TreeNode(stoi(rs));
                    q.push(tp->right);
                }
                else tp->right = NULL;
            }
        }

        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;