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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur, *prev, *forward;
        dummy->next = head;
        prev = dummy;

        for(int i = 0 ; i < left - 1; i++){
            prev = prev->next;
        }

        cur = prev->next;
        // 1 2 3 4 5  6 7, (3, 6)
        // 1 2 3 10 9 8 4
        //     p. c f
        //. 1 2 3 9 10 8 4
        //  1 2 3 8 9 10 4
        // 1 2 3 
        for(int i = 0; i < right - left; i++){
            forward = cur->next;
            cur->next = forward->next;
            forward->next = prev->next;
            prev->next = forward; 


            // prev = prev->next;
            // cur = cur->next;

        }



        return dummy->next;
    }
};