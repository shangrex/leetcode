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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > q;

        for(auto &l : lists){
            if(l) q.push({l->val, l});
        }

        ListNode *dummy = new ListNode(0);
        ListNode *cur;
        cur = dummy;
        while(!q.empty()){
            pair<int, ListNode*> point = q.top();
            q.pop();
            cur->next = point.second;
            cur = cur->next;

            if(point.second->next){
                ListNode *nxt = point.second->next;
                q.push({nxt->val, nxt});
            }
        }
        return dummy->next;
    }
};