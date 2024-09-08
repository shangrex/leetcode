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
    Approach 1. merge of two sorted array
    Approach 2. priroty_queue the each list first element and iterate
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int intervals = lists.size();
        int amount = 1;
        while(amount < intervals){
            for(int i = 0; i < lists.size()-amount; i+=amount*2){
                // cout << "list merge" << i << i+amount << endl;
                lists[i] = merge2Lists(lists[i], lists[i+amount]);
            }
            amount*=2;
        }
        if(lists.size() == 0)return NULL;
        else return lists[0];
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode*rst = new ListNode();
        ListNode*cur = rst;
        while(l1 && l2){
            // cout << l1->val << " " << l2->val << endl;
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
            else {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
        }
        
        if(l1){
            cur->next = l1;
        }
        else {
            cur->next = l2;
        }
        
        return rst->next;
    }
};