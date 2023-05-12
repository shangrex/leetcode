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
struct comp{
    // priority_queue is !comparison.
    bool operator()(ListNode* a, ListNode* b){
        if(a->val < b->val)return false;
        else return true;
    }
};
class Solution {
public:
    /*
    assume there are K lists and every lists' length is N.
    
    approach 1: use priority queue, always add the smallest node into the newlist.
    Time complexity O(lgK)
    approach 2: merge 1, 2 and merge 3 4.... divide the question to merge 2 sorted list, and the time complexity is O(N*lgK)
    */

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp>pq;
    
        // initialize
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL)pq.push(lists[i]);
        }
        
        ListNode *rst = new ListNode();
        ListNode *head = rst;
        while(!pq.empty()){
            ListNode*tmp = pq.top();
            pq.pop();
            rst->next = tmp;
            rst = rst->next;
            if(tmp->next != NULL){
                tmp = tmp->next;
                pq.push(tmp);            
            }
        }
        return head->next;
    }
};