class Solution {
public:
    /*
            priority_queue<pair<int, int>> pq;
        unordered_map<int, int>mp;
        for(auto num : nums){
            if(mp.find(num) != mp.end()){
                mp[num] += 1;
            }
            else mp[num] = 1;
        }
        
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        vector<int>rst;
        for(int i = 0; i < k; i++){
            pair<int, int>p = pq.top();
            rst.push_back(p.second);
            pq.pop();
        }
        return rst;
    */


















    /*
    Approach 1. map
    Approach 2. bucket sort
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto num : nums){
            mp[num] += 1;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto it : mp){
            bucket[it.second].push_back(it.first);
        }
        int cnt_k = 0;
        vector<int> rst;
        for(int i = n; i >= 0; i--){
            if(!bucket[i].empty()){
                for(int j = 0; j < bucket[i].size(); j++){
                    rst.push_back(bucket[i][j]);
                    cnt_k++;
                }
            }
            if(cnt_k >= k) break;
        }

        return rst;
    }
};