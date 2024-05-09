class Solution {
public:
    /*
    
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
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
    }
};