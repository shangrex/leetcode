class Solution {
public:
    bool match(vector<int>&s1c, vector<int>&s2c){
        for(int i = 0; i < 26; i++){
            if(s1c[i] > s2c[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> s1c(26), s2c(26);

        for(auto &i : s1){
            s1c[i-'a'] +=1;
        }

        int n = s1.length();
        int leftIdx = 0, rightIdx = 0;
        while(rightIdx < s2.length()){
            s2c[s2[rightIdx]-'a'] += 1;
            while(leftIdx <= rightIdx && match(s1c, s2c)){
                cout << leftIdx << ' ' << rightIdx << endl;
                if(rightIdx - leftIdx == n-1) return true;
                s2c[s2[leftIdx]-'a'] --;
                leftIdx++;
            }
            rightIdx++;
        }
        return false;
    }
};