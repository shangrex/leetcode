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
    void reorderList(ListNode* head) {
        // 1. find the middle point
        // 2. reverse the linked list after the middle part
        // 3. merge the linked list 
        ListNode *slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        
        // slow is the middle point
        // reverse the linked list
        ListNode *prev = NULL;
        while(slow){
            ListNode *post = slow->next;
            slow->next = prev;
            prev = slow;
            slow = post;
        }
        
        

        // merge
        ListNode* cur = head;
        ListNode* tail = prev;
        while(cur && tail){
            cout << cur->val << " " << tail->val << endl;
            ListNode* post = tail->next;
            ListNode* post_forward = cur->next;
            cur->next = tail;
            tail->next = post_forward;
            cur = post_forward;
            tail = post;
        }
        // if line 19 is while(fast && fast->next) then need line 51
        //if(cur)cur->next=NULL;
      
    }
};
// ListNode *post_forward = cur->next;
//             cur->next = tail;
//             tail = tail->next;
//             cur = cur->next;
//             cur->next = post_forward;
//             cur = cur->next;