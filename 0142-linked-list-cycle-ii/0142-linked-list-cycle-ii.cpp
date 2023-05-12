/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    
    tail + first step + n*cycle length = slow length
    tail + first step*2 + second step + m*cycle length = fast length
    2 tail + 2 first step + 2n*cycle length = 2*slow length = fast length = tail + first step*2 + second step + m*cycle length
    tail = second step + (m-n)cycle length
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        
        // find the first meeting point,
        while(true){
            if(slow != NULL)slow = slow->next;
            else return NULL;
            if(fast->next != NULL)fast = fast->next->next;
            else return NULL;
            if(fast == NULL)return NULL;
            if(slow == fast)break;
        }
        
        ListNode* rst = head;
        while(rst != slow){
            rst = rst->next;
            slow = slow->next;
        }
        return rst;
    }
};