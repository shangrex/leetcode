class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        map<string, int> cnt;
        map<string, map<int, string>> mp;

        for(int i = 0; i < username.size(); i++){
            mp[username[i]][timestamp[i]] = website[i];
        }

        for(auto &u : mp){
            unordered_set<string> st;
            for(auto it = begin(u.second); it != end(u.second); it++){
                for(auto it2 = next(it); it2 != end(u.second); it2++){
                    for(auto it3 = next(it2); it3 != end(u.second); it3++){
                        string t = it->second + "$" + it2->second + "#" + it3->second;
                        st.insert(t);
                        // cout << t << endl;
                    }
                }
            }
            
            for(auto s : st)cnt[s]++;  
        }

        int max_cnt = 0;
        string max_path = "";
        for(auto s : cnt){
            if(s.second > max_cnt){
                max_path = s.first;
                max_cnt = s.second;
            }
            else if(s.second == max_cnt){
                if(s.first < max_path){
                    max_path = s.first;
                    max_cnt = s.second;
                }
            }
        }

        auto f1 = max_path.find("$");
        auto f2 = max_path.find("#");
        // cout << f1 << " " << f2 << endl;
        return {max_path.substr(0, f1), max_path.substr(f1+1, f2-f1-1), max_path.substr(f2+1)};
    }
};