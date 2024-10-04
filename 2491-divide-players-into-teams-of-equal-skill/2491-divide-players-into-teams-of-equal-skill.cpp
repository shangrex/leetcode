class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int total = 0;
        unordered_map<int, int> mp;
        for(auto& s : skill){
            total += s;
            mp[s] += 1;
        }
        
        int skill_l = skill.size();
        int chemistry = total/(skill_l/2);
        long long rst = 0;
        for(auto m : skill){
            int val = m;
            if(mp[val] <= 0) continue;
            cout << val;
            int remain = chemistry - m;
            if(mp.find(remain) == mp.end() || mp[remain] <= 0){
                return -1;
            }
            else {
                rst += (val * (remain));
                mp[val] -= 1;
                mp[remain] -= 1;
            }
        }
        
        return rst;
        
        
    }
};