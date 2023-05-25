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
    /*
    Attention:
    1. char only take 8 bytes, and 1000 is bigger than it, so we can not use char to transform the data.
    
    Solution step:
    1. Design a encode and decode method into string
    2. Triverse all the tree and encode
    3. Triverse all the tree and decode.
    
    
    bfs have a special feature: you can first push all node in queue and pop
    */
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string rst="";
        queue<TreeNode*>q;
        if(root!=NULL){
            q.push(root);
        }
        else {
            rst.append("*,");
        }
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* tp = q.front();
                q.pop();
                if(tp)rst.append(to_string(tp->val)+",");
                else {rst.append("*,");continue;}
                if(tp->left)q.push(tp->left);
                else {q.push(NULL);}
                if(tp->right)q.push(tp->right);
                else {q.push(NULL);}
            }
        }
        return rst;
    }
    
    string helper(string &data){
        int pos = data.find(",");
        string rst = data.substr(0, pos);
        data= data.substr(pos+1);
        return rst;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // cout << data << endl;
        // cout << data.length() << endl;
        TreeNode* rst=NULL, *tp=NULL;
        queue<TreeNode*>q;
        
        string rt = helper(data);
        if(rt != "*"){
            tp = new TreeNode(stoi(rt));
            rst = tp;
            q.push(tp);
        }
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* first = q.front();
                q.pop();
                TreeNode* l, *r;
                
                rt = helper(data);
                if(rt != "*"){
                    l = new TreeNode(stoi(rt));
                    first->left = l;
                    q.push(l);
                }
                else{
                    first->left=NULL;
                }
                rt = helper(data);
                if(rt != "*"){
                    r = new TreeNode(stoi(rt));
                    first->right=r;
                    q.push(r);
                }
                else {
                    first->right=NULL;
                }
            }
        }
        return rst;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));