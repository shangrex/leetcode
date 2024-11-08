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
// class Solution {
// public:
//     ListNode* reverseLinkedList(ListNode* head, int k){
//         ListNode *prev = NULL;
//         ListNode *cur = head;
//         while(k > 0){
//             ListNode*tmp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = tmp;
//             k--;
//         }
        
//         return prev;
//     }
    
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *cur = head;
//         int cnt = 0;
//         while(cnt < k && cur != NULL){
//             cur = cur->next;
//             cnt++;
//         }
        
//         if(cnt == k){
//             ListNode *rev_cur = reverseLinkedList(head, k);
//             head->next = reverseKGroup(cur, k);
//             return rev_cur;
//         }
        
//         return head;
//     }
// };
class Solution {
public:
    /*
    Apporach 1. recursive
    first step check the list lenght is bigger than k or not 
        if bigger than return head
        otherwise return the new node that is the head of reversed linked list
            and reverse the node in k times 
        
    
    
    Approach 2. iterative
    */
    ListNode* reverseLinkedList(ListNode* head, int k){
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(k > 0){
            ListNode*tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            k--;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        // check if length is larger than k
        int cnt = 0;
        while(cnt < k && cur != NULL){
            cur = cur->next;
            cnt++;
        }
        
        if(cnt == k){
            ListNode* prev = NULL, *cur = head, *tmp_next;
            for(int i = 0; i < k; i++){
                tmp_next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp_next;
            }
            
            head->next = reverseKGroup(cur, k);
            return prev;
        }
        
        return head;
    }
};