class Solution {
public:
    
    bool match(vector<int>&s1, vector<int>&s2){
        for(int i = 0; i < 26; i++){
            if(s1[i] != s2[i])return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;
        int left = 0, right = -1;
        
        vector<int>count_s1(26, 0);
        vector<int>count_s2(26, 0);
        for(int i = 0; i < s1.length(); i++){
            count_s1[s1[i]-'a']++;
        }
        int n1 = s1.length();
        
        int n2 = s2.length();   
        
        while(right < n2-1){
            right++;
            count_s2[s2[right]-'a']++;
            while(right-left+1 < n1){
                right++;
                count_s2[s2[right]-'a']++;
            }      
            
            // cout << right << " " << left << endl;
            if(match(count_s1, count_s2))return true;
            
            count_s2[s2[left]-'a']--;
            left++;

        }
        return false;
    }
};