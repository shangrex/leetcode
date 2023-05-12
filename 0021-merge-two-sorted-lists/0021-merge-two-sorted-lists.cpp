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
    method 1 create a new list and merge
    method 2 merge the list2 to list1
    */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *rst, *tmp;
        rst = new ListNode();
        tmp = rst;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                rst->next = new ListNode();
                rst = rst->next;
                rst->val = list1->val;
                list1 = list1->next;
            }
            else {
                rst->next = new ListNode();
                rst = rst->next;
                rst->val = list2->val;
                list2 = list2->next;
            }
        }
        // add list2 
        if(list1 == NULL){
            rst->next = list2;
        }
        // add list1
        if(list2 == NULL){
            rst->next = list1;
        }
        return tmp->next;
    }
};