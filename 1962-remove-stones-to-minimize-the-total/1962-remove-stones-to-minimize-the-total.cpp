class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ret = 0;
        for(int i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
        }

        for(int i = 0; i < k; i++){
            int t = pq.top();
            pq.pop();
            pq.push(( t%2==0?t/2:t/2+1 ));
        }

        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            ret += t;
        }
        return ret;
    }
};