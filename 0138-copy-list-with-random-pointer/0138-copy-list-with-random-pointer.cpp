/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* org_cur = head;
        Node* new_head = new Node(org_cur->val);
        Node* new_cur = new_head;
        unordered_map<Node*, Node*> mp;
        mp[org_cur] = new_cur;
        while(org_cur && new_cur){
            Node* new_nxt = NULL;
            if(org_cur->next && mp.find(org_cur->next) == mp.end()){
                // create new copied node
                new_nxt = new Node(org_cur->next->val);
                mp[org_cur->next] = new_nxt;
            }
            else if(org_cur->next){
                // already exist
                new_nxt = mp[org_cur->next];
            }
            else {
                new_nxt = NULL;   
            }
            
            new_cur->next = new_nxt;
            // add random next
            Node* new_random = NULL;
            if(org_cur->random && mp.find(org_cur->random) == mp.end()){
                // random origin not exist
                new_random = new Node(org_cur->random->val);
                mp[org_cur->random] = new_random;
            }
            else if(org_cur->random){
                new_random = mp[org_cur->random];
            }
            else new_random = NULL;
            
            new_cur->random = new_random;
            new_cur = new_cur->next;
            org_cur = org_cur->next;
            
        }
        return new_head;
    }
};