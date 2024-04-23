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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rst = new ListNode();
        ListNode *cur = rst;
        int new_val = 0;
        while(l1 && l2){
            ListNode *tmp = new ListNode();
            new_val = l1->val + l2->val + new_val/10;
            tmp->val = new_val % 10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
            cout << new_val << " ";
        }
        while(l1){
            ListNode* tmp = new ListNode();
            new_val = l1->val + new_val/10;
            tmp->val = (new_val)%10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2){
            ListNode* tmp = new ListNode();
            new_val = l2->val + new_val/10;
            tmp->val = (new_val)%10;
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        if(new_val/10){
            ListNode *tmp = new ListNode(1);
            cur->next = tmp;
            cur = cur->next;
        }
        return rst->next;
    }
};