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
        int flag = 0;
        while(list1 != NULL && list2 != NULL){
            ListNode *tmp = new ListNode();
            if(list1->val < list2->val){
                tmp->val = list1->val;
                list1 = list1->next;
                flag =1;
            }
            else {
                tmp->val = list2->val;
                list2 = list2->next;
                flag = 2;
            }
            iter->next = tmp;
            iter = iter->next;
        }
        if(flag == 1){
            // check list2
            iter->next = list2;
        }
        else {
            iter->next = list1;
        }
        return n->next;
    }
};