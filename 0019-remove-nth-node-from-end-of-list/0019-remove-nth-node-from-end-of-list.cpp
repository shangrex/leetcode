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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*dummy = new ListNode();
        dummy->next = head;
        ListNode *cur = dummy;
        for(int i = 0; i < n+1; i++){
            cur = cur->next;
        }
        
        ListNode *itr = dummy;
        while(cur){
            itr = itr->next;
            cur = cur->next;
        }
        itr->next = itr->next->next;
        return dummy->next;
    }
};