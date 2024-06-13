class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int>mp;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]-'a'] = i;
        }
        
        vector<int>ans;
        int split = 0, last_split = 0;
        for(int i = 0; i < s.length(); i++){
            split = max(split, mp[s[i]-'a']);
            if(split > i)continue;

            else {
                ans.push_back(i-last_split+1);
                last_split = i+1;
            }
        }
        return ans;
    }
};