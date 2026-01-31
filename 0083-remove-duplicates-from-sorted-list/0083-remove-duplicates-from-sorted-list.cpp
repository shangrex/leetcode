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
        if(!head) return NULL;
        ListNode *cur = head;
        int lastVal = cur->val;
        ListNode*lastNode=cur;
        cur = cur->next;
        while(cur){
            if(cur->val == lastVal){
                // remove duplicate
                lastNode->next = cur->next;
                ListNode *t = cur;
                cur = cur->next;
                delete(t);
                continue;
            }
            lastNode = cur;
            lastVal = cur->val;
            cur = cur->next;

        }
        return head;
    }
};