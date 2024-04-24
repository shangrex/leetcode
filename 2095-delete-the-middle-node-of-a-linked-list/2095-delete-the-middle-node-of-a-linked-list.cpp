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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        if(!head->next)return NULL;
        
        // find the middle point
        while(fast && fast->next){
            slow = slow->next;
            if(!fast->next)break;
            fast = fast->next->next;
        }
        // slow in the middle point
        // find slow's previous node
        ListNode* cur = head;
        while(cur->next != slow){
            cur = cur->next;
        }
        
        cur->next = slow->next;
        
        
        
        return head;
    }
};