struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b) {
     
        return a.second < b.second;
    }  
};
class Solution {
public:
    /*
    Approach 1: priority queue
    O(NlgN)
    Approach 2: bucket sort
    Time: O(N)
    Space: 
    Approach 3: selection algorithmns
    Time: O(k*N)
    */
    /*
            
        vector<int>rst;
        
        map<int, int>fq;
        // O(N)
        for(int i = 0; i < nums.size(); i++){
            fq[nums[i]] += 1;
        }
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, cmp>pq;
        // O(NlgN)
        for(auto i = fq.begin(); i != fq.end(); i++){
            pair<int,int>tmp;
            tmp.first = i->first;
            tmp.second = i->second;
            pq.push(tmp);
        }
        int it = 0;
        // O(N)
        while(!pq.empty()){
            if(it >= k)break;
            pair<int, int> tmp = pq.top();
            pq.pop();
            rst.push_back(tmp.first);
            it++;
        }
        return rst;
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>mp;
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += 1;
        }
        
        priority_queue< pair<int,int>> pq;
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        vector<int>rst;
        for(int i = 0; i < k; i++){
            rst.push_back(pq.top().second);
            pq.pop();
        }
        return rst;
        
    }
};