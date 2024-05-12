/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* psu = new ListNode(0, head);
        ListNode*prev = psu, *cur = head;
        if(!cur)return NULL;
        while(cur){
            ListNode*sub_tail = cur->next;                
            if(sub_tail && sub_tail->val == cur->val){
                // cout << sub_tail->val << endl;
                while(sub_tail && sub_tail->val == cur->val){
                    sub_tail = sub_tail->next;    
                }
                prev->next = sub_tail;
            }
            else {
                prev = cur;
            }
            cur = sub_tail;
        }
        
        return psu->next;
    }
};