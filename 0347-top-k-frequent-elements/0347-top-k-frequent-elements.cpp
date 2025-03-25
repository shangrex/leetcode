class Solution {
public:
    
    /*Approach 1. map, can use min-heap to optimize
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


    Approach 2. bucket sort
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
        
        vector<int> rst;
        for(int i = n; i >= 0; i--){
            if(!bucket[i].empty()){
                for(int j = 0; j < bucket[i].size(); j++){
                    rst.push_back(bucket[i][j]);
                    k--;
                }
            }
            if(k == 0) break;
        }

        return rst;
    }
    */


















    /*
    
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

        vector<int> rst;
        for(int i = n; i >= 0; i--){
            if(bucket[i].empty()) continue;
            for(auto j : bucket[i]){
                rst.push_back(j);
                if((int)rst.size() == k)break;
            }
            if((int)rst.size() == k) break;
        }

        return rst;
    }
};