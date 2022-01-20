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
        if(!list1)return list2;
        else if(!list2)return list1;
        ListNode* n = new ListNode();
        ListNode*iter = n;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                iter->next = list1;
                list1 = list1->next;
            }
            else {
                iter->next = list2;
                list2 = list2->next;
            }
            iter = iter->next;
        }
        iter->next = list1 ? list1 : list2;
        return n->next;
    }
};