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
    First approach array + two pointer
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        vector<int> arr;
        while(cur){
…        }
        return true;
    }
    Second Reverse Linked list
    */
    ListNode* reverseList(ListNode* cur){
        ListNode *tmpNode = NULL, *prev = NULL;
        
        while(cur){
            /*
            null -> 1 -> 2 -> 3
            t.     c
            */
            tmpNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmpNode;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *rList = reverseList(slow);
        ListNode *cur = head;

        // while(rList){
        //     cout << rList->val << endl;
        //     rList = rList->next;
        // }
        while(cur && rList){
            if(cur->val != rList->val){
                cout << "c" << cur->val << endl;
                cout << rList->val << endl;
                return false;
            }
            cur = cur->next;
            rList = rList->next;
        }
        return true;
        
    }
};