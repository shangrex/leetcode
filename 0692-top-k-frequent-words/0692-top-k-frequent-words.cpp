class myCompare {
    public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2){
    // if same count then small lexigo first
    if(p1.first == p2.first){
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
    }
};
class Solution {
public:
    /*
    use prioirty_queue with customize operator function
    */
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        priority_queue<pair<int, string>, vector<pair<int, string>>, myCompare>pq;
        
        for(auto &word : words){
            mp[word] += 1;
        }

        for(auto &it : mp){
            pq.push({it.second, it.first});
        }

        vector<string> ret;
        int tmp = 0;
        for(int i = 0; i < k; i++){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};