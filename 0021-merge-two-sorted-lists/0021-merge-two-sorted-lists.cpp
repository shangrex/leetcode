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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*rst = new ListNode();
        ListNode*tmp = rst;
        while(list1 && list2){
            if(list1->val <= list2->val){
                rst->next = list1;
                list1 = list1->next;
                rst = rst->next;
            }
            else {
                rst->next = list2;
                list2 = list2->next;
                rst = rst->next;
            }
        }
        if(list1){
            rst->next = list1;
        }
        else if(list2){
            rst->next = list2;
        }
        return tmp->next;
    }
};