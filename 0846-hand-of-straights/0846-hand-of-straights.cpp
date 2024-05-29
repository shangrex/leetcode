class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int>mp;
        for(int i = 0; i < hand.size(); i++){
            mp[hand[i]] += 1;
        }
        /* approach 1
        while(mp.size() >= groupSize){
            auto i = mp.begin();
            for(int j = 0; j < groupSize; j++){
                cout << i->first+j;
                if(mp.find(i->first+j) != mp.end()){
                    mp[i->first+j] -= 1;
                }
                else return false;
            }
            for(int j = groupSize-1; j >= 0; j--){
                if(mp[i->first+j] == 0)mp.erase(i->first+j);
            }
        }
        if(mp.size() > 0)return false;
        */
        
        // approach 2.
        sort(hand.begin(), hand.end());
        for(int i = 0; i < hand.size(); i++){
            if(mp[hand[i]] == 0)continue;
            for(int j = 0; j < groupSize; j++){
                // cout << hand[i]+j << mp[hand[i]+j] << endl;
                if(mp.find(hand[i]+j) != mp.end() && mp[hand[i]+j] > 0){
                    mp[hand[i]+j] -= 1;
                }
                else return false;
            }
        }
        
        return true;
    }
};