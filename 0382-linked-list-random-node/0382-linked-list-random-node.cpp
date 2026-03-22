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
    int listLength;
    ListNode *mhead;
    Solution(ListNode* head) {
        srand(time(0));
        mhead = head;
    }
    
    int getRandom() {
        /*
        Reservior Sampling
        */

        ListNode *cur = mhead;
        int ret = cur->val;
        int scope = 1;
        while(cur){
            if(rand() % scope == 0){
                ret = cur->val;
            }
            scope+=1;
            cur = cur->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */