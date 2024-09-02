class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // find the middle one
        while(fast != NULL){
            fast->next != NULL ? fast = fast->next->next : fast = fast->next;
            if(fast == NULL)break;
            slow = slow->next;
        }
        // reverse the half of the order
        ListNode* prev = NULL, *cur = slow, *nxt = NULL;
        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        ListNode* forward = head, *reverse = prev, *tmp_f, *tmp_r;
        // combine the linked list
        while(forward != NULL){
            tmp_f = forward->next;
            tmp_r = reverse->next;
            forward->next = reverse;
            reverse->next = tmp_f;
            forward = tmp_f;
            reverse = tmp_r;
        }
    }
};