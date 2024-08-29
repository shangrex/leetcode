class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>> > mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> p = {timestamp, value};
        mp[key].push_back(p);
        //sort(mp[key].begin(), mp[key].end());
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())return "";
        if(timestamp < mp[key][0].first) return "";
        // using copy constructor here will lead to TLE
        // use copy reference to the new variable can pass
        vector<pair<int, string>>&t = mp[key];
        int left = 0, right = t.size();
        while(left < right){
            int mid = (left+right)/2;
            if(t[mid].first == timestamp){
                return t[mid].second;
            }
            else if(t[mid].first > timestamp){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        if(right == 0)return "";
        return t[left-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */