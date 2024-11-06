class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        for(auto &i : mp){
            pair<char, int>p;
            pq.push({i.second, i.first});        
        }

        string rst = "";
        while(!pq.empty()){
            pair<int, char>p = pq.top();
            pq.pop();
            rst += p.second;
            
            if(!pq.empty()){
                pair<int, char>t = pq.top();
                pq.pop();
                rst += t.second;
                if(--t.first > 0)
                    pq.push(t);
            }
            else if(p.first > 1)return "";
            
            if(--p.first > 0)
                pq.push(p);
        }


        return rst;
    }
};