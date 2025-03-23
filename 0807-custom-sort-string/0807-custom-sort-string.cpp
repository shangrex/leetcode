class Solution {
public:
    /*
    Concept: 
        [=] means “capture all local variables used in the lambda by value.”
        [&] means “capture all local variables used in the lambda by reference.”


    Approach 1. 

    */
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        
        for(int i = 0; i < order.length(); i++){
            mp[order[i]] = i; 
        }

        sort(s.begin(), s.end(), [&](char i, char j){
            
            cout << i << j << endl;
            bool t1 = (mp.find(i) != mp.end());
            bool t2 = (mp.find(j) != mp.end());

            if(t1 && t2){
                return mp[i] < mp[j];
            }
            else if(t1 && !t2){
                return true;
            }
            else if(!t1 && t2){
                return false;
            }
            else {
                return i < j;
            }
        
        });

        return s;
    }
};