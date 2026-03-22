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
/*
Approach 1.

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* rst = new ListNode();
        ListNode *cur = rst;
        while(l1 && l2){
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (carry + l1->val + l2->val)%10;
            carry = (l1->val + l2->val+carry)/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (carry + l1->val)%10;
            carry = (l1->val+carry)/10;
            l1 = l1->next;
        }

        while(l2){
            cur->next = new ListNode();
            cur = cur->next;
            cur->val = (carry + l2->val)%10;
            carry = (l2->val+carry)/10;
            l2 = l2->next;
        }

        if(carry > 0){
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        return rst->next;
    }
*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int val1 = 0, val2 = 0;
        ListNode *cur;
        ListNode *ret = new ListNode();
        cur = ret;

        while(l1 || l2 || carry > 0){
            cur->next = new ListNode();
            cur = cur->next;
            if(l1){
                val1 = l1->val;
                l1 = l1->next;
            }
            else val1 = 0;
            if(l2){
                val2 = l2->val;
                l2 = l2->next;
            }
            else val2 = 0;
            int total = (val1+val2+carry)%10;
            carry = (val1+val2+carry)/10;
            cur->val = total;
        }
        return ret->next;
    }
};