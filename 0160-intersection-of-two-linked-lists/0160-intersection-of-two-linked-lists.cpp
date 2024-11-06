/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
        Hint :the intersection point to the listend is the same in both A and B
        -> find the first same point
        
        Approach 1. set like hash table

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        ListNode*cur = headA;
        while(cur){
            s.insert(cur);
            cur = cur->next;
        }

        cur = headB;
        while(cur){
            if(s.count(cur) != 0){
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }
        Approach 2. use hint and check the first same point
    */
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0;
        ListNode *cur = headA;
        while(cur){
            la++;
            cur = cur->next;
        }
        int lb = 0;
        cur = headB;
        while(cur){
            lb++;
            cur = cur->next;
        }

        if(la > lb){
            int diff = la-lb;
            cur = headA;
            for(int i = 0; i < diff; i++) cur = cur->next;
            ListNode *t = headB;
            while(t != cur){
                if(!t)break;
                t = t->next;
                cur = cur->next;
            }
            return cur;
        }
        else {
            int diff = lb -la;
            cur = headB;
            //cout << headB->val<<endl;
            for(int i = 0; i < diff; i++) cur = cur->next;
            ListNode *t = headA;
            while(t != cur){
                if(!t)break;
                cout << t->val << " " << cur->next;
                t = t->next;
                cur = cur->next;
            }
            return cur;
        }
    }
};