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
        ListNode *slow = new ListNode(), *fast, *tmp;
        slow->next = head;
        tmp = fast = slow;
        for(int i = 0; i < n+1; i++){
            if(fast != NULL)fast = fast->next;
            // if(fast != NULL)cout << fast->val;
        }
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        if(slow == tmp)head = head->next;
        return head;
    }
};