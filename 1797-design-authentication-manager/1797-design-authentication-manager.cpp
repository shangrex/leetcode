/*
method 1. use hash map<string, int>mp
to renew, find exist & check if it is expired
to count, traverse all map member and check if expired

query time: O(N)

method 2. 
to count, remove expired and count size of hash_map
auery time: 
*/
class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int>mp;
    set<pair<int, string>>time_map;
    AuthenticationManager(int timeToLive) : ttl(timeToLive){ }
    
    void clean(int currentTime){
        while(!time_map.empty() && begin(time_map)->first <= currentTime){
            mp.erase(begin(time_map)->second);
            time_map.erase(begin(time_map));
        }
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
        // check to remove
        time_map.insert({currentTime+ttl, tokenId});
    }
    
    void renew(string tokenId, int currentTime) {
        clean(currentTime);
        if(mp.find(tokenId) != mp.end() && mp[tokenId]+ttl > currentTime){
            time_map.erase({mp[tokenId]+ttl, tokenId});
            mp[tokenId] = currentTime;
            time_map.insert({currentTime+ttl, tokenId});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        // method 1
        // int cnt = 0;
        // for(auto i : mp){
        //     if(i.second + ttl > currentTime){
        //         cnt++;
        //     }
        // }
        // return cnt;
        
        
        // ---
        // method 2
        clean(currentTime);
        // cout << mp.size() << " " << time_map.size() << endl;
        return mp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */