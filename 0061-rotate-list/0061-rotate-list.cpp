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
    ListNode* rotateRight(ListNode* head, int k) {
    
        ListNode*cur = head;
        int listLength = 0;
        while(cur){
            cur = cur->next;
            listLength++;
        }
        if(listLength == 0) return NULL;
        k %= listLength;

        ListNode*dummy = new ListNode();
        dummy->next = head;
        ListNode* tail = dummy;
        for(int i = 0; i < k; i++){
            tail = tail->next;
        }
        while(tail->next){
            tail = tail->next;
            dummy = dummy->next;
        }

        tail->next = head;

        head = dummy->next;
        dummy->next = NULL;
        return head;
    }
};