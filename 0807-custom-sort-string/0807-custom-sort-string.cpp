class Solution {
public:
    /*
    Concept: 
        [=] means “capture all local variables used in the lambda by value.”
        [&] means “capture all local variables used in the lambda by reference.”


    Approach 1. 
    use hashtable to count the index of the char + sort in lambda and use &
    !! crucial !!
    sort need to consider any condition in lambda
string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        
        for(int i = 0; i < order.length(); i++){
            mp[order[i]] = i; 
        }

        sort(s.begin(), s.end(), [&](char i, char j){
            
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
                return false;
            }
        
        });

        return s;
    }


    !! follow up !!
    can use string find 
    T: O(NlgN)
    S: O(N) in C++ sorting

    std::string::npos is an unsigned “largest possible size_t” value.
    npos means all bits set to 1 

    string customSortString(string order, string s) {
        // std::string::npos is an unsigned “largest possible size_t” value.
        sort(s.begin(), s.end(), [&](char i, char j){
            return order.find(i) < order.find(j);
        });
        return s;
    }

    Approach 2. 
    use count the frequency in s, and first construct in order

    T: O(N) N means the length of the string
    S: O(N) for the length of the s
    */
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;

        for(auto i : s){
            mp[i]++;
        }
        
        string ans = "";
        for(int i = 0; i < order.length(); i++){
            if(mp.find(order[i]) != mp.end()){
                for(int j = 0; j < mp[order[i]]; j++){
                    ans += order[i];
                }
                mp.erase(order[i]);
            }
                
        }

        for(auto it : mp){
            for(int j = 0; j < it.second; j++){
                ans += it.first;
            }
        }

        return ans;
    }
};