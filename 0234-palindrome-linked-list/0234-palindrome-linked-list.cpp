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
    Second Reverse Linked list
    */
    bool isPalindrome(ListNode* head) {
        ListNode *cur = head;
        vector<int> arr;
        while(cur){
            arr.push_back(cur->val);
            cur = cur->next;
        }
        int l = 0, r = arr.size()-1;
        while(l < r){
            if(arr[l] != arr[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};