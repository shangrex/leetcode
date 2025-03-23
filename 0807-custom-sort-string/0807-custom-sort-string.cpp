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
    T: O(NlgN)
    S: number of char in order


    Approach 2. 
    use 
    */
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
};