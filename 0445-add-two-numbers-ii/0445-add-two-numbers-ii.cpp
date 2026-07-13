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
    ListNode* reverse(ListNode *lt){
        // 1->2->3
        // 1<-2
        ListNode *prevNode = NULL;
        while(lt){
            ListNode *nxtNode = lt->next;
            lt->next = prevNode;
            prevNode = lt;
            lt = nxtNode;
        }
        lt = prevNode;
        return prevNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        //cout << l1->val << " " << l2->val << endl;
        int car = 0;
        int rem = 0, val1 = 0, val2 = 0;
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while(l1 || l2){
            if(l1) val1 = l1->val;
            if(l2) val2 = l2->val;
            //cout << val1 << " " << val2 << endl;
            rem = (val1+val2+car)%10;
            car = (val1+val2+car)/10;

            cur->next = new ListNode(rem);
            cur = cur->next;
            val1 = val2 = 0;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(car){
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        dummy = reverse(dummy->next);
        return dummy;
    }
};