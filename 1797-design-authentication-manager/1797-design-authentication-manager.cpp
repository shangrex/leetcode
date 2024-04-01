class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int>mp;
    AuthenticationManager(int timeToLive) : ttl(timeToLive){   
        
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId) != mp.end() && mp[tokenId]+ttl > currentTime){
            mp[tokenId] = currentTime;        
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto i : mp){
            if(i.second + ttl > currentTime){
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */